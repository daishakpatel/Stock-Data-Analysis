// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#pragma once
#include "Recognizer.h"
using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;


/// <summary>
/// Subclass specialized in identifying bearish engulfing candlestick patterns
/// </summary>
public ref class Recognizer_BearishEngulfing : Recognizer
{
public:

	// Constructor
	Recognizer_BearishEngulfing() : Recognizer("Bearish Engulfing", 2) {}

	// Recognize a BearishEngulfing candlestick
	bool Recognize(List<SmartCandlestick^>^ lscs, int index) override;

};

