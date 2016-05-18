#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/simulate.h"

/// \fn ExchangeRateShockImpact
/// \brief Impact of an exchange rate appreciation or depreciation on imports exports and GDP
/// \bug No matter the input, it either causes a big recession or good growth levels. Could be caused by our random elasticity values. 

/// \Details ExchangeRate of country C will always refer to how many foreign currencies country C can buy with one unit of country C's currency (ex: If Pound is domestic and Euro foreign, and 1 Pound = 1.27 Euro, then the ExchangeRate is 1.27). Thus an appreciation relative to another currency means an increase in ExchangeRate. 

/// The function takes as inputs a country and a shock to the exchange rate. An appreciation (ExchangeRate > 0) in the currency makes imports less expensive thus increasing the demand for imports while making exports more expensive thus decreasing the foreign for the domestic country's exports. The opposite for a Depreciation (ExchangeRate <= 0).  We can calculate a prediction of the change in imports and exports using the elasticity of imports and exports. Using this we can calculate a prediction for the change in the domestic country's income. If the function is called, it will output the impact on trade and will generate the GDPShockImpact using the predicted income change. 

void ExchangeRateShockImpact(country* domesticcountry, country* foreigncountry, int choice1, int choice2, market* market1, market* market2, market* market3, double change, exportsnetwork* nafta) {	
	market* mymarketfc;
	market* mymarketdom;
	// percent of marketA in total exports of foreign country to domesticcountry
	double pmkt1expfc = (*market1).exchange[choice2-1][choice1-1]/(*nafta).exports[choice2-1][choice1-1]; //dom imports = forexp
	double pmkt2expfc = (*market2).exchange[choice2-1][choice1-1]/(*nafta).exports[choice2-1][choice1-1];
	double pmkt3expfc = (*market3).exchange[choice2-1][choice1-1]/(*nafta).exports[choice2-1][choice1-1];
	double pmkt1expdom = (*market1).exchange[choice1-1][choice2-1]/(*nafta).exports[choice1-1][choice2-1]; //dom exp = forimp
	double pmkt2expdom = (*market2).exchange[choice1-1][choice2-1]/(*nafta).exports[choice1-1][choice2-1];
	double pmkt3expdom = (*market3).exchange[choice1-1][choice2-1]/(*nafta).exports[choice1-1][choice2-1];
	if ((pmkt1expfc >= pmkt2expfc) && (pmkt1expfc >= pmkt3expfc)) {
		mymarketfc = market1;
	}
	else if((pmkt2expfc >= pmkt1expfc) && (pmkt2expfc >= pmkt3expfc)) {
		mymarketfc = market2;
	}
	else {
		mymarketfc = market3;
	}
	if ((pmkt1expdom >= pmkt2expdom) && (pmkt1expdom >= pmkt3expdom)) {
		mymarketdom = market1;
	}
	else if((pmkt2expdom >= pmkt1expdom) && (pmkt2expfc >= pmkt3expdom)) {
		mymarketdom = market2;
	}
	else {
		mymarketdom = market3;
	}
	if (change > 0) { ///Appreciation		
		std::cout << "Good for " << (*domesticcountry).name << "'s imports from "<< (*foreigncountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry).name << "'s " << (*mymarketfc).good << " export market." << 			std::endl;
		std::cout << "Risk for " << (*domesticcountry).name << 	"'s primary exports to " << (*foreigncountry).name 			<< std::endl;
		std::cout << "	Especially " << (*domesticcountry).name << "'s " << (*mymarketdom).good << " export market." << 		std::endl;
	}
	if (change == 0) {
		std::cout << "No impact on economy." << std::endl;	
	}
	if (change <= 0) { ///Depreciation
		std::cout << "Risk for " << (*domesticcountry).name << "'s imports from" << (*foreigncountry).name << std::endl; 
		std::cout << "	Especially " << (*foreigncountry).name << "'s " << (*mymarketfc).good << " export market." << 			std::endl;
		std::cout << "Good for " << (*domesticcountry).name << "'s primary exports to " << (*foreigncountry).name << 			std::endl;
		std::cout << "	Especially " << (*domesticcountry).name << "'s " << (*mymarketdom).good << " export market." << 		std::endl;
	}
}
