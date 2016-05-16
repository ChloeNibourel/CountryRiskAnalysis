#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/readdata.h"

/// \file choiceread.cpp
/// \Lets the user chose what type of data he wants to read

///\fn read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3)
///\brief lets the user chose what data he wants to read
void read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork) {
	int choice, ctry, mkt;

	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
	do {
		std::cout << blue << "Are you interested in datas about a market or a country ? 1/2" << std::endl;
		std::cout << blue << " 1. Market" << std::endl;
		std::cout << blue << " 2. Country" << std::endl;
		std::cout << blue << " 3. Total exports matrix" << std::endl;
		std::cout << blue << " 4. Cancel" << std::endl;
		std::cin>> choice;
		
		if(choice==1){
			do{
				//chose a market	
				std::cout << blue << "Which market are you interested in ? 1/2/3" << std::endl;
				std::cout << blue << " 1. Food" << std::endl;
				std::cout << blue << " 2. Machinery and transport equipment" << std::endl;
				std::cout << blue << " 3. Fuel" << std::endl;
				std::cout << blue << " 4. Cancel" << std::endl;
			
				std::cin>> mkt;
				
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
					std::cout << red << "Error: choose 1, 2, 3 or 4"<< std::endl;
				}
			}while(mkt!=1 && mkt!=2 && mkt!=3 && mkt!=4);
			//If the user makes an invalid choice he can choose again
		}

		else if(choice==2){
			do{
				//chose a country	
				std::cout << blue << "Which country are you interested in ? 1/2/3" << std::endl;
				std::cout << blue << " 1. United States" << std::endl;
				std::cout << blue << " 2. Canada" << std::endl;
				std::cout << blue << " 3. Mexico" << std::endl;
				std::cout << blue << " 4. Cancel" << std::endl;

				std::cin>> ctry;
			
				if(ctry==1){
					readcountry(country1);
				}
				else if (ctry==2){
					readcountry(country2);
				}
				else if (ctry==3){
					readcountry(country3);
				}
				else if (ctry!=4){
					std::cout << red << "Error: choose 1, 2, 3 or 4"<< std::endl;
				}
			} while(ctry!=1 && ctry !=2 && ctry!=3 && ctry!=4);
			//If the user makes an invalid choice he can choose again
			
		}	
	
		else if (choice==3){
			readexports(mynetwork);
		}
		
		else if (choice!=4){
			std::cout << red << "Error: choose 1, 2 or 3"<< std::endl;
		}
	}while (choice!=1 && choice!=2 && choice!=3 && choice!=4); ///\bug When someone enters something else than an int the program goes in infinite loops
	//If the user makes an invalid choice he can choose again
}
