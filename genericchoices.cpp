///\file genericchoices.cpp
///\brief includes functions that let the user choose between options, for choices which are made repeateadly over the program

#include <iostream>
#include "headers/colors.h"
#include "headers/country.h"

///\func int choicecountry
///\brief general function that lets you choose between the 3 coutries
int choicecountry(country* country1, country* country2, country* country3){
	//give the options

	//colors
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);


	int choice;
	std::cout << blue << " 1. " << (*country1).name << std::endl;
	std::cout << " 2. "<< (*country2).name << std::endl;
	std::cout << " 3. "<< (*country3).name << std::endl;
	std::cout << " 4. Cancel" << std::endl;
		
	std::cin >> choice;
	
	
	if(std::cin.fail() ){ //if type wasn't right
        std::cin.clear(); //clear stream
        std::cin.ignore(); //ignore left over data
		choice=0;
	}
	
	if (choice==1 || choice ==2 || choice==3 || choice==4){
		return(choice);
	}
	else {return(0);}

}
