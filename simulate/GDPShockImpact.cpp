#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/simulate.h"



/// \fn GDPShockImpact
/// \brief Determines the impact of a shock to GDP growth

/// \Detail The GDPShockImpact takes as inputs country and a variable representing the shock to GDP called GDPChange := Percent change in GDP. If we see growth (GDPChange > 0) in a country, it will increase the demand for its imports. Thus we can expect its primary trading partners to increase the volume of their exports. If rather, we see a recession (GDPChange < 0) in a country, it will decrease the demand of their imports. Thus there is a risk for its primary trading partners' exports. 

void GDPShockImpact(country* mycountry, country* foreigncountry1, country* foreigncountry2, int choice, int choicea, int choiceb,  market* market1, market* market2, market* market3, double change, exportsnetwork* nafta) {
	market* mymarketfc1;
	market* mymarketfc2;
	double pmkt1expfc1 = (*market1).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1];
	double pmkt2expfc1 = (*market2).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1];
	double pmkt3expfc1 = (*market3).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1];
	double pmkt1expfc2 = (*market1).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1];
	double pmkt2expfc2 = (*market2).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1];
	double pmkt3expfc2 = (*market3).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1];
	if ((pmkt1expfc1 >= pmkt2expfc1) && (pmkt1expfc1 >= pmkt3expfc1)) {
		mymarketfc1 = market1;
	}
	else if((pmkt2expfc1 >= pmkt1expfc1) && (pmkt2expfc1 >= pmkt3expfc1)) {
		mymarketfc1 = market2;
	}
	else {
		mymarketfc1 = market3;
	}
	if ((pmkt1expfc2 >= pmkt2expfc2) && (pmkt1expfc2 >= pmkt3expfc2)) {
		mymarketfc2 = market1;
	}
	else if((pmkt2expfc2 >= pmkt1expfc2) && (pmkt2expfc2 >= pmkt3expfc2)) {
		mymarketfc2 = market2;
	}
	else {
		mymarketfc2 = market3;
	}
	if (change > 2) {
		std::cout << "Good growth levels for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Low risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " <<  			(*mycountry).name << std::endl;
		std::cout << "	Especially" << (*foreigncountry1).name << "'s " << (*mymarketfc1).name << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).name << " export market." << std::endl;
	}
	if (change > 0 && change <= 2) {
		std::cout << "Slow growth for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Medium risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " 			<< (*mycountry).name << std::endl;
		std::cout << "	Especially" << (*foreigncountry1).name << "'s " << (*mymarketfc1).name << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).name << " export market." << std::endl;
	}	
	if (change == 0) {
		std::cout << "No growth for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Medium risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " 			<< (*mycountry).name << std::endl;
		std::cout << "	Especially" << (*foreigncountry1).name << "'s " << (*mymarketfc1).name << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).name << " export market." << std::endl;
	}
	if (change < 0 && change >= -1) {
		std::cout << "A recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "High risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " << 			(*mycountry).name << std::endl;
		std::cout << "	Especially" << (*foreigncountry1).name << "'s " << (*mymarketfc1).name << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).name << " export market." << std::endl;
	}
	if (change < -1) {
		std::cout << "A big recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Do not invest in " << (*mycountry).name << "'s import markets."; 
		std::cout << "Big recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Do not invest in " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " 			<< (*mycountry).name << std::endl;
		std::cout << "	Especially" << (*foreigncountry1).name << "'s " << (*mymarketfc1).name << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).name << " export market." << std::endl;
	}
}

