// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "SmartCandlestick.h"
#include "Recognizer.h"

/// <summary>
/// Recognizes all candlesticks in the, based on the recognizer that calls this method
/// </summary>
/// <param name="lscs">The list of smart candlesticks</param>
/// <returns>Void</returns>
Void Recognizer::RecognizeAll(List<SmartCandlestick^>^ lscs)
{
	// Return if the list is empty
	if (lscs->Count == 0) { return; }

	// Initialize the patterns dictionary
	int numCandlesticks = this->patternLength;
	for (int i = 0; i < lscs->Count; i++) {
		// If it's the last candlestick and the pattern length is 2, mark it as false (for 2-candlestick patterns)
		if (numCandlesticks == 2 && i == lscs->Count - 1) {
			lscs[i]->patterns->Add(patternName, false);
			continue;
		}
		// If it's the first or last candlestick and the pattern length is 3 (for 3-candlestick patterns)
		if (numCandlesticks == 3 && ((i == 0) || (i == lscs->Count - 1))) {
			lscs[i]->patterns->Add(patternName, false);
			continue;
		}
		lscs[i]->patterns->Add(patternName, this->Recognize(lscs, i));
	}

	// Return
	return;
}


