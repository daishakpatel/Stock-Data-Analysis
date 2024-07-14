// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Form_StockPicker.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer.h"
#include "Recognizer_Bullish.h"
#include "Recognizer_Bearish.h"
#include "Recognizer_Neutral.h"
#include "Recognizer_Marubozu.h"
#include "Recognizer_Hammer.h"
#include "Recognizer_Doji.h"
#include "Recognizer_DragonflyDoji.h"
#include "Recognizer_GravestoneDoji.h"
#include "Recognizer_BullishEngulfing.h"
#include "Recognizer_BearishEngulfing.h"
#include "Recognizer_BullishHarami.h"
#include "Recognizer_BearishHarami.h"
#include "Recognizer_Peak.h"
#include "Recognizer_Valley.h"

using namespace CppCLRWinFormsProject;
using namespace System::Windows::Forms::DataVisualization::Charting;

/// <summary>
/// Event handler for the openFileDialog. Creates a dataGridView and a Chart based on data from the selected file.
/// </summary>
/// <param name="sender">The object that triggered the event</param>
/// <param name="e">The event arguments</param>
/// <returns>Void</returns>
Void Form_StockPicker::openFileDialog_stockPicker_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e)
{
	// Clear any existing annotations
	chart_OHLCV->Annotations->Clear();

	// Find filepath, display as text
	array<String^>^ files = openFileDialog_stockPicker->FileNames;
	String^ filePath = files[0];
	Text = "Loading: " + Path::GetFileNameWithoutExtension(filePath);

	// Read data from file and create a list of candlesticks
	listOfSmartCandlesticks = ReadCandleStickDataFromFile(filePath);



	// Recognize all candlestick patterns
	for each (Recognizer ^ recognizer in listOfRecognizers) {
		recognizer->RecognizeAll(listOfSmartCandlesticks);
	}


	// Filter candlesticks within the required date range
	boundListOfSmartCandlesticks = filterCandlesticks(listOfSmartCandlesticks);

	// Normalize chart
	normalizeChart(boundListOfSmartCandlesticks);

	// Bind boundListOfCandlesticks to Chart
	displayChart(boundListOfSmartCandlesticks);

	for (int i = 1; i < files->Length; i++) {

		Form_StockPicker^ formsp = gcnew Form_StockPicker();

		// Clear any existing annotations
		formsp->chart_OHLCV->Annotations->Clear();

		String^ filePath = files[i];
		formsp->Text = "Loading: " + Path::GetFileNameWithoutExtension(filePath);

		// Read data from file and create a list of candlesticks
		formsp->listOfSmartCandlesticks = formsp->ReadCandleStickDataFromFile(filePath);

		// Recognize all candlestick patterns
		for each (Recognizer ^ recognizer in formsp->listOfRecognizers) {
			recognizer->RecognizeAll(formsp->listOfSmartCandlesticks);
		}

		// Filter candlesticks within the required date range
		formsp->boundListOfSmartCandlesticks = formsp->filterCandlesticks(formsp->listOfSmartCandlesticks);

		// Normalize chart
		formsp->normalizeChart(formsp->boundListOfSmartCandlesticks);

		// Bind boundListOfCandlesticks to Chart
		formsp->displayChart(formsp->boundListOfSmartCandlesticks);

		// Show the form
		formsp->Show();
	}
}

/// <summary>
/// Reads data from a file and returns a list of smart candlesticks.
/// </summary>
/// <param name="filePath">The path to the file to be read</param>
/// <returns>A list of smart candlesticks</returns>
Void Form_StockPicker::ReadCandleStickDataFromFile() {
	// Call readCandleStickFromFile by passing in the chosen file
	listOfSmartCandlesticks = ReadCandleStickDataFromFile(openFileDialog_stockPicker->FileName);
}

/// <summary>
/// This reads data from the file.
/// </summary>
/// <param name="filePath">This is the path to the file to be read</param>
/// <returns>This will return a list of candlesticks</returns>
List<SmartCandlestick^>^ Form_StockPicker::ReadCandleStickDataFromFile(String^ filePath)
{
	// Clear the existing list of smart candlesticks
	listOfSmartCandlesticks->Clear();

	if (File::Exists(filePath))
	{
		// Create reader for file
		StreamReader^ reader = gcnew StreamReader(filePath);

		// Skip header line
		String^ line = reader->ReadLine();

		// Loop through each row in the file
		while ((line = reader->ReadLine()) != nullptr)
		{
			// Create a new candlestick object using data from the Excel row
			Candlestick^ candlestick = gcnew Candlestick(line);
			SmartCandlestick^ smartCandlestick = gcnew SmartCandlestick(candlestick);
			// Add candlestick to the listOfCandlesticks
			listOfSmartCandlesticks->Add(smartCandlestick);

		}

		reader->Close();

	}
	else
	{
		// If file does not exist
		Console::Write("Error: File not found\n");

	}

	// Return listOfCandlesticks
	return listOfSmartCandlesticks;
}

/// <summary>
/// Updates the list of candlesticks based on the specified date range.
/// </summary>
/// <param name="sender">The object that triggered the event</param>
/// <param name="e">The event arguments</param>
/// <returns>Void</returns>
Void Form_StockPicker::button_UpdatePicker_Click(System::Object^ sender, System::EventArgs^ e) {
	// Clear any existing annotations
	chart_OHLCV->Annotations->Clear();

	// Filter candlesticks within new data range
	filterCandlesticks();

	// Normalize the chart
	normalizeChart();

	// Bind new boundListOfCandlesticks to Chart
	displayChart();
}

/// <summary>
/// Calls the filterCandlesticks method to filter the list of candlesticks according to the date range specified by the dateTimePickers.
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::filterCandlesticks() {
	// Filter the listOfCandlesticks according to the range specified by the dateTimePickers
	boundListOfSmartCandlesticks = filterCandlesticks(listOfSmartCandlesticks);
}

/// <summary>
/// Normalizes the y-axis for the chart according to the maximum high and minimum low of the candlesticks.
/// </summary>
/// <param name="bloc">The list of candlesticks</param>
/// <returns>Void</returns>
Void Form_StockPicker::normalizeChart(BindingList<SmartCandlestick^>^ blosc) {

	// Check if the list of candlesticks is empty
	if (blosc->Count == 0) { return; }

	// Initialize variables for maximum high and minimum low
	double max_High = blosc[0]->High;
	double min_Low = blosc[0]->Low;

	// Loop through the list of candlesticks to find the maximum high and minimum low
	for (int i = 0; i < blosc->Count; i++) {

		// cs will be Candlestick at current index
		SmartCandlestick^ scs = blosc[i];

		// Update max_High if the high of the current candlestick is greater
		if (scs->High > max_High) { max_High = scs->High; }

		// Update min_Low if the low of the current candlestick is lower
		if (scs->Low < min_Low) { min_Low = scs->Low; }

	}

	// Increase max_High by 2%
	max_High = max_High * 1.02;

	// Increase min_Low by 2%
	min_Low = min_Low * 1.02;

	// Set chart area axis y maximum to max_High
	chart_OHLCV->ChartAreas[0]->AxisY->Maximum = max_High;

	// Set chart area axis y minimum to min_Low
	chart_OHLCV->ChartAreas[0]->AxisY->Minimum = min_Low;
}

/// <summary>
/// Filters the list of candlesticks according to the date range specified by the dateTimePickers.
/// </summary>
/// <param name="loc">The list of candlesticks to be filtered</param>
/// <returns>A BindingList of candlesticks filtered by the required date range</returns>
BindingList<SmartCandlestick^>^ Form_StockPicker::filterCandlesticks(List<SmartCandlestick^>^ losc)
{
	// Create a new list to store selected candlesticks
	List<SmartCandlestick^>^ selectedSmartCandlesticks = gcnew List<SmartCandlestick^>(losc->Count);

	// Loop through all candlesticks and select the ones within the required date range
	for (int i = 0; i < losc->Count; i++)
	{
		SmartCandlestick^ scs = losc[i];
		// Break if the candlestick is beyond the end date
		if (dateTimePicker_End->Value < scs->Date) {
			break;
		}

		// Check if the candlestick is within the required date range
		if (dateTimePicker_Start->Value <= scs->Date && scs->Date <= dateTimePicker_End->Value) {
			selectedSmartCandlesticks->Add(scs);
		}
	}

	// Create a BindingList from the selected candlesticks and return it
	BindingList<SmartCandlestick^>^ resultingBindingList = gcnew BindingList<SmartCandlestick^>(selectedSmartCandlesticks);
	return resultingBindingList;

}

/// <summary>
/// Calls the normalizeChart method to normalize the y-axis for the chart.
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::normalizeChart() {
	// Normalize y-axis for the chart
	normalizeChart(boundListOfSmartCandlesticks);
}

/// <summary>
/// Displays a chart using the provided list of candlesticks.
/// </summary>
/// <param name="bloc">The list of candlesticks</param>
/// <returns>Void</returns>
Void Form_StockPicker::displayChart(BindingList<SmartCandlestick^>^ blosc) {

	// Set the data source for the chart
	chart_OHLCV->DataSource = blosc;
	chart_OHLCV->DataBind();

}

/// <summary>
/// Event handler for the comboBox. Adds arrow annotations to the chart based on the selected pattern.
/// </summary>
/// <param name="sender">The object that triggered the event</param>
/// <param name="e">The event arguments</param>
/// <returns>Void</returns>
Void Form_StockPicker::comboBox_Patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	// Clear existing annotations on the chart
	chart_OHLCV->Annotations->Clear();

	// Get the selected pattern from the comboBox
	String^ selectedPattern = comboBox_Patterns->SelectedItem->ToString();

	// Iterate through the candlesticks in the boundListOfSmartCandlesticks
	if (boundListOfSmartCandlesticks == nullptr) { return; }
	for (int i = 0; i < boundListOfSmartCandlesticks->Count; i++) {
		SmartCandlestick^ scs = boundListOfSmartCandlesticks[i];


		// Check if the selected pattern is true for the current candlestick
		if (scs->patterns[selectedPattern]) {
			// Create a new RectangleAnnotation object
			RectangleAnnotation^ rectangle = gcnew RectangleAnnotation();

			// Set the anchor point to the candlestick data point
			rectangle->AnchorDataPoint = chart_OHLCV->Series["Series_OHLC"]->Points[i];
			rectangle->IsSizeAlwaysRelative = false;

			// Set the rectangle properties
			rectangle->BackColor = Drawing::Color::Transparent;
			rectangle->LineWidth = 1;
			rectangle->LineColor = Drawing::Color::Black;

			// Calculate the height, width, and position based on the selected pattern
			int numCandlesticks = 0;
			for each (Recognizer ^ lr in listOfRecognizers)
			{
				if (lr->patternName == selectedPattern)
				{
					numCandlesticks = lr->patternLength;
				}
			}
			// Check if the number of candlesticks is 1
			if (numCandlesticks == 1) {
				rectangle->Width = 1;				// Set the width of the rectangle to 1
				rectangle->Height = (scs->Range);				// Set the height of the rectangle to the range of the candlestick
				rectangle->X = i + 0.5;				// Set the X position of the rectangle to the index plus 0.5
				// Set the Y position of the rectangle to the low of the candlestick
				rectangle->Y = scs->Low;
			}
			// Check if the number of candlesticks is 2
			else if (numCandlesticks == 2) {
				// If it's the last candlestick, exit the loop
				if (i == boundListOfSmartCandlesticks->Count - 1) { break; }
				// Get the next candlestick
				SmartCandlestick^ scsNext = boundListOfSmartCandlesticks[i + 1];
				// Set the width of the rectangle to 2
				rectangle->Width = 2;
				// Set the height of the rectangle to the difference between the highs and lows of the current and next candlesticks
				rectangle->Height = Math::Max(scs->High, scsNext->High) - Math::Min(scs->Low, scsNext->Low);
				// Set the X position of the rectangle to the index plus 0.5
				rectangle->X = i + 0.5;
				// Set the Y position of the rectangle to the minimum of the lows of the current and next candlesticks
				rectangle->Y = Math::Min(scs->Low, scsNext->Low);
			}
			// Check if the number of candlesticks is 3
			else if (numCandlesticks == 3) {
				// If it's the first or last candlestick, exit the loop
				if (i == 0 || i == boundListOfSmartCandlesticks->Count - 1) { break; }
				// Get the next and previous candlesticks
				SmartCandlestick^ scsNext = boundListOfSmartCandlesticks[i + 1];
				// Set the width of the rectangle to 3
				SmartCandlestick^ scsPrev = boundListOfSmartCandlesticks[i - 1];
				rectangle->Width = 3;
				// Set the X position of the rectangle to the index minus 0.5
				rectangle->X = i - 0.5;
				// Calculate the low and high values considering the current, next, and previous candlesticks
				double low = Math::Min(scs->Low, scsNext->Low);
				low = Math::Min(low, scsPrev->Low);
				double high = Math::Max(scs->High, scsNext->High);
				// Set the height of the rectangle to the difference between high and low
				high = Math::Max(high, scsPrev->High);
				rectangle->Height = high - low;
				// Set the Y position of the rectangle to the calculated low value
				rectangle->Y = low;
			}
			// Add the annotation to the chart
			chart_OHLCV->Annotations->Add(rectangle);
		}
	}
}

/// <summary>
/// Calls displayChart which displays a chart using the boundListOfCandlesticks
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::displayChart() {
	// Display the chart using data from the boundListOfCandlesticks
	displayChart(boundListOfSmartCandlesticks);
}


/// <summary>
/// Initializes the comboBox with the patterns found in the boundListOfSmartCandlesticks.
/// </summary>
/// <param name="blosc">The list of candlesticks</param>
/// <returns>Void</returns>
Void Form_StockPicker::initializeComboBox(BindingList<SmartCandlestick^>^ blosc) {
	
	// Empty blosc
	if (blosc->Count == 0) { return; }

	// Create a new SmartCandlestick object for the first candlestick in the list
	SmartCandlestick^ scs = blosc[0];

	// Clear the comboBox
	comboBox_Patterns->Items->Clear();

    // Check if the selectedCandlestick is not null and has patterns
	if (scs != nullptr && scs->patterns != nullptr)
	{
		// Get the patterns dictionary from the selectedCandlestick
		Dictionary<String^, bool>^ patterns = scs->patterns;

		// Add keys from the patterns dictionary to the combo box
		for each (String ^key in patterns->Keys)
		{
			comboBox_Patterns->Items->Add(key);  // Add the key to the comboBox
		}
	}
}


/// <summary>
/// Initlializes the member variable listOfRecognizers with the Recognizers
/// </summary>
/// <returns>Void</returns>
Void Form_StockPicker::initializeRecognizers() {
	// Initialize the list of recognizers
	listOfRecognizers = gcnew List<Recognizer^>();

	// Add each recognizer to the list
	listOfRecognizers->Add(gcnew Recognizer_Bullish());
	listOfRecognizers->Add(gcnew Recognizer_Bearish());
	listOfRecognizers->Add(gcnew Recognizer_Neutral());
	listOfRecognizers->Add(gcnew Recognizer_Marubozu());
	listOfRecognizers->Add(gcnew Recognizer_Hammer());
	listOfRecognizers->Add(gcnew Recognizer_Doji());
	listOfRecognizers->Add(gcnew Recognizer_DragonflyDoji());
	listOfRecognizers->Add(gcnew Recognizer_GravestoneDoji());
	listOfRecognizers->Add(gcnew Recognizer_BullishEngulfing());
	listOfRecognizers->Add(gcnew Recognizer_BearishEngulfing());
	listOfRecognizers->Add(gcnew Recognizer_BullishHarami());
	listOfRecognizers->Add(gcnew Recognizer_BearishHarami());
	listOfRecognizers->Add(gcnew Recognizer_Peak());
	listOfRecognizers->Add(gcnew Recognizer_Valley());
	
	// Fill the comboBox with pattern names
	for each (Recognizer^ recognizer in listOfRecognizers) {
		comboBox_Patterns->Items->Add(recognizer->patternName);
	}
}