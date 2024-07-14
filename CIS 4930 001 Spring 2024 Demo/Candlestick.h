// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314


#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

/// <summary>
/// Represents a candlestick in stock data, containing information about Date, Open, High, Low, Close, and Volume.
/// </summary>
public ref class Candlestick
{
public:
	property DateTime Date;				// Date for the stock candlestick
	property double Open;				// Open price for the stock
	property double High;				// High price of the stock
	property double Low;				// Low price of the stock
	property double Close;				// Close price of the stock
	property unsigned long long Volume; // Volume of stock that was traded

	// Default constructor
	Candlestick() {};

	// Constructor that takes a a CSV lines as input
	Candlestick(String^ csvLine); 

};


