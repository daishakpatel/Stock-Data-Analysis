// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#pragma once

/// <summary>
/// Abstract base class for all recognizers
/// </summary>
public ref class Recognizer abstract
{
public:
	// Properties
	property String^ patternName;
	property int patternLength;

	// Abstract Recognize method
	virtual bool Recognize(List<SmartCandlestick^>^ lscs, int index) = 0;

	// Constructor
	Recognizer(String^ pN, int pL)
	{
		patternName = pN;
		patternLength = pL;
	}

	// Recognize all patterns for a list of smart candlesticks
	Void RecognizeAll(List<SmartCandlestick^>^ lscs);

	
};


