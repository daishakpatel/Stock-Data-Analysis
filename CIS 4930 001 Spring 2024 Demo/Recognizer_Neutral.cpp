#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_Neutral.h"
#include "Recognizer.h"


/// <summary>
/// Recognizes whether the candlestick at the index is Neutral
/// Updates the patterns dictionary in the candlestick
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlestick is neutral</returns>
bool Recognizer_Neutral::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	return (lscs[index]->bodyRange >= 0.01 * lscs[index]->Range) && (lscs[index]->bodyRange <= 0.1 * lscs[index]->Range);

}