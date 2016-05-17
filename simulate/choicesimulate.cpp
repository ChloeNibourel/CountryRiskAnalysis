#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/genericchoices.h"

//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

/// \file choicesimulate.cpp
/// \brief give the users the options for simulation

void choicesimulate(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork) {
	int choiceshock, countryshock;
	double percentshock;
	country sim;

//loop to choose the type of shock
	do {
		std::cout << blue << "What type of shock do you want to simulate ? 1/2/3/4/5" << std::endl;
		std::cout << " 1. A shock on GDP" << std::endl;
		std::cout << " 2. A shock on Exchange rate" << std::endl;
		std::cout << " 3. A shock on Interest rate" << std::endl;
		std::cout << " 4. A shock on Inflation rate" << std::endl;
		std::cout << " 5. A shock on Production" << def << std::endl;
		std::cout << " 6. Cancel" << def << std::endl;

		std::cin >> choiceshock;
		
		if(std::cin.fail() ){ //if type wasn't right
            std::cin.clear(); //clear stream
            std::cin.ignore(); //ignore left over data
			choiceshock=0; //set value of choice to zero so that we stay in the initial "do-while" loop so that the user gets to choose again
		}

	// CASES: type of shock

		if (choiceshock==1 || choiceshock==3 || choiceshock==4) { //For the cases of GDP, e and inflation the additional informations needed are the same
			do {
				std::cout << blue << "In which country would this shock happen ? 1/2/3/4" << def << std::endl;
				countryshock= choicecountry(country1, country2, country3);
			}while (countryshock==0);
			switch(countryshock) {
				case 1: sim = *country1;
					break;
				case 2: sim = *country2;
					break;
				case 3: sim = *country3;
					break;
				default: std::cout << "Country not available in your location.";

			}	
			if(countryshock!=4){ //If the user doesn't choose to cancel
				percentshock= percentageshock();
			}
			
			switch (choiceshock){
				case 1: GDPShockImpact(sim, percentshock);
				case 3: InterestRateShockImpact(sim, countryshock, percentshock);
				case 4: InflationRateShockImpact(sim, countryshock, percentshock);
			}
		}
		
		if(choiceshock==2){
			do {
				std::cout << blue << "Domestic country : 1/2/3/4" << def << std::endl;
				domcountry= choicecountry(country1, country2, country3);
			}while (domcountry==0);
			
			if(domcountry==4){ //If the user has chosen to cancel don't offer any further choice
				do {
					std::cout << blue << "Foreign country : 1/2/3/4" << def << std::endl;
					forcountry= choicecountry(country1, country2, country3);
				}while (forcountry==0);
			}
			
			if(domcountry==4 || forcountry==4){ //If the user has chosen to cancel don't offer any further choice
				percentshock=percentageshock();
			}
			
			//Call shock exchange rate : first do a switch for domestic country, then for foreign country, then call the function itself
		}
	}while(choiceshock!=1 && choiceshock!=2 && choiceshock!=3 && choiceshock!=4 && choiceshock!=5 && choiceshock!=6)

}
