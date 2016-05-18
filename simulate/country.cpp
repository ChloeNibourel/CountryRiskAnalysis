#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"


/// \file country.cpp
/// \brief Macro level functions for country class
/// \bug If there is a problem, it probably has to do with inputting classes. Change the inputs as the address of the class.

/// \Detail The country class has functions that allow us to determine the impact of four types of macroeconomic shock: 1. Shock to GDP. 2. Shock to Exchange Rates. 3. Shock to Domestic Interest Rates. 4. Shock to Domestic Inflation Rates. We also include a function that calculates GDP.  

/// \fn GDP 
/// \brief Calculates GDP

/// \Detail This function calculates a countries GDP as a function of domestic consuption, total exports and total imports. The variable A = country.income - (country.totalexports - country.totalimports). In other words, A is the GDP when we exclude the trade balance. A will not change in our model unless it is updated.  

double GDP(  country* mycountry, float nexports, float nimports) {
	double GDP = (*mycountry).A + nexports - nimports;	
	return GDP;
	}

/// \func GDPShockImpact
/// \brief Determines the impact of a shock to GDP growth
/// \bug Inputting -3 will end program.

/// \Detail The GDPShockImpact takes as inputs country and a variable representing the shock to GDP called GDPChange := Percent change in GDP. If we see growth (GDPChange > 0) in a country, it will increase the demand for its imports. Thus we can expect its primary trading partners to increase the volume of their exports. If rather, we see a recession (GDPChange < 0) in a country, it will decrease the demand of their imports. Thus there is a risk for its primary trading partners' exports. 

void GDPShockImpact(  country* mycountry, double change) {
	if (change > 2) {
		std::cout << "Good growth levels." << std::endl << "Low risk for " << (*mycountry).name << "'s import markets.";
	}
	if (change > 0 && change <= 2) {
		std::cout << "Slow growth." << std::endl << "Medium risk for " << (*mycountry).name << "'s import markets."; 
	}	
	if (change == 0) {
		std::cout << "No growth." << std::endl << "Medium risk for " << (*mycountry).name << "'s import markets.";
	}
	if (change < 0 && change >= -1) {
		std::cout << "Recession." << std::endl << "High Risk for " << (*mycountry).name << "'s import markets."; 
	}
	if (change < -1) {
		std::cout << "Big recession." << std::endl << "Do not invest in " << (*mycountry).name << "'s import markets."; 
	}
}

/// \fn ExchangeRateShockImpact
/// \brief Impact of an exchange rate appreciation or depreciation on imports exports and GDP

/// \Details ExchangeRate of country C will always refer to how many foreign currencies country C can buy with one unit of country C's currency (ex: If Pound is domestic and Euro foreign, and 1 Pound = 1.27 Euro, then the ExchangeRate is 1.27). Thus an appreciation relative to another currency means an increase in ExchangeRate. 

/// The function takes as inputs a country and a shock to the exchange rate. An appreciation (ExchangeRate > 0) in the currency makes imports less expensive thus increasing the demand for imports while making exports more expensive thus decreasing the foreign for the domestic country's exports. The opposite for a Depreciation (ExchangeRate <= 0).  We can calculate a prediction of the change in imports and exports using the elasticity of imports and exports. Using this we can calculate a prediction for the change in the domestic country's income. If the function is called, it will output the impact on trade and will generate the GDPShockImpact using the predicted income change. 

void ExchangeRateShockImpact(country* domesticcountry,   country* foreigncountry, int choice1, int choice2, double change,   exportsnetwork* nafta) {	
	double changeimports = change*(*domesticcountry).elasticityimports;
	double changeexports = change*(*domesticcountry).elasticityexports;
	double newimports = changeimports*(*nafta).exports[choice2-1][choice1-1]; 
	double newexports = changeexports*(*nafta).exports[choice1-1][choice2-1];
	double newincome = GDP(domesticcountry, newexports, newimports);
	double incomechange = (newincome - (*domesticcountry).income)/(*domesticcountry).income;
	if (change > 0) { ///Appreciation		
		std::cout << "Good for" << (*domesticcountry).name << "'s imports. Risk for " << (*domesticcountry).name << 				"'s primary exports. ";
		GDPShockImpact(domesticcountry, incomechange);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";	
	}
	if (change <= 0) { ///Depreciation
		std::cout << "Risk for " << (*domesticcountry).name << "'s imports. Good for " << (*domesticcountry).name << 			" 's primary exports.";
		GDPShockImpact(domesticcountry, incomechange);
	}
}

/// \func InterestRateShockImpact
/// \brief Determine impact of a shock to interest rates. 

/// \Detail When there is an increase in interest rates, we see an increase in the domestic exchange rate since their is more demand for the domestic currency due to superior investment returns in that country. Thus an increase in interest rates will result in a currency appreciation and a decrease in interest rates will result in a currency depreciation. The function takes as inputs the country and the interest rate change, and outputs the effect on the exchange rate while calling the ExchangeRateShockImpact function. 

void InterestRateShockImpact(  country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta) {
	double ExchRChange = change;	
	if (change > 0) {
		std::cout << "Simulateneous Appreciation of " << (*domesticcountry).name << "'s exchange rate with:" << 			std::endl;
		std::cout << (*foreigncountry1).name << std::endl;
		std::cout << " and " << (*foreigncountry2).name;
		ExchangeRateShockImpact(domesticcountry, foreigncountry1, choice, choicea, ExchRChange, nafta);
		ExchangeRateShockImpact(domesticcountry, foreigncountry2, choice, choiceb, ExchRChange, nafta);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";	
	}
	if (change < 0) {
		std::cout << "Simulateneous Depreciation of " << (*domesticcountry).name << "'s exchange rate with:" << 		std::endl;
		std::cout << (*foreigncountry1).name << " and " << (*foreigncountry2).name;
		ExchangeRateShockImpact(domesticcountry, foreigncountry1, choice, choicea, ExchRChange, nafta);
		ExchangeRateShockImpact(domesticcountry, foreigncountry2, choice, choiceb, ExchRChange, nafta);
	}
}

/// \func InflationRateShockImpact
/// \brief Determine the impact of a shock of the inflation rate.


/// \Detail When there is an increase in inflation, it results in an increase in the domestic interest rate since banks run a higher risk when they lend money. When there is a decrease in inflation we see a decrease in interest rates. The function takes an inputs the country and the inflation rate change, and outputs the effect on interest rates while calling the InterestRateShockImpact function.

void InflationRateShockImpact(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta) {
	double IntRChange = change;
	if (change > 0) {
		std::cout << "Increase in interest rates. " ;
		InterestRateShockImpact(mycountry, foreigncountry1, foreigncountry2, choice, choicea, choiceb, IntRChange, nafta);
	}
	if (change == 0) {
		std::cout << "No impact on economy.";
	}
	if (change <= 0) {
		std::cout << "Decrease in interest rates. ";
		InterestRateShockImpact(mycountry, foreigncountry1, foreigncountry2, choice, choicea, choiceb, IntRChange, nafta);
	}
}


