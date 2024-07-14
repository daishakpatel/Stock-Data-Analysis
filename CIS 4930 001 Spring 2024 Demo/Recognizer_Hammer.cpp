// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_Hammer.h"
#include "Recognizer.h"


/// <summary>
/// Recognizes whether the candlestick at the index is Hammer
/// Updates the patterns dictionary in the candlestick
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlestick is Hammer</returns>
bool Recognizer_Hammer::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	return (lscs[index]->upperTail < 0.1 * lscs[index]->Range) && (lscs[index]->bodyRange >= 0.15 * lscs[index]->Range) && (lscs[index]->bodyRange <= 0.35 * lscs[index]->Range);

}
