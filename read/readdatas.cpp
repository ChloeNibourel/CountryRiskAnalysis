#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/readdata.h"

/// \file readdatas.cpp
/// \brief show datas available for a given country

/// function read() : choose a country to have its
/// GDP, Total export, Export to other countries (total and by fields)
/// Countries: Canada, USA, Mexico
/// fields: Mineral fuels, Food, Machinery and transport equipments


///\fn read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3)
///\brief lets the user chose what data he wants to read
void read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3) {
	int choice1, ctry, mkt;

	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
	do {
		std::cout << blue << "Are you interested in datas about a market or a country ? 1/2" << std::endl;
		std::cout << blue << " 1. Market" << std::endl;
		std::cout << blue << " 2. Country" << std::endl;
		std::cout << blue << " 3. Cancel" << std::endl;
		std::cin>> choice1;
		
		if(choice1==1){
			do{
				//chose a market	
				std::cout << blue << "Which market are you interested in ? 1/2/3" << std::endl;
				std::cout << blue << " 1. Food" << std::endl;
				std::cout << blue << " 2. Machinery and transport equipment" << std::endl;
				std::cout << blue << " 3. Fuel" << std::endl;
				std::cout << blue << " 4. Cancel" << std::endl;
			
				std::cin>> mkt;
				
				if(mkt==1){
					//readmarket(market1);
				}
				else if (mkt==2){
					//readmarket(market2);
				}
				else if (mkt==3){
					//readmarket(market3);
				}
				else if (mkt!=4){
					std::cout << red << "Error: choose 1, 2, 3 or 4"<< std::endl;
				}
			}while(mkt!=1 && mkt!=2 && mkt!=3 && mkt!=4);
			//If the user makes an invalid choice he can choose again
		}

		else if(choice1==2){
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
	
		else if (choice1!=3){
			std::cout << red << "Error: choose 1, 2 or 3"<< std::endl;
		}
	}while (choice1!=1 && choice1!=2 && choice1!=3);
	//If the user makes an invalid choice he can choose again
}


void readcountry(country* mycountry){
	std::cout<< std::endl;
	std::cout << "Country : " << (*mycountry).name << std::endl;
	std::cout << "GDP : " << (*mycountry).income << " Billion USD" << std::endl;
	std::cout << "Elasticity of importation : " << (*mycountry).elasticityimports << std::endl;
	std::cout << "Elasticity of exportation : " << (*mycountry).elasticityexports << std::endl;
	std::cout << "Total imports : " << (*mycountry).totalimports << " Billion USD" << std::endl;
	std::cout << "Total exports : " << (*mycountry).totalexports << " Billion USD" << std::endl;
	std::cout<< std::endl;
	
}


