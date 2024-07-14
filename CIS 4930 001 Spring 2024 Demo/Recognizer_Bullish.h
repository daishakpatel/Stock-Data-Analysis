#pragma once
#include "Recognizer.h"
using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

/// <summary>
/// Derived class for recognizing bullish candlesticks
/// </summary>
public ref class Recognizer_Bullish : Recognizer
{
public:

	// Constructor
	Recognizer_Bullish() : Recognizer("Bullish", 1) {}

	// Recognize a bullish candlestick
	bool Recognize(List<SmartCandlestick^>^ lscs, int index) override;

};

