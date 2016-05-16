#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/updatedata.h"

void updatechoice(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork) {
	int choice1;
	int choice2a;
	int choice2b;
	int choice3a;
	int choice3b;

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
		
		if (choice1==1) {
			do {
				std::cout << blue << "Which country do you want to update ? 1/2/3/4" << std::endl;
				choice2a= choicecountry();
				if (choice2a==0) {
					std::cout << blue << "Error : please choose 1, 2, 3 or 4" << std::endl;
				}
			}while (choice2a==0);
				
			do {
				std::cout << blue << "Which data do you want to update ? 1/2/3/4/5/6/7" << std::endl;
				std::cout << blue << " 1. GDP" << std::endl;
				std::cout << blue << " 2. Total Imports" << std::endl;
				std::cout << blue << " 3. Total Exports" << std::endl;
				std::cout << blue << " 4. Elasticity of Importation" << std::endl;
				std::cout << blue << " 5. Elasticity of Exportation" << std::endl;
				std::cout << blue << " 6. A" << std::endl;
				std::cout << blue << " 7. Cancel" << std::endl;

				std::cin >> choice2b;
				
				if(choice2b==1 && choice2b==2 && choice2b==3 && choice2b!=4 && choice2b!=5 && choice2b!=6 && choice2b!=7){
					std::cout << blue << "Error : please choose 1, 2, 3, 4 or 5" << std::endl;
				}
			}while (choice2b==1 && choice2b==2 && choice2b==3 && choice2b!=4&& choice2b!=5);
			
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
		
	}while(choice1!=1 && choice1!=2 && choice1!=3 && choice1!=4);
}

///\fn int choicecountry
///\brief general function that lets you choose between the 3 coutries
int choicecountry(){
	//give the options
    Color::Modifier blue(Color::FG_BLUE);
	
	int choice;
	std::cout << blue << " 1. United States" << std::endl;
	std::cout << blue << " 2. Canada"<< std::endl;
	std::cout << blue << " 3. Mexico"<< std::endl;
	std::cout << blue << " 4. Cancel"<< std::endl;
		
	std::cin >> choice;
		
	if (choice==1 || choice ==2 || choice==3 || choice ==4){
		return(choice);
	}
	else {return(0);}

}