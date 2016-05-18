#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"


/// \file country.cpp
/// \brief Macro level functions for country class
/// \bug If there is a problem, it probably has to do with inputting classes. Change the inputs as the address of the class.

/// The country class has functions that allow us to determine the impact of four types of macroeconomic shock: 1. Shock to GDP. 2. Shock to Exchange Rates. 3. Shock to Domestic Interest Rates. 4. Shock to Domestic Inflation Rates. We also include a function that calculates GDP.  

  

double GDP(country* mycountry, float nexports, float nimports) {
	double GDP = (*mycountry).A + nexports - nimports;	
	return GDP;
	}



void GDPShockImpact(country* mycountry, double change) {
	if (change > 2) {
		std::cout << "Good growth levels for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Low risk for " << (*mycountry).name << "'s import markets.";
	}
	if (change > 0 && change <= 2) {
		std::cout << "Slow growth for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout <<  "Medium risk for " << (*mycountry).name << "'s import markets."; 
	}	
	if (change == 0) {
		std::cout << "No growth for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout <<  "Medium risk for " << (*mycountry).name << "'s import markets.";
	}
	if (change < 0 && change >= -1) {
		std::cout << "A Recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "High Risk for " << (*mycountry).name << "'s import markets."; 
	}
	if (change < -1) {
		std::cout << "A Big recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Do not invest in " << (*mycountry).name << "'s import markets."; 
	}
}
 

void ExchangeRateShockImpact(country* domesticcountry,   country* foreigncountry, int choice1, int choice2, double change,   exportsnetwork* nafta) {	
	if (change > 0) { //Appreciation		
		std::cout << "Good for " << (*domesticcountry).name << "'s imports."<< std::endl;
		std::cout << "Risk for " << (*domesticcountry).name << 	"'s primary exports." << std::endl;
	}
	if (change == 0) {
		std::cout << "No impact on economy." << std::endl;	
	}
	if (change <= 0) { //Depreciation
		std::cout << "Risk for " << (*domesticcountry).name << "'s imports." << std::endl; 
		std::cout << "Good for " << (*domesticcountry).name << "'s primary exports." << std::endl;
	}
}


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


