/// \file market.cpp
/// \brief Define the functions to be executed by the market class


#include <iostream>
#include <cmath>
#include <string>
#include "../headers/country.h"
#include "../headers/market.h"



void ProductionShock(country* mycountry, country* foreigncountry1, country* foreigncountry2, int choice, int choicea, int choiceb, market* mymarket, double change, exportsnetwork* nafta) {
	double diff;	
	double expforeigncountry1 = (*mymarket).exchange[choice-1][choicea-1];
	double expforeigncountry2 = (*mymarket).exchange[choice-1][choiceb-1];
	double impforeigncountry1 = (*mymarket).exchange[choicea-1][choice-1];
	double impforeigncountry2 = (*mymarket).exchange[choiceb-1][choice-1];
		//Percentage of total exports of foreign country 1 and 2
	double ptotalexpfc1 = (*mymarket).exchange[choicea-1][choice-1]/(*nafta).exports[choicea-1][choice-1];
	double ptotalexpfc2 = (*mymarket).exchange[choiceb-1][choice-1]/(*nafta).exports[choiceb-1][choice-1];
		//Definition of difference for country	
	if(impforeigncountry1 < impforeigncountry2) {
		diff = (impforeigncountry2 - impforeigncountry1)/impforeigncountry2;
	}
	else {
		diff = (impforeigncountry2 - impforeigncountry1)/impforeigncountry1;
	}
	if (change > 0) {
		std::cout << "Good for " << (*mycountry).name << "'s " << (*mycountry).name << " export market" << std::endl;
		std::cout << "Risk for " << (*foreigncountry1).name << "'s " << (*mymarket).good << " export market" << std::endl;
		std::cout << "Risk for " << (*foreigncountry2).name << "'s " << (*mymarket).good << std::endl;
		if (ptotalexpfc1 > ptotalexpfc2) {
			std::cout << "Bigger risk for " << (*foreigncountry1).name << "'s economy.";	
		}
		if (ptotalexpfc1 == ptotalexpfc2) {
			std::cout << "Equal risk for both countries."; 
		}
		if (ptotalexpfc1 < ptotalexpfc2) {
			std::cout << "Bigger risk for " << (*foreigncountry2).name << "'s economy.";
		}
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

