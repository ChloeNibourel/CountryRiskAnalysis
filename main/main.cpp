/// \file main.cpp
/// \brief Choices: 1.Read 2.Update 3.Simulate 4.Exit

/// User have 4 choices opening the program
/// 1.Read some datas used to simulate
/// 2.Update some datas to improve the simulation
/// 3.Simulate different shocks 
/// 4.Exit the program

#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/getdata.h"
#include "../headers/readdata.h"
#include "../headers/updatedata.h"
#include "../headers/simulate.h"

/// \fn main
/// \brief creates variables for countries and markets, and asks the user what he wants to do
int main() {

	//Getting data from the Excel file into type country variables usa, canada, mexico and type market variables food, machinery, fuel
	country usa;
	country canada;
	country mexico;
	
	market food;
	market machinery;
	market fuel;
	
	exportsnetwork nafta;
	
	getdata (&usa, &canada, &mexico, &food, &machinery, &fuel, &nafta);
	
	
	int choice; 

//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);


// do while: loop for the options of the program
	do {
		std::cout << std::endl;
		std::cout << blue << "Welcome, what do you want to do ? 1/2/3/4"<<std::endl;
		std::cout << " 1. Read datas"<<std::endl;
		std::cout << " 2. Update datas"<<std::endl;
		std::cout << " 3. Simulate a shock"<<std::endl;	
		std::cout << " 4. Exit the program"<< def << std::endl;

		std::cin>>choice;

		if(std::cin.fail() ){ //if type wasn't right
          	  std::cin.clear(); //clear stream
         	  std::cin.ignore(); //ignore left over data
			choice=0;
		}

// switch: send the choice to the good function
	switch (choice) {
			case 1: read(&usa, &canada, &mexico, &food, &machinery, &fuel, &nafta);
				break;
			case 2: updatechoice(&usa, &canada, &mexico, &food, &machinery, &fuel, &nafta);
				break;
			case 3: choicesimulate(&usa, &canada, &mexico, &food, &machinery, &fuel, &nafta);
				break;
			case 4: 
				break;
			default: std::cout << red << "Error: please enter 1, 2, 3 or 4" << def << std::endl;
		}
		
	} while (choice!=4);
}


