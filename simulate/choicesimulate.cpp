#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/choices.h"
#include "../headers/simulate.h"



/// \file choicesimulate.cpp
/// \brief give the users the options for simulation

void choicesimulate(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork) {

	//ask the questions in blue and errors in red
  	Color::Modifier blue(Color::FG_BLUE);
    	Color::Modifier red(Color::FG_RED);
    	Color::Modifier def(Color::FG_DEFAULT);	
	int choiceshock, countryshock, mkt, domcountry, forcountry;
	double percentshock;
	country* sim;
	country* sim1;
	country* sim2;
	market* simm;

//loop to choose the type of shock
	do {
		std::cout << blue << "What type of shock do you want to simulate ? 1/2/3/4/5" << std::endl;
		std::cout << " 1. A shock on GDP" << std::endl;
		std::cout << " 2. A shock on Exchange rate" << std::endl;
		std::cout << " 3. A shock on Interest rate" << std::endl;
		std::cout << " 4. A shock on Inflation rate" << std::endl;
		std::cout << " 5. A shock on Production" << std::endl;
		std::cout << " 6. Cancel" << def << std::endl;

		std::cin >> choiceshock;
		
		if(std::cin.fail() ){ //if type wasn't right
            std::cin.clear(); //clear stream
            std::cin.ignore(); //ignore left over data
			choiceshock=0; //set value of choice to zero so that we stay in the initial "do-while" loop so that the user gets to choose again
		}

	// CASES: type of shock
		//GDP shock
		if (choiceshock==1) { //For the cases of GDP, e and inflation the additional informations needed are the same
			/// \bug if you cancel after choosing 1, the program breaks down.
			do {
				std::cout << blue << "In which country would this shock happen ? 1/2/3/4" << def << std::endl;
				countryshock= choicecountry(country1, country2, country3);
			}while (countryshock==0);
			
			
			
			if(countryshock!=4){ //If the user doesn't choose to cancel
				percentshock= percentageshock();
				
				//Determine which country has been chosen and will be given as input of GDPShock
				switch(countryshock) {
				case 1: GDPShockImpact(country1, country2, country3, 1, 2, 3, market1, market2, market3, 						percentshock, mynetwork);
					break;
				case 2: GDPShockImpact(country2, country1, country3, 2, 1, 3, market1, market2, market3, 						percentshock, mynetwork);
					break;
				case 3: GDPShockImpact(country3, country1, country2, 3, 1, 2, market1, market2, market3, 						percentshock, mynetwork);
					break;
				}	
			}
			
			
		}
		
		//Exchange rate shock
		if(choiceshock==2){
			do{
				//Choice of domestic country
				do {
					std::cout << blue << "Domestic country : 1/2/3/4" << def << std::endl;
					domcountry= choicecountry(country1, country2, country3);
				}while (domcountry==0);
				
				if(domcountry!=4){ //If the user has chosen to cancel don't offer any further choice
					//Choice of foreign country
					do {
						std::cout << blue << "Foreign country : 1/2/3/4" << def << std::endl;
						forcountry= choicecountry(country1, country2, country3);
					}while (forcountry==0);
				}
				 
				//Don't let the user choose the same countries
				if(domcountry==forcountry){
					std::cout << "Choose two different countries.";
				}
				
			}while(domcountry==forcountry);

			
			if(domcountry!=4 && forcountry!=4){ //If the user has chosen to cancel don't offer any further choice
				percentshock=percentageshock();
				switch(domcountry) {
					case 1: sim1 = country1;
						break;
					case 2: sim1 = country2;
						break;
					case 3: sim1 = country3;
						break;
				}
				switch(forcountry) {
					case 1: sim2 = country1;
						break;
					case 2: sim2 = country2;
						break;
					case 3: sim2 = country3;
						break;
				}
				ExchangeRateShockImpact(sim1, sim2, domcountry, forcountry, market1, market2, market3, percentshock, 					mynetwork);
			}
		}
		
		//Interest rate shock
		if (choiceshock == 3) {
			do {
				std::cout << blue << "In which country would this shock happen ? 1/2/3/4" << def << std::endl;
				countryshock= choicecountry(country1, country2, country3);
			}while (countryshock==0);
			
			if(countryshock!=4){ //If the user doesn't choose to cancel
				percentshock= percentageshock();
				switch(countryshock) {
					case 1: InterestRateShockImpact(country1, country2, country3, 1, 2, 3, market1, market2, 						market3, percentshock, mynetwork);
					break;
					case 2: InterestRateShockImpact(country2, country1, country3, 2, 1, 3, market1, market2, 						market3, percentshock, mynetwork);
					break;
					case 3: InterestRateShockImpact(country3, country1, country2, 3, 1, 3, market1, market2, 						market3, percentshock, mynetwork);
					break;
				}	
			}
				
			
		}

		//Inflation rate shock
		if(choiceshock==4) {		
			do {
				std::cout << blue << "In which country would this shock happen ? 1/2/3/4" << def << std::endl;
				countryshock= choicecountry(country1, country2, country3);
			}while (countryshock==0);	
			
			if(countryshock!=4){ //If the user doesn't choose to cancel
				percentshock= percentageshock();
			
				switch(countryshock) {
					case 1: InflationRateShockImpact(country1, country2, country3, 1, 2, 3, market1, market2, 						market3, percentshock, mynetwork);
					break;
					case 2: InflationRateShockImpact(country2, country1, country3, 2, 1, 3, market1, market2, 						market3, percentshock, mynetwork);
					break;
					case 3: InflationRateShockImpact(country3, country1, country2, 3, 1, 3, market1, market2, 						market3, percentshock, mynetwork);
				}
			}

		
		}
			
		//Production shock
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
			if(countryshock!=4 && mkt!=4){ //If the user has chosen to cancel don't offer any further choice
				percentshock=percentageshock();
			
				switch(mkt) {
					case 1: simm = market1;
						break;
					case 2: simm = market2;
						break;
					case 3: simm = market3;
						break;
				}
				
				switch(countryshock) {
					case 1: 
						ProductionShock(country1, country2, country3, 1, 2, 3, simm, percentshock, mynetwork);
						break;
					case 2: ProductionShock(country2, country1, country3, 2, 1, 3, simm, percentshock, mynetwork);
						break;
					case 3: ProductionShock(country3, country1, country2, 3, 2, 1, simm, percentshock, mynetwork);
							break;
				}
			}

		}
		
	}while(choiceshock!=1 && choiceshock!=2 && choiceshock!=3 && choiceshock!=4 && choiceshock!=5 && choiceshock!=6);

}
