#pragma once
#include "Recognizer.h"
using namespace System;
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Collections::Generic;


/// <summary>
/// Derived class for recognizing all valley patterns
/// </summary>
public ref class Recognizer_Valley : Recognizer
{
public:

	// Constructor
	Recognizer_Valley() : Recognizer("Valley", 3) {}

	// Recognize a Valley
	bool Recognize(List<SmartCandlestick^>^ lscs, int index) override;

};