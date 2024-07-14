// Stock Data Analysis Project
// CIS 4930 Project 3
// Name: Daishak Patel
// U-Number: U84709314

#include "pch.h"
#include "SmartCandlestick.h"
#include "Candlestick.h"


/// <summary>
/// Calculate the extra properties of the candlestick using the OHLC data
/// </summary>
/// <returns>Void</returns>
Void SmartCandlestick::ComputeExtraProperties()
{
	Range = High - Low;						// Calculate the range of the candlestick
	topPrice = Math::Max(Open, Close);		// Calculate the top price of the candlestick
	bottomPrice = Math::Min(Open, Close);	// Calculate the bottom price of the candlestick
	bodyRange = topPrice - bottomPrice;		// Calculate the body range of the candlestick
	upperTail = High - topPrice;			// Calculate the upper tail of the candlestick
	lowerTail = bottomPrice - Low;			// Calculate the lower tail of the candlestick
}