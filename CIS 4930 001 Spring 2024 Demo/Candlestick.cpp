// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Candlestick.h"
#include <math.h>

/// <summary>
/// Constructor: Parses a line of CSV data and creates a Candlestick object.
/// </summary>
/// <param name="csvLine">A single line of data from the CSV file</param>
/// <returns>A Candlestick Object</returns>
Candlestick::Candlestick(String^ csvLine)
{
	// Define the date format
	String^ dateFormat = "yyyy-MM-dd";

	// Define the separators
	array<wchar_t>^ separators = { L',',L'"' };

	// Split the CSV line into an array of tokens using defined separators
	array<String^>^ tokens = csvLine->Split(separators, StringSplitOptions::RemoveEmptyEntries);

	// Parse each line and save the data to the correct Candlestick member attribute
	if (tokens->Length >= 7)
	{
		Date = DateTime::ParseExact(tokens[0], dateFormat, CultureInfo::InvariantCulture); // Parse date
		Open = Double::Parse(tokens[1], CultureInfo::InvariantCulture); // Parse stock open price
		High = Double::Parse(tokens[2], CultureInfo::InvariantCulture); // Parse stock high price
		Low = Double::Parse(tokens[3], CultureInfo::InvariantCulture); // Parse stock low price
		Close = Double::Parse(tokens[4], CultureInfo::InvariantCulture); // Parse stock close price
		Volume = Int64::Parse(tokens[6]); // Parse volume of the stock traded
	}
}