// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#pragma once
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_StockPicker
	/// </summary>
	public ref class Form_StockPicker : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_Start;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker_End;
	private: System::Windows::Forms::Label^ label_Start;
	private: System::Windows::Forms::Label^ label_End;
	private: System::Windows::Forms::Label^ label_ComboBox;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart_OHLCV;
	private: System::Windows::Forms::Button^ button_UpdatePicker;

	// Member variables
	private:List<Candlestick^>^ listOfCandlesticks;
	private:List<SmartCandlestick^>^ listOfSmartCandlesticks;
	private:BindingList<Candlestick^>^ boundListOfCandlesticks;
	private: List<Recognizer^>^ listOfRecognizers;
	private: System::Windows::Forms::ComboBox^ comboBox_Patterns;
	private: System::Windows::Forms::Label^ label1;
	private: BindingList<SmartCandlestick^>^ boundListOfSmartCandlesticks;

	public:
		Form_StockPicker(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			listOfCandlesticks = gcnew List<Candlestick^>(1024);
			listOfSmartCandlesticks = gcnew List<SmartCandlestick^>(1024);
			initializeRecognizers();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_StockPicker()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_StockPicker;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog_stockPicker;



	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->button_StockPicker = (gcnew System::Windows::Forms::Button());
			this->openFileDialog_stockPicker = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dateTimePicker_Start = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker_End = (gcnew System::Windows::Forms::DateTimePicker());
			this->label_Start = (gcnew System::Windows::Forms::Label());
			this->label_End = (gcnew System::Windows::Forms::Label());
			this->chart_OHLCV = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->button_UpdatePicker = (gcnew System::Windows::Forms::Button());
			this->comboBox_Patterns = (gcnew System::Windows::Forms::ComboBox());
			this->label_ComboBox = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->BeginInit();
			this->SuspendLayout();
			// 
			// button_StockPicker
			// 
			this->button_StockPicker->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_StockPicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_StockPicker->Location = System::Drawing::Point(463, 122);
			this->button_StockPicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_StockPicker->Name = L"button_StockPicker";
			this->button_StockPicker->Size = System::Drawing::Size(138, 66);
			this->button_StockPicker->TabIndex = 0;
			this->button_StockPicker->Text = L"Load Stock";
			this->button_StockPicker->UseVisualStyleBackColor = false;
			this->button_StockPicker->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_StockPicker_Click);
			// 
			// openFileDialog_stockPicker
			// 
			this->openFileDialog_stockPicker->FileName = L"*.csv";
			this->openFileDialog_stockPicker->Filter = L"All Files|*.CSV|Monthly|*-Month.CSV|Weekly|*-Week.CSV|Daily|*-Day.CSV";
			this->openFileDialog_stockPicker->Multiselect = true;
			this->openFileDialog_stockPicker->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form_StockPicker::openFileDialog_stockPicker_FileOk);
			// 
			// dateTimePicker_Start
			// 
			this->dateTimePicker_Start->Location = System::Drawing::Point(153, 124);
			this->dateTimePicker_Start->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePicker_Start->Name = L"dateTimePicker_Start";
			this->dateTimePicker_Start->Size = System::Drawing::Size(287, 22);
			this->dateTimePicker_Start->TabIndex = 2;
			this->dateTimePicker_Start->Value = System::DateTime(2022, 1, 1, 0, 0, 0, 0);
			// 
			// dateTimePicker_End
			// 
			this->dateTimePicker_End->Location = System::Drawing::Point(153, 166);
			this->dateTimePicker_End->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dateTimePicker_End->Name = L"dateTimePicker_End";
			this->dateTimePicker_End->Size = System::Drawing::Size(287, 22);
			this->dateTimePicker_End->TabIndex = 3;
			this->dateTimePicker_End->Value = System::DateTime(2024, 4, 19, 23, 23, 19, 0);
			// 
			// label_Start
			// 
			this->label_Start->AutoSize = true;
			this->label_Start->BackColor = System::Drawing::SystemColors::Control;
			this->label_Start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Start->Location = System::Drawing::Point(35, 122);
			this->label_Start->Name = L"label_Start";
			this->label_Start->Size = System::Drawing::Size(102, 20);
			this->label_Start->TabIndex = 4;
			this->label_Start->Text = L"Start Date:";
			// 
			// label_End
			// 
			this->label_End->AutoSize = true;
			this->label_End->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_End->Location = System::Drawing::Point(35, 168);
			this->label_End->Name = L"label_End";
			this->label_End->Size = System::Drawing::Size(93, 20);
			this->label_End->TabIndex = 6;
			this->label_End->Text = L"End Date:";
			// 
			// chart_OHLCV
			// 
			chartArea1->AxisX->LabelStyle->Enabled = false;
			chartArea1->AxisX->LabelStyle->IsEndLabelVisible = false;
			chartArea1->AxisX->TextOrientation = System::Windows::Forms::DataVisualization::Charting::TextOrientation::Stacked;
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->AxisY2->IsStartedFromZero = false;
			chartArea1->Name = L"ChartArea_OHLC";
			chartArea2->AlignWithChartArea = L"ChartArea_OHLC";
			chartArea2->Name = L"ChartArea_Volume";
			this->chart_OHLCV->ChartAreas->Add(chartArea1);
			this->chart_OHLCV->ChartAreas->Add(chartArea2);
			legend1->Enabled = false;
			legend1->Name = L"Legend1";
			this->chart_OHLCV->Legends->Add(legend1);
			this->chart_OHLCV->Location = System::Drawing::Point(28, 237);
			this->chart_OHLCV->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart_OHLCV->Name = L"chart_OHLCV";
			series1->ChartArea = L"ChartArea_OHLC";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Candlestick;
			series1->CustomProperties = L"PriceDownColor=Red, PriceUpColor=Green";
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Series_OHLC";
			series1->XValueMember = L"Date";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series1->YValueMembers = L"High,Low,Open,Close";
			series1->YValuesPerPoint = 4;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Double;
			series2->ChartArea = L"ChartArea_Volume";
			series2->IsXValueIndexed = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Series_Volume";
			series2->XValueMember = L"Date";
			series2->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::DateTime;
			series2->YValueMembers = L"Volume";
			series2->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chart_OHLCV->Series->Add(series1);
			this->chart_OHLCV->Series->Add(series2);
			this->chart_OHLCV->Size = System::Drawing::Size(1128, 549);
			this->chart_OHLCV->TabIndex = 7;
			this->chart_OHLCV->Text = L"chart_OHLCV";
			// 
			// button_UpdatePicker
			// 
			this->button_UpdatePicker->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button_UpdatePicker->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_UpdatePicker->Location = System::Drawing::Point(617, 123);
			this->button_UpdatePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_UpdatePicker->Name = L"button_UpdatePicker";
			this->button_UpdatePicker->Size = System::Drawing::Size(155, 64);
			this->button_UpdatePicker->TabIndex = 8;
			this->button_UpdatePicker->Text = L"Update";
			this->button_UpdatePicker->UseVisualStyleBackColor = false;
			this->button_UpdatePicker->Click += gcnew System::EventHandler(this, &Form_StockPicker::button_UpdatePicker_Click);
			// 
			// comboBox_Patterns
			// 
			this->comboBox_Patterns->FormattingEnabled = true;
			this->comboBox_Patterns->Location = System::Drawing::Point(885, 146);
			this->comboBox_Patterns->Margin = System::Windows::Forms::Padding(4);
			this->comboBox_Patterns->Name = L"comboBox_Patterns";
			this->comboBox_Patterns->Size = System::Drawing::Size(179, 24);
			this->comboBox_Patterns->TabIndex = 9;
			this->comboBox_Patterns->SelectedIndexChanged += gcnew System::EventHandler(this, &Form_StockPicker::comboBox_Patterns_SelectedIndexChanged);
			// 
			// label_ComboBox
			// 
			this->label_ComboBox->AutoSize = true;
			this->label_ComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_ComboBox->Location = System::Drawing::Point(791, 146);
			this->label_ComboBox->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_ComboBox->Name = L"label_ComboBox";
			this->label_ComboBox->Size = System::Drawing::Size(76, 20);
			this->label_ComboBox->TabIndex = 10;
			this->label_ComboBox->Text = L"Pattern:";
			this->label_ComboBox->Click += gcnew System::EventHandler(this, &Form_StockPicker::label_ComboBox_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(474, 46);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(285, 32);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Stock Data Analysis";
			// 
			// Form_StockPicker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1263, 861);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_ComboBox);
			this->Controls->Add(this->comboBox_Patterns);
			this->Controls->Add(this->button_UpdatePicker);
			this->Controls->Add(this->chart_OHLCV);
			this->Controls->Add(this->label_End);
			this->Controls->Add(this->label_Start);
			this->Controls->Add(this->dateTimePicker_End);
			this->Controls->Add(this->dateTimePicker_Start);
			this->Controls->Add(this->button_StockPicker);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Form_StockPicker";
			this->Text = L"Form_StockPicker";
			this->Load += gcnew System::EventHandler(this, &Form_StockPicker::Form_StockPicker_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart_OHLCV))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region
	/// <summary>
	/// Loads the form
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns>Void</returns>
	private: System::Void Form_StockPicker_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	// Methods and event handlers
	
	/// <summary>
	/// Opens a fileDialog
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns>Void</returns>
	private: System::Void button_StockPicker_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Open file explorer
		openFileDialog_stockPicker->ShowDialog();
	}

	/// <summary>
	/// Creates a dataGridView and a Chart based using data on the file selected in the openFileDialog
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns>Void</returns>
	private: System::Void openFileDialog_stockPicker_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e);
	
	/// <summary>
	/// Updates the boundListOfCandlesticks based on the newly specified date range
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns>Void</returns>
	private: System::Void button_UpdatePicker_Click(System::Object^ sender, System::EventArgs^ e);

	/// <summary>
	/// This reads data from the file.
	/// </summary>
	/// <param name="filePath">This is the path to the file to be read</param>
	/// <returns>This will return a list of candlesticks</returns>
	public: List<SmartCandlestick^>^ ReadCandleStickDataFromFile(String^ filePath);

	/// <summary>
	/// Calls ReadCandleStickDataFromFile by passing in the filepath from the openFileDialog
	/// </summary>
	/// <returns>Void</returns>
	public: Void ReadCandleStickDataFromFile();	

	/// <summary>
	/// Filters a listOfCandlesticks according to the date range specified by the dateTimePickers
	/// </summary>
	/// <param name="loc">listOfCandlesticks that has to be filtered</param>
	/// <returnsA boundListOfCandlesticks></returns>
	public: BindingList<SmartCandlestick^>^ filterCandlesticks(List<SmartCandlestick^>^ losc);

	/// <summary>
	/// Calls filterCandlesticks which filters a listOfCandlesticks according to the date range specified by the dateTimePickers
	/// </summary>
	/// <returns>Void</returns>
	public: Void filterCandlesticks();
	
	/// <summary>
	/// Normalizes the y-axis for chartArea_OHLC according to the maximum high and minimum low of the candlesticks
	/// </summary>
	/// <param name="bloc"></param>
	/// <returns>Void</returns>
	public: Void normalizeChart(BindingList<SmartCandlestick^>^ blosc);

	/// <summary>
	/// Calls normalizeChart which normalizes the y-axis for chartArea_OHLC according to the maximum high and minimum low of the candlesticks
	/// </summary>
	/// <returns>Void</returns>
	public: Void normalizeChart();


	/// <summary>
	/// Displays a chart using the boundListOfCandlesticks. The chart shows the candlesticks along with their volume
	/// </summary>
	/// <param name="bloc"></param>
	/// <returns>Void</returns>
	public: Void displayChart(BindingList<SmartCandlestick^>^ blosc);

	/// <summary>
	/// Calls displayChart which displays a chart using the boundListOfCandlesticks
	/// </summary>
	/// <returns>Void</returns>
	public: Void displayChart();

	/// <summary>
	/// Initializes the comboBox with the patterns found in the boundListOfCandlesticks
	/// </summary>
	/// <param name="blosc"></param>
	/// <returns>Void</returns>
	public: Void initializeComboBox(BindingList<SmartCandlestick^>^ blosc);


	/// <summary>
	/// Event handler for the comboBox.
	/// Adds arrow annotations to the chart according to the pattern selected in the comboBox
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	/// <returns>Void</returns>
	public: Void comboBox_Patterns_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e);
	
	/// <summary>
	/// Initlializes the member variable listOfRecognizers with the Recognizers
	/// </summary>
	/// <returns>Void</returns>
	public: Void initializeRecognizers();

#pragma endregion
private: System::Void label_ComboBox_Click(System::Object^ sender, System::EventArgs^ e) {
}
};


}
