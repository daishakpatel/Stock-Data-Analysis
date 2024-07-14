// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "Candlestick.h"
#include "SmartCandlestick.h"
#include "Recognizer_Bearish.h"
#include "Recognizer.h"

/// <summary>
/// Determines if the candlestick at the specified index indicates a bearish trend and updates the candlestick's patterns dictionary accordingly.
/// </summary>
/// <param name="lscs"> The list of smart candlesticks</param>
/// <param name="index"> The index in the list where the candlestick is located</param>
/// <returns>bool: Whether the candlestick is bearish</returns>
bool Recognizer_Bearish::Recognize(List<SmartCandlestick^>^ lscs, int index)
{
	return lscs[index]->Close < lscs[index]->Open;

}