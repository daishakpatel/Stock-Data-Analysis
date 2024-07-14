#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_Peak.h"
#include "Recognizer.h"

/// <summary>
/// Recognizes whether the candlestick at the index, the one after it, and the one after that is a peak pattern
/// Updates the patterns dictionary in the candlestick
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlesticks follow a peak pattern</returns>
bool Recognizer_Peak::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	double prevHigh = lscs[index - 1]->topPrice;
	double currHigh = lscs[index]->topPrice;
	double nextHigh = lscs[index + 1]->topPrice;

	bool result = (prevHigh < currHigh) && (currHigh > nextHigh);

	return result;
}