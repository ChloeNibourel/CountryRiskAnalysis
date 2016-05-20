#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/simulate.h"

/// \file InterestAndInflation.cpp
/// \brief Defines the InterestRateShockImpact and InflationRateShockImpact functions

void InterestRateShockImpact(country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, market* market1, market* market2, market* market3, double change,   exportsnetwork* nafta) {
	double ExchRChange = change;	//An interest rate shock will imply a shock in the same direction on the exchange rate
	//Function outputs depending onf the sign of the change
	if (change > 0) {
		std::cout << "Simulateneous appreciation of " << (*domesticcountry).name << "'s exchange rate with:" << std::endl;
		std::cout << "	" << (*foreigncountry1).name << std::endl;
		std::cout << "	" << (*foreigncountry2).name << std::endl;
		std::cout << "Effect on " << (*foreigncountry1).name << ":" << std::endl;
		ExchangeRateShockImpact(domesticcountry, foreigncountry1, choice, choicea, market1, market2, market3, ExchRChange, 			nafta);
		std::cout << "Effect on " << (*foreigncountry2).name << ":" << std::endl;
		ExchangeRateShockImpact(domesticcountry, foreigncountry2, choice, choiceb, market1, market2, market3, ExchRChange, 			nafta);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";	
	}
	if (change < 0) {
		std::cout << "Simulateneous depreciation of " << (*domesticcountry).name << "'s exchange rate with:" << std::endl;
		std::cout << "	" << (*foreigncountry1).name << std::endl;
		std::cout << "	" << (*foreigncountry2).name << std::endl;
		std::cout << "Effect on " << (*foreigncountry1).name << ":" << std::endl;
		ExchangeRateShockImpact(domesticcountry, foreigncountry1, choice, choicea, market1, market2, market3, ExchRChange, 			nafta);
		std::cout << "Effect on " << (*foreigncountry2).name << ":" << std::endl;
		ExchangeRateShockImpact(domesticcountry, foreigncountry2, choice, choiceb, market1, market2, market3, ExchRChange, 			nafta);
	}
}

void InflationRateShockImpact(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, market* market1, market* market2, market* market3, double change,   exportsnetwork* nafta) {
	double IntRChange = change; //An inflation rate shock implies a shock on the interest rate in the same direction
	//Function output depending on the sign of the shock
	if (change > 0) {
		std::cout << "Increase in interest rates." << std::endl;
		InterestRateShockImpact(mycountry, foreigncountry1, foreigncountry2, choice, choicea, choiceb, market1, market2, 			market3, IntRChange, nafta);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";
	}
	if (change <= 0) {
		std::cout << "Decrease in interest rates." << std::endl;
		InterestRateShockImpact(mycountry, foreigncountry1, foreigncountry2, choice, choicea, choiceb, market1, market2, 			market3, IntRChange, nafta);
	}
}


