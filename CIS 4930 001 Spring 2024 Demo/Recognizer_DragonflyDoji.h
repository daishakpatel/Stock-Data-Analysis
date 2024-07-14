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
/// Derived class for recognizing dragonfly doji candlesticks
/// </summary>
public ref class Recognizer_DragonflyDoji : Recognizer
{
public:

	// Constructor
	Recognizer_DragonflyDoji() : Recognizer("Dragonfly Doji", 1) {}

	// Recognize a DragonflyDoji candlestick
	bool Recognize(List<SmartCandlestick^>^ lscs, int index) override;

};
