#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/readdata.h"
#include "../headers/choices.h"

/// \file choiceread.cpp
/// \brief lets the user choose what type of data he wants to read


void read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork) {
	int choice, ctry, mkt;

	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
	do {
		std::cout << blue << "Are you interested in datas about a market or a country ? 1/2/3/4" << std::endl;
		std::cout << " 1. Market" << std::endl;
		std::cout << " 2. Country" << std::endl;
		std::cout << " 3. Total exports matrix" << std::endl;
		std::cout << " 4. Cancel" << def << std::endl;
		std::cin>> choice;
		if(std::cin.fail() ){ //if type wasn't right
            std::cin.clear(); //clear stream
            std::cin.ignore(); //ignore left over data
			choice=0; //set value of choice to zero so that we stay in the initial "do-while" loop so that the user gets to choose again
		}
		
		if(choice==1){
			do{
				//chose a market	
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
				
				if(mkt==1){
					readmarket(market1);
				}
				else if (mkt==2){
					readmarket(market2);
				}
				else if (mkt==3){
					readmarket(market3);
				}
				else if (mkt!=4){
					std::cout << red << "Error: please enter 1, 2, 3 or 4"<< def << std::endl;
				}
			}while(mkt!=1 && mkt!=2 && mkt!=3 && mkt!=4);
			//If the user makes an invalid choice he can choose again
		}

		else if(choice==2){
			do{
				//chose a country	
				std::cout << blue << "Which country are you interested in ? 1/2/3/4" << std::endl;
				ctry=choicecountry(country1, country2, country3);
	
				if(ctry==1){
					readcountry(country1);
				}
				else if (ctry==2){
					readcountry(country2);
				}
				else if (ctry==3){
					readcountry(country3);
				}
			} while(ctry!=1 && ctry !=2 && ctry!=3 && ctry!=4);
			//If the user makes an invalid choice he can choose again
			
		}	
	
		else if (choice==3){
			readexports(mynetwork);
		}
		
		else if (choice!=4){
			std::cout << red << "Error: please enter 1, 2, 3 or 4"<< def << std::endl;
		}
	}while (choice!=1 && choice!=2 && choice!=3 && choice!=4); 
	//If the user makes an invalid choice he can choose again
}
