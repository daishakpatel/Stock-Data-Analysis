// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_DragonflyDoji.h"
#include "Recognizer.h"

/// <summary>
/// Recognizes whether the candlestick at the index is Dragonfly Doji
/// Updates the patterns dictionary in the candlestick
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlestick is Dragonfly Doji</returns>
bool Recognizer_DragonflyDoji::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	return (lscs[index]->bodyRange < 0.1 * lscs[index]->Range) && (lscs[index]->upperTail < 0.02 * lscs[index]->Range);
}
