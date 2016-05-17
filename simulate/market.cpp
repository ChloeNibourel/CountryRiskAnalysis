/// \file market.cpp
/// \brief Define the functions to be executed by the market class


#include <iostream>
#include <cmath>
#include <stream>
#include "country.h"
#include "market.h"



/// \fn MarketShock
/// \brief Determine the impact of a market shock
/// \bug Would using uscan/usmex change the marketvalue or the new value? We almost need markets to be a class defined to a country for this to work.

/// We want to make a qualitative judgement on whether a change in one country's market will have a large or small impact on that country. We want to take as inputs: country, the effected market, and the dollar change in the market in billions. Basically, if the marketchange is negative, the country will export less and import more, thus corresponding to a decrease in that country. Since prices will likely increase in the domestic market due to a shock in the supply, its trading partners will likely demand more of their domestic market's goods => an increase in income => increase demand for imports. 

void ProductionShock(const country& mycountry, int choice, const market& mymarket, double change) {
	switch (choice) {
			case 1 : const &country foreigncountry1 = Canada; ///We might not care about foreigncountry
				int choicea = 2;
				const &country foreigncountry2 = Mexico;
				int choiceb = 3;
				break;
			case 2 : const &country foreigncountry1 = USA;
				int choicea = 1;
				const &country foreigncountry2 = Mexico;
				int choiceb = 3;
				break;
			case 3 : const &country foreigncountry1 = USA;
				int choicea = 1;
				const &country foreigncountry2 = Canada;
				int choiceb = 2;
				break;
			default : std::cout << "Country not available in your location";	
	}
	
	double expforeigncountry1 = (*mymarket).exchange[choice-1][choicea-1];
	double expforeigncountry2 = (*mymarket).exchange[choice-1][choiceb-1];
	double impforeigncountry1 = (*mymarket).exchange[choicea-1][choice-1];
	double impforeigncountry2 = (*mymarket).exchange[choiceb-1][choice-1];
		///Percentage of total exports of foreign country 1 and 2
	double ptotalexpfc1 = (*mymarket).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1];
	double ptotalexpfc2 = (*mymarket).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1];
		///Definition of difference for country	
	if(impforeigncountry1 < impforeigncountry2) {
		double diff = (impforeigncountry2 - impforeigncountry1)/impforeigncountry2;
	}
	else {
		double diff = (impforeigncountry2 - impforeigncountry1)/impforeigncountry1;
	}
	if (change > 0) {
		std::cout << "Good for " << (*mycountry).name << "'s " << (*mycountry).name << " export market" << std::endl
		std::cout << "Risk for " << (*foreigncountry1).name << "'s " << (*mymarket).good << " export market" << 		std::endl << "Risk for " << (*foreigncountry2).name << "'s " << (*mymarket).good << std::endl;
		if (ptotalexpfc1 > ptotalexpfc2) {
			std::endl << "Bigger risk for " << (*foreigncountry1).name << "'s economy.";	
		}
		if (ptotalexpfc1 == ptotalexpfc2) {
			std::endl << "Equal risk for both countries."; 
		}
		if (ptotalexpfc1 < ptotalexpfc2) {
			std::endl << "Bigger risk for " << (*foreigncountry2).name << "'s economy.";
		}
	if (change == 0) {
		std::cout << "No impact on " << (*mycountry).name << "'s economy."; 
	}
	if (change < 0) {
		std::cout << "Risk for " << (*mycountry).name << "'s " << (*mymarket).good << " export market" << std::endl;
		if (diff >= 0.1) {
			std::cout << "Investment in " << (*foreigncountry2).name << "'s " << (*mymarket).good << " export 				market will have higher yield.";
		}
		if (diff < -0.1) {
			std::cout << "Investment in " << (*foreigncountry1).name << "'s " << (*mymarket).good << " export 				market will have higher yield.";
		}
		if (diff>= -0.1 & diff <0.1) {
			std::cout << "Investment in both " << (*foreigncountry1).name << " and " << (*foreigncountry2).name 				<< " 's export markets will have approximately equal yields";
		}
	}
}

