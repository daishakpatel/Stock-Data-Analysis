// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_BearishEngulfing.h"
#include "Recognizer.h"

/// <summary>
/// Determines if the candlestick at the specified index and the subsequent one form a bearish engulfing pattern and updates the candlestick's patterns dictionary accordingly.
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlesticks follow a bearish engulfing pattern</returns>
bool Recognizer_BearishEngulfing::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	bool firstBullish = lscs[index]->patterns["Bullish"];
	bool secondBearish = lscs[index + 1]->patterns["Bearish"];
	double firstBottom = lscs[index]->bottomPrice;
	double firstTop = lscs[index]->topPrice;
	double secondBottom = lscs[index + 1]->bottomPrice;
	double secondTop = lscs[index + 1]->topPrice;

	return firstBullish && secondBearish && (firstBottom > secondBottom) && (firstTop < secondTop);
}
