#pragma once
#include "Recognizer.h"
using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

/// <summary>
/// Derived class for recognizing neutral candlesticks
/// </summary>
public ref class Recognizer_Neutral : Recognizer
{
public:

	// Constructor
	Recognizer_Neutral() : Recognizer("Neutral", 1) {}

	// Recognize a neutral candlestick
	bool Recognize(List<SmartCandlestick^>^ lscs, int index) override;

};
