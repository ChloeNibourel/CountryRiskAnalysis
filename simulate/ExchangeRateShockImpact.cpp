#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/simulate.h"

/// \file ExchangeRateShockImpact.cpp
/// \brief Defines the ExchangeRateShockImpact function

void ExchangeRateShockImpact(country* domesticcountry, country* foreigncountry, int choice1, int choice2, market* market1, market* market2, market* market3, double change, exportsnetwork* nafta) {	
	market* mymarketfc; //Defines the largest export market from foreigncountry to domesticcountry
	market* mymarketdom; //Defines the largest export market from domesticcountry to foreigncountry
	// percent of market X in total exports of foreigncountry to domesticcountry
	double pmkt1expfc = (*market1).exchange[choice2-1][choice1-1]/(*nafta).exports[choice2-1][choice1-1];
	double pmkt2expfc = (*market2).exchange[choice2-1][choice1-1]/(*nafta).exports[choice2-1][choice1-1];
	double pmkt3expfc = (*market3).exchange[choice2-1][choice1-1]/(*nafta).exports[choice2-1][choice1-1];
	//percent of market X in total export of domesticcountry to foreigncountry	
	double pmkt1expdom = (*market1).exchange[choice1-1][choice2-1]/(*nafta).exports[choice1-1][choice2-1];
	double pmkt2expdom = (*market2).exchange[choice1-1][choice2-1]/(*nafta).exports[choice1-1][choice2-1];
	double pmkt3expdom = (*market3).exchange[choice1-1][choice2-1]/(*nafta).exports[choice1-1][choice2-1];
	//Determines largest export market from foreigncountry to domesticcountry	
	if ((pmkt1expfc >= pmkt2expfc) && (pmkt1expfc >= pmkt3expfc)) {
		mymarketfc = market1;
	}
	else if((pmkt2expfc >= pmkt1expfc) && (pmkt2expfc >= pmkt3expfc)) {
		mymarketfc = market2;
	}
	else {
		mymarketfc = market3;
	}
	//Determines largest export market from domesticcountry to foreigncountry
	if ((pmkt1expdom >= pmkt2expdom) && (pmkt1expdom >= pmkt3expdom)) {
		mymarketdom = market1;
	}
	else if((pmkt2expdom >= pmkt1expdom) && (pmkt2expfc >= pmkt3expdom)) {
		mymarketdom = market2;
	}
	else {
		mymarketdom = market3;
	}
	//Function outputs depending on the sign of the shock
	if (change > 0) { ///Appreciation		
		std::cout << "Good for " << (*foreigncountry).name <<  "'s exports to "<< (*domesticcountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry).name << "'s " << (*mymarketfc).good << " export market." << 			std::endl;
		std::cout << "Risk for " << (*domesticcountry).name << 	"'s primary exports to " << (*foreigncountry).name 			<< std::endl;
		std::cout << "	Especially " << (*domesticcountry).name << "'s " << (*mymarketdom).good << " export market." << 		std::endl;
	}
	if (change == 0) {
		std::cout << "No impact on economy." << std::endl;	
	}
	if (change <= 0) { ///Depreciation
		std::cout << "Risk for " << (*foreigncountry).name << "'s imports from " << (*domesticcountry).name << std::endl; 
		std::cout << "	Especially " << (*foreigncountry).name << "'s " << (*mymarketfc).good << " export market." << 			std::endl;
		std::cout << "Good for " << (*domesticcountry).name << "'s primary exports to " << (*foreigncountry).name << 			std::endl;
		std::cout << "	Especially " << (*domesticcountry).name << "'s " << (*mymarketdom).good << " export market." << 		std::endl;
	}
}
