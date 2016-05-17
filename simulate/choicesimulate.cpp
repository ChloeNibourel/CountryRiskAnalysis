#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"

//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

/// \file choicesimulate.cpp
/// \brief give the users the options for simulation

void choicesimulate() {
int choiceshock, choice2a;

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

	// CASES: type of shock

		if (choiceshock==1) {
			do {
				std::cout << blue << "Which country ? 1/2/3/4" << def << std::endl;
				choice2a= choicecountry(country1, country2, country3);
				if (choice2a==0) {
					std::cout << red << "Error : please choose 1, 2, 3 or 4" << def << std::endl;
				}
			}while (choice2a==0);
		

