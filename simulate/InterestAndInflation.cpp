#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/simulate.h"

/// \fn InterestRateShockImpact
/// \brief Determine impact of a shock to interest rates. 

/// \Detail When there is an increase in interest rates, we see an increase in the domestic exchange rate since their is more demand for the domestic currency due to superior investment returns in that country. Thus an increase in interest rates will result in a currency appreciation and a decrease in interest rates will result in a currency depreciation. The function takes as inputs the country and the interest rate change, and outputs the effect on the exchange rate while calling the ExchangeRateShockImpact function. 

void InterestRateShockImpact(  country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta) {
	double ExchRChange = change;	
	if (change > 0) {
		std::cout << "Simulateneous appreciation of " << (*domesticcountry).name << "'s exchange rate with:" << std::endl;
		std::cout << "	" << (*foreigncountry1).name << std::endl;
		std::cout << "	" << (*foreigncountry2).name << std::endl;
		ExchangeRateShockImpact(domesticcountry, foreigncountry1, choice, choicea, ExchRChange, nafta);
		ExchangeRateShockImpact(domesticcountry, foreigncountry2, choice, choiceb, ExchRChange, nafta);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";	
	}
	if (change < 0) {
		std::cout << "Simulateneous depreciation of " << (*domesticcountry).name << "'s exchange rate with:" << std::endl;
		std::cout << "	" << (*foreigncountry1).name << std::endl;
		std::cout << "	" << (*foreigncountry2).name << std::endl;
		ExchangeRateShockImpact(domesticcountry, foreigncountry1, choice, choicea, ExchRChange, nafta);
		ExchangeRateShockImpact(domesticcountry, foreigncountry2, choice, choiceb, ExchRChange, nafta);
	}
}

/// \fn InflationRateShockImpact
/// \brief Determine the impact of a shock of the inflation rate.


/// \Detail When there is an increase in inflation, it results in an increase in the domestic interest rate since banks run a higher risk when they lend money. When there is a decrease in inflation we see a decrease in interest rates. The function takes an inputs the country and the inflation rate change, and outputs the effect on interest rates while calling the InterestRateShockImpact function.

void InflationRateShockImpact(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta) {
	double IntRChange = change;
	if (change > 0) {
		std::cout << "Increase in interest rates." << std::endl;
		InterestRateShockImpact(mycountry, foreigncountry1, foreigncountry2, choice, choicea, choiceb, IntRChange, nafta);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";
	}
	if (change <= 0) {
		std::cout << "Decrease in interest rates." << std::endl;
		InterestRateShockImpact(mycountry, foreigncountry1, foreigncountry2, choice, choicea, choiceb, IntRChange, nafta);
	}
}


