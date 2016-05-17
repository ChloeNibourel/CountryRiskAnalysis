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

void choicesimulate() {
	int choiceshock, countryshock;

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

		if (choiceshock==1 || choiceshcok==3 || choiceshock==4) { //For the cases of GDP, e and inflation the additional informations needed are the same
			do {
				std::cout << blue << "In which country would this shock happen ? 1/2/3/4" << def << std::endl;
				countryshock= choicecountry(country1, country2, country3);
			}while (countryshock==0);
			
			if(countryshock!=4){ //If the user doesn't choose to cancel
				double percentshock= percentageshock();
			}
			
			switch (choiceshock){
				case 1: //Call function shockGDP(countryshock, percentageshock)
				case 3: //Call function shockGDP(countryshock, percentageshock)
				case 4: //Call function shockGDP(countryshock, percentageshock)
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
		
		
		if(choiceshock==5){
			//Choosing a country
			do {
				std::cout << blue << "Domestic country : 1/2/3/4" << def << std::endl;
				countryshock= choicecountry(country1, country2, country3);
			}while (countryshock==0);
			
			//Choosing a market
			if(countryshock!=4){ //If the user has chosen to cancel don't offer any further choice
				do {
					std::cout << blue << "Which market are you interested in ? 1/2/3/4" << std::endl;
					std::cout << " 1. Food" << std::endl;
					std::cout << " 2. Machinery and transport equipment" << std::endl;
					std::cout << " 3. Fuel" << std::endl;
					std::cout << " 4. Cancel" << def << std::endl;
			
					std::cin>> mkt;
				
					if(std::cin.fail() ){ //if type wasn't right
            			std::cin.clear(); //clear stream
            			std::cin.ignore(); //ignore left over data
						mkt=0;
					}
					
					if (mkt!=1 && mkt!=2 && mkt!=3 && mkt!=4){
						std::cout << "Error : enter 1, 2, 3 or 4" << std::endl;
					}
					
				}while (mkt!=1 && mkt!=2 && mkt!=3 && mkt!=4);
				
			}
			
			//Entering a percentage of shock
			if(countryshock!=4 || mkt!=4){ //If the user has chosen to cancel don't offer any further choice
				percentshock=percentageshock();
			}
			
			//Swith countryshock to determine a country, switch mkt to determine market, call shockproduction
		}
	}while(choiceshock!=1 && choiceshock!=2 && choiceshock!=3 && choiceshock!=4 && choiceshock!=5 && choiceshock!=6)

}