#include <iostream>
#include <string> 
#include <cmath>
#include "country.h"

/// \file country.cpp
/// \brief Macro level functions for country class
/// \bug Remember to delete the int main() in this file. It only exists to test the functions. We also may want to include different risk levels (small change in interest rates => small change in exchange rate => low risk). 

/// \Detail The country class has functions that allow us to determine the impact of four types of macroeconomic shock: 1. Shock to GDP. 2. Shock to Exchange Rates. 3. Shock to Domestic Interest Rates. 4. Shock to Domestic Inflation Rates. We also include a function that calculates GDP.  

/// \func GDP 
/// \brief Calculates GDP

/// \Detail This function calculates a countries GDP as a function of domestic consuption, total exports and total imports. The variable A = country.income - (country.totalexports - country.totalimports). In other words, A is the GDP when we exclude the trade balance. A will not change in our model unless it is updated.  

double GDP(const country& mycountry, float nexports, float nimports) {
	double GDP = mycountry.A + nexports - nimports;	
	return GDP;
	}

/// \func GDPShockImpact
/// \brief Determines the impact of a shock to GDP growth
/// \bug Maybe we should include last growth in the class. Since a contraction has negative impacts on trading partners even if the country is growing (ex: China). Easy change.

/// \Detail The GDPShockImpact takes as inputs country and a variable representing the shock to GDP called GDPChange := Percent change in GDP. If we see growth (GDPChange > 0) in a country, it will increase the demand for its imports. Thus we can expect its primary trading partners to increase the volume of their exports. If rather, we see a recession (GDPChange < 0) in a country, it will decrease the demand of their imports. Thus there is a risk for its primary trading partners' exports. 

void GDPShockImpact(const country& mycountry, double change) {
	if (change > 2) {
		std::cout << "Good growth levels. Low risk for " << mycountry.name << "'s import markets.";
	}
	if (change > 0 & GDPChange <= 2) {
		std::cout << "Slow growth. Medium risk for " << mycountry.name << "'s import markets."; 
	if (change = 0) {
		std::cout << "No growth. Medium risk for " << mycountry.name << "'s import markets.";
	}
	if (change < 0 & GDPChange >= -1) {
		std::cout << "Recession. High Risk for " << mycountry.name << "'s import markets."; 
	}
	if (change < -1) {
		std::cout << "Big recession. Do not invest in " << mycountry.name << "'s import markets."; 
	}
}

/// \func ExchangeRateShockImpact
/// \brief Impact of an exchange rate appreciation or depreciation on imports exports and GDP
/// \bug How does cpp read specific values.

/// \Details ExchangeRate of country C will always refer to how many foreign currencies country C can buy with one unit of country C's currency (ex: If Pound is domestic and Euro foreign, and 1 Pound = 1.27 Euro, then the ExchangeRate is 1.27). Thus an appreciation relative to another currency means an increase in ExchangeRate. 

/// The function takes as inputs a country and a shock to the exchange rate. An appreciation (ExchangeRate > 0) in the currency makes imports less expensive thus increasing the demand for imports while making exports more expensive thus decreasing the foreign for the domestic country's exports. The opposite for a Depreciation (ExchangeRate <= 0).  We can calculate a prediction of the change in imports and exports using the elasticity of imports and exports. Using this we can calculate a prediction for the change in the domestic country's income. If the function is called, it will output the impact on trade and will generate the GDPShockImpact using the predicted income change. 

void ExchangeRateShockImpact(const country& domesticcountry, const country& foreigncountry, double ExchRChange) {
	double changeimports = ExchRChange*domesticcountry.elasticityimports;
	double changeexports = ExchRChange*domesticcountry.elasticityexports;
	double newimports = changeimports*mycountry.totalimports;
	double newexports = changeexports*mycountry.totalexports;
	double newincome = GDP(mycountry, newexports, newexports);
	double incomechange = (newincome - mycountry.income)/mycountry.income;
	if (ExchRChange > 0) { ///Appreciation		
		std::cout << mycountry.name << " will see an increased demand in imports and a decreased demand in exports. Good for" << mycountry.othercountryexports << ". Risk for " << mycountry.exportmarkets << ". ";
		GDPShockImpact(mycountry, incomechange);
	}
	if (ExchRChange <= 0) { ///Depreciation
		std::cout << mycountry.name << "will see a decreased demand in imports and an increased demand in exports. Good for " << mycountry.exportmarkets << " Risk for " << mycountry.othercountryexports << ".";
		GDPShockImpact(mycountry, incomechange);
	}
}

/// \func InterestRateShockImpact
/// \brief Determine impact of a shock to interest rates. 

/// \Detail When there is an increase in interest rates, we see an increase in the domestic exchange rate since their is more demand for the domestic currency due to superior investment returns in that country. Thus an increase in interest rates will result in a currency appreciation and a decrease in interest rates will result in a currency depreciation. The function takes as inputs the country and the interest rate change, and outputs the effect on the exchange rate while calling the ExchangeRateShockImpact function. 

void InterestRateShockImpact(const country& mycountry, double IntRChange) {
	double ExchRChange = IntRChange;
	if (IntRChange > 0) {
		std::cout << "Appreciation of exchange rate. ";
		ExchangeRateShockImpact(mycountry, ExchRChange);
	}
	if (IntRChange <= 0) {
		std::cout << "Depreciation of exchange rate. ";
		ExchangeRateShockImpact(mycountry, ExchRChange);
	}
}

/// \func InflationRateShockImpact
/// \brief Determine the impact of a shock of the inflation rate.


/// \Detail When there is an increase in inflation, it results in an increase in the domestic interest rate since banks run a higher risk when they lend money. When there is a decrease in inflation we see a decrease in interest rates. The function takes an inputs the country and the inflation rate change, and outputs the effect on interest rates while calling the InterestRateShockImpact function.

void InflationRateShockImpact(const country& mycountry, double InflRChange) {
	double IntRChange = InflRChange;
	if (InflRChange >0) {
		std::cout << "Increase in interest rates. " ;
		InterestRateShockImpact(mycountry, IntRChange);
	}
	if (InflRChange <= 0) {
		std::cout << "Decrease in interest rates. ";
		InterestRateShockImpact(mycountry, IntRChange);
	}
}

int main() {
	country Mexico;
	Mexico.name = "Mexico";
	Mexico.othercountryexports = "Canada's Food Exports and USA's Petrol Exports.";
	Mexico.elasticityimports = 0.45;
	Mexico.elasticityexports = -0.20;
	Mexico.totalimports = 204;
	Mexico.totalexports = 109;
	Mexico.A = 2094+109-204;
	Mexico.income = 2094;
	Mexico.exportmarkets = "Mexico's Pharmaceutical, Food, and Petrol markets";
	InflationRateShockImpact(, -5); 
}

