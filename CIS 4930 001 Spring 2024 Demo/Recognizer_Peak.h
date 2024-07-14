#pragma once
#include "Recognizer.h"
using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;

/// <summary>
/// Derived class for recognizing all peak patterns
/// </summary>
public ref class Recognizer_Peak : Recognizer
{
public:

	// Constructor
	Recognizer_Peak() : Recognizer("Peak", 3) {}

	// Recognize a Peak
	bool Recognize(List<SmartCandlestick^>^ lscs, int index) override;

};