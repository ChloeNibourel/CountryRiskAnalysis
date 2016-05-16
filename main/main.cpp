/// \file main.cpp
/// \brief Choices: 1.Read 2.Update 3.Simulate 4.Exit
///
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

///\fn main
///\brief creates variables for countries and markets, and asks the user what he wants to do
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
		std::cout << blue << "Welcome, what do you want to do ? 1/2/3/4"<<std::endl;
		std::cout << blue << " 1. Read datas used"<<std::endl;
		std::cout << blue << " 2. Update datas used"<<std::endl;
		std::cout << blue << " 3. Simulate a shock"<<std::endl;	
		std::cout << blue << " 4. Exit the program"<<std::endl;

		std::cin>>choice; /// \bug when user does not enter an integer in the choices 

// switch: send the choice to the good function
	switch (choice) {
			case 1: read(&usa, &canada, &mexico, &food, &machinery, &fuel, &nafta);
				break;
			/*case 2: update();
				break;
			case 3: simulate();
				break;*/
			case 4: 
				break;
			default: std::cout << red << "Error, enter 1, 2, 3 or 4" <<std::endl;
		}
		
	} while (choice!=4);
}


