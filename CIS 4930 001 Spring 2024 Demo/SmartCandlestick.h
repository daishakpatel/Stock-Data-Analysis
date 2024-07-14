// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#pragma once
#include "Candlestick.h"

using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

/// <summary>
/// SmartCandlestick class which is derived from Candlestick class. 
/// It has additional properties like Range, bodyRange, topPrice, bottomPrice, upperTail, lowerTail and patterns.
/// </summary>
public ref class SmartCandlestick : Candlestick {
public:
	property double Range;								// Range of the candlestick
	property double bodyRange;							// Range of the body of the candlestick
	property double topPrice;							// Top price of the candlestick
	property double bottomPrice;						// Bottom price of the candlestick
	property double upperTail;							// Upper tail of the candlestick
	property double lowerTail;							// Lower tail of the candlestick
	property Dictionary<String^, bool>^ patterns;		// Dictionary of patterns and their boolean values


	// Constructor that takes candlestick object as an input
	SmartCandlestick(Candlestick^ cs) : Candlestick()
	{
		Date = cs->Date;								// Set date of smartcandlestick
		Open = cs->Open;								// Set open of smartcandlestick
		High = cs->High;								// Set high of smartcandlestick
		Low = cs->Low;									// Set low of smartcandlestick
		Close = cs->Close;								// Set close of smartcandlestick	
		Volume = cs->Volume;							// Set volume of smartcandlestick
		patterns = gcnew Dictionary<String^, bool>;	    // Initialize patterns dictionary
		ComputeExtraProperties();						// Compute extra properties of smartcandlestick
	}

	// Constructor that takes a csvline as an input
	SmartCandlestick(String^ csvLine) : Candlestick(csvLine) 
	{
		patterns = gcnew Dictionary<String^, bool>;	    // Initialize patterns dictionary
		ComputeExtraProperties();						// Compute extra properties of smartcandlestick
	}

	// Computes properties (members) of smartcandlestick
	Void ComputeExtraProperties();

 };

