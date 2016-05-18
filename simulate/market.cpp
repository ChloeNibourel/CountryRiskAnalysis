/// \file market.cpp
/// \brief Define the ProductionShock function


#include <iostream>
#include <cmath>
#include <string>
#include "../headers/country.h"
#include "../headers/market.h"



void ProductionShock(country* mycountry, country* foreigncountry1, country* foreigncountry2, int choice, int choicea, int choiceb, market* mymarket, double change, exportsnetwork* nafta) {
	double diff;
	double expforeigncountry1 = (*mymarket).exchange[choice-1][choicea-1]; //exports from mycountry to foreigncountry1
	double expforeigncountry2 = (*mymarket).exchange[choice-1][choiceb-1]; //exports from mycountry to foreigncountry2
	double impforeigncountry1 = (*mymarket).exchange[choicea-1][choice-1]; //exports from foreigncountry1 to mycountry
	double impforeigncountry2 = (*mymarket).exchange[choiceb-1][choice-1]; //exports from foreigncountry2 to mycoutry
		//Percentage of total exports from foreign country 1 and 2 to mycountry
	double ptotalexpfc1 = (*mymarket).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1];
	double ptotalexpfc2 = (*mymarket).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1];
		//Definition of difference for country scaled to the largest market
	if(impforeigncountry1 < impforeigncountry2) {
		diff = (impforeigncountry2 - impforeigncountry1)/impforeigncountry2;
	}
	else {
		diff = (impforeigncountry2 - impforeigncountry1)/impforeigncountry1;
	}
	//If we have a positive shock on a market => good for domesticcoutry's export, bad for foreigncountry1 and foreigncountry2's exports. Defines which country between foreigncountry1 and foreigncountry2 is most at risk based on which market had a larger percent of total exports to that country. Took relative values for positive shocks.
	if (change > 0) {
		std::cout << "Good for " << (*mycountry).name << "'s " << (*mymarket).good << " export market" << std::endl;
		std::cout << "Risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s " <<	(*mymarket).good << " export markets" << std::endl;
		if (ptotalexpfc1 > ptotalexpfc2) {
			std::cout << "	Bigger risk for " << (*foreigncountry1).name << "'s economy";	
		}
		if (ptotalexpfc1 == ptotalexpfc2) {
			std::cout << "	Equal risk for both countries."; 
		}
		if (ptotalexpfc1 < ptotalexpfc2) {
			std::cout << "	Bigger risk for " << (*foreigncountry2).name << "'s economy";
		}
	}
	//If we have no shock on the market, it will have no effect on anything
	if (change == 0) {
		std::cout << "No impact on " << (*mycountry).name << "'s economy."; 
	}
	//If we have a negative shock on a market => risk for domestic country's exports, good for foreigncountry1 and foreigncountry2's exports. Defines which country between foreigncountry1 and foreigncountry2 will yield higher returns based on which country has the largest level of exports to the domestic country (in absolutes). Took absolute values for negative shocks
	if (change < 0) {
		std::cout << "Risk for " << (*mycountry).name << "'s " << (*mymarket).good << " export market" << std::endl;
		std::cout << "Good for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s " <<	(*mymarket).good << " export markets" << std::endl;
		if (diff >= 0.1) {
			std::cout << "	Investment in " << (*foreigncountry2).name << "'s export market will have higher returns.";
		}
		if (diff < -0.1) {
			std::cout << "	Investment in " << (*foreigncountry1).name << "'s export market will have higher returns.";
		}
		if (diff>= -0.1 & diff <0.1) {
			std::cout << "Investment in both " << (*foreigncountry1).name << " and " << (*foreigncountry2).name 				<< " 's export markets will have approximately equal returns.";
		}
	}
}

