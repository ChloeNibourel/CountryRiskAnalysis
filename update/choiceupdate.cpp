#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/updatedata.h"

void updatechoice(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork) {
	int choice1, choice2a, choice2b, choice3a, choice3b, choice3c;
	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

	do{
		// Choose which kind of datas you want to update 
		std::cout << blue << "What do you want to update ? 1/2/3/4" << std::endl;
		std::cout << blue << " 1. A country data : GDP, Total export, Elasticities" << std::endl;
		std::cout << blue << " 2. A market data : export between 2 countries in a specific field"<< std::endl;
		std::cout << blue << " 3. Total exports between two countries"<< std::endl;
		std::cout << blue << " 4. Cancel"<< std::endl;
		
		std::cin >> choice1;
		
		//To update data about a country
		if (choice1==1) {
			do {
				std::cout << blue << "Which country do you want to update ? 1/2/3" << std::endl;
				choice2a= choicecountry(country1, country2, country3);
				if (choice2a==0) {
					std::cout << blue << "Error : please choose 1, 2, or 3" << std::endl;
				}
			}while (choice2a==0);
				
			do {
				std::cout << blue << "Which data do you want to update ? 1/2/3/4/5/6" << std::endl;
				std::cout << blue << " 1. GDP" << std::endl;
				std::cout << blue << " 2. Total Imports" << std::endl;
				std::cout << blue << " 3. Total Exports" << std::endl;
				std::cout << blue << " 4. Elasticity of Importation" << std::endl;
				std::cout << blue << " 5. Elasticity of Exportation" << std::endl;
				std::cout << blue << " 6. A" << std::endl;

				std::cin >> choice2b;
				
				if(choice2b==1 && choice2b==2 && choice2b==3 && choice2b!=4 && choice2b!=5 && choice2b!=6){
					std::cout << red << "Error : please choose 1, 2, 3, 4, 5 or 6" << std::endl;
				}
			}while (choice2b!=1 && choice2b!=2 && choice2b!=3 && choice2b!=4&& choice2b!=5 && choice2b!=6);
			
			//Calls function updatecountry with different input (usa/canada/mexico) depending on the user's choice
			if (choice2a==1){
				updatecountry(country1, 1, choice2b);
			}
			
			else if (choice2a==2){
				updatecountry(country2, 2, choice2b);
			}
			
			else if (choice2a==3){
				updatecountry(country3, 3, choice2b);
			}
		}	
		
		//To update data about a market
		else if (choice1==2){
			
			do{
				std::cout << blue << "Which market ? 1/2/3/4" << std::endl;
				std::cout << blue << " 1. Food" << std::endl;
				std::cout << blue << " 2. Machinery and transport equipment" << std::endl;
				std::cout << blue << " 3. Mineral fuels" << std::endl;
			
				std::cin>> choice3a;
					
				if (choice3a !=1 && choice3a!=2 && choice3a!=3){
					std::cout << red << "Error : please choose 1, 2 or 3" << std::endl;
				}
			} while (choice3a !=1 && choice3a!=2 && choice3a!=3);	
			
			do {
				std::cout << blue << "Update exportations from : 1/2/3" << std::endl;
				choice3b= choicecountry(country1, country2, country3);

				if (choice3b==0) {
					std::cout << red << "Error : please choose 1, 2, or 3" << std::endl;
				}
			}while (choice3b==0);
				
			do {
				std::cout << blue << "Update exportations to : 1/2/3" << std::endl;
				choice3c= choicecountry(country1, country2, country3);
				if (choice3c==0) {
					std::cout << red << "Error : please choose 1, 2, or 3" << std::endl;
				}
			}while (choice3c==0);
			
		
			//Case where user chooses same country as origin and destination of exports
			if (choice3b == choice3c) {
				std::cout << red << "Error : please pick two different countries" << std::endl;
			}
			//Call the updatemarket function with different arguments depending on the user's choices
			else if (choice3a==1){
				updatemarket(market1, choice3b, choice3c, choice3a);
			}
					 
			else if (choice3a==2){
				updatemarket(market2, choice3b, choice3c, choice3a);
			}
			
			else if (choice3a==1){
				updatemarket(market3, choice3b, choice3c, choice3a);
			}
		}
		
		else if (choice1==3){
			std::cout << "Pas encore fait désolée" << std::endl;
		}
		
		else if (choice1!=4) {
			std::cout << red <<  "Error : please choose 1, 2, 3 or 4" << std::endl;
		}
		
	}while(choice1!=1 && choice1!=2 && choice1!=3 && choice1!=4);
}


