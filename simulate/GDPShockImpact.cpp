#include <iostream>
#include <string> 
#include <cmath>
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/simulate.h"

/// \file GDPShockImpact.cpp
/// \brief Defines the function GDPShockImpact 

void GDPShockImpact(country* mycountry, country* foreigncountry1, country* foreigncountry2, int choice, int choicea, int choiceb,  market* market1, market* market2, market* market3, double change, exportsnetwork* nafta) {
	market* mymarketfc1; //defines the largest export market from foreigncountry1 to mycountry
	market* mymarketfc2; //defines the largest export market from foreigncountry2 to mycountry
	double pmkt1expfc1 = (*market1).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1]; //market1- fc1-mycountry
	double pmkt2expfc1 = (*market2).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1]; //market2
	double pmkt3expfc1 = (*market3).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1]; //market3
	double pmkt1expfc2 = (*market1).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1]; //market1- fc2-mycountry
	double pmkt2expfc2 = (*market2).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1]; //market2
	double pmkt3expfc2 = (*market3).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1]; //market3
	//Determines the largest export market from foreigncountry1 to mycountry	
	if ((pmkt1expfc1 >= pmkt2expfc1) && (pmkt1expfc1 >= pmkt3expfc1)) {
		mymarketfc1 = market1;
	}
	else if((pmkt2expfc1 >= pmkt1expfc1) && (pmkt2expfc1 >= pmkt3expfc1)) {
		mymarketfc1 = market2;
	}
	else {
		mymarketfc1 = market3;
	}
	//Determines the largest export market from foreigncountry2 to mycountry
	if ((pmkt1expfc2 >= pmkt2expfc2) && (pmkt1expfc2 >= pmkt3expfc2)) {
		mymarketfc2 = market1;
	}
	else if((pmkt2expfc2 >= pmkt1expfc2) && (pmkt2expfc2 >= pmkt3expfc2)) {
		mymarketfc2 = market2;
	}
	else {
		mymarketfc2 = market3;
	}
	//Outputs different things depending on the shock level
	if (change > 2) {
		std::cout << "Good growth levels for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Low risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " <<  			(*mycountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry1).name << "'s " << (*mymarketfc1).good << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).good << " export market." << std::endl;
	}
	if (change > 0 && change <= 2) {
		std::cout << "Slow growth for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Medium risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " 			<< (*mycountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry1).name << "'s " << (*mymarketfc1).good << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).good << " export market." << std::endl;
	}	
	if (change == 0) {
		std::cout << "No growth for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Medium risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " 			<< (*mycountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry1).name << "'s " << (*mymarketfc1).good << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).good << " export market." << std::endl;
	}
	if (change < 0 && change >= -1) {
		std::cout << "A recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "High risk for " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " << 			(*mycountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry1).name << "'s " << (*mymarketfc1).good << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).good << " export market." << std::endl;
	}
	if (change < -1) {
		std::cout << "Big recession for "<< (*mycountry).name << "'s economy" << std::endl;
		std::cout << "Do not invest in " << (*foreigncountry1).name << " and " << (*foreigncountry2).name << "'s exports to " 			<< (*mycountry).name << std::endl;
		std::cout << "	Especially " << (*foreigncountry1).name << "'s " << (*mymarketfc1).good << " export market and " << 			(*foreigncountry2).name << "'s "<< (*mymarketfc2).good << " export market." << std::endl;
	}
}

