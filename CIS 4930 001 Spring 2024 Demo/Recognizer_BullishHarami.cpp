// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_BullishHarami.h"
#include "Recognizer.h"

/// <summary>
/// Recognizes whether the candlestick at the index and the one after it is a bullish harami pattern
/// Updates the patterns dictionary in the candlestick
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlesticks follow a bullish harami pattern</returns>
bool Recognizer_BullishHarami::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	bool firstBearish = lscs[index]->patterns["Bearish"];
	bool secondBullish = lscs[index + 1]->patterns["Bullish"];
	double firstBottom = lscs[index]->bottomPrice;
	double firstTop = lscs[index]->topPrice;
	double secondBottom = lscs[index + 1]->bottomPrice;
	double secondTop = lscs[index + 1]->topPrice;

	return firstBearish && secondBullish && (firstBottom < secondBottom) && (firstTop > secondTop);
}