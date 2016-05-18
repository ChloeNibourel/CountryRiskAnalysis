/// \file genericchoices.cpp
/// \brief includes functions that let the user choose between options, for choices which are made repeateadly over the program

#include <iostream>
#include "headers/colors.h"
#include "headers/country.h"


	//colors
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);


int choicecountry(country* country1, country* country2, country* country3){
	//give the options
	int choice;
	std::cout << blue << " 1. " << (*country1).name << std::endl;
	std::cout << " 2. "<< (*country2).name << std::endl;
	std::cout << " 3. "<< (*country3).name << std::endl;
	std::cout << " 4. Cancel" << def << std::endl;
		
	std::cin >> choice;
	
	
	if(std::cin.fail() ){ //if type wasn't right
        std::cin.clear(); //clear stream
        std::cin.ignore(); //ignore left over data
		choice=0;
	}
	
	if (choice==1 || choice ==2 || choice==3 || choice==4){
		return(choice);
	}

	else {
		std::cout << red << "Error : please choose 1, 2, 3 or 4" << def << std::endl;
		return(0);
	}

}

double percentageshock(){
	double shock;
	bool error;
	do{
		error=0;
		std::cout << blue << "Enter + or - and the percentage of shock :"<< std::endl << "Example : if you have a 3 percent decrease, enter -3" <<def << std::endl;
		std::cin >> shock;

		if(std::cin.fail() ){ //if type wasn't right
    	    		std::cin.clear(); //clear stream
    	    		std::cin.ignore(); //ignore left over data
			std::cout<<red << "Error : enter a numerical value" << def << std::endl;
			error=1;
		}
	}while(error==1);	
	return(shock);
	
}
