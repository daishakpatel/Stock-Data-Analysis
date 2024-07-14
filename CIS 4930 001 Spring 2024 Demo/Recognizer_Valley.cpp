#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_Valley.h"
#include "Recognizer.h"


/// <summary>
/// Recognizes whether the candlestick at the index, the one after it, and the one after that is a valley pattern
/// Updates the patterns dictionary in the candlestick
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlesticks follow a valley pattern</returns>
bool Recognizer_Valley::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	double prevLow = lscs[index - 1]->bottomPrice;
	double currLow = lscs[index]->bottomPrice;
	double nextLow = lscs[index + 1]->bottomPrice;

	bool result = (prevLow > currLow) && (currLow < nextLow);

	return result;
}