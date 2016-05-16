#include <iostream>
#include "colors.h"

///\fn int choicecountry
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
		
	std::cin >> choice;
		
	if (choice==1 || choice ==2 || choice==3){
		return(choice);
	}
	else {return(0);}

}