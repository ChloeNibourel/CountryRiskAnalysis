#include <iostream>
#include "colors.h"

/// \file updatedatas.cpp
/// \brief modify header files and excel file with new data

/// Choose the data you want to update and then change it in the different files 

void update() {
	int choice1;
	int choice2a;
	int choice2b;
	int choice3a;
	int choice3b;

//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);


// Choose which kind of datas you want to update 

	std::cout << blue << "What do you want to update ? 1/2" << std::endl;
	std::cout << blue << " 1. A country data : GDP, Total export, Elasticities" << std::endl;
	std::cout << blue << " 2. A market data : export between 2 countries in a specific field" 			<< std::endl;

	std::cin >> choice1;


// Update Country data

	if (choice1==1) { 
	// Which country
		std::cout << blue << "Which country ? 1/2/3" << std::endl;
		std::cout << blue << " 1. Canada" << std::endl;
		std::cout << blue << " 2. United States" << std::endl;
		std::cout << blue << " 3. Mexico" << std::endl;

		std::cin >> choice2a;

	// Which data
		std::cout << blue << "Which data ? 1/2/3" << std::endl;
		std::cout << blue << " 1. GDP" << std::endl;
		std::cout << blue << " 2. Total Export" << std::endl;
		std::cout << blue << " 3. Elasticity of Exportation" << std::endl;
		std::cout << blue << " 4. Elasticity of Importation" << std::endl;

		std::cin >> choice2b;

	// All cases

	//Canada
		if (choice2a=1 && choice2b=1) { //update GDP Canada 
		}
		else if (choice2a=1 && choice2b=2) { //update Total export Canada
		}
		else if (choice2a=1 && choice2b=3) { //update exp elast Canada
		}
		else if (choice2a=1 && choice2b=4) { //update imp elast Canada
		}

	//USA
		else if (choice2a=2 && choice2b=1) { //update GDP US
		}
		else if (choice2a=2 && choice2b=2) { //update Total export US
		}
		else if (choice2a=2 && choice2b=3) { //update exp elas US
		}
		else if (choice2a=2 && choice2b=4) { //update imp elas US
		}

	//Mexico
		else if (choice2a=3 && choice2b=1) { //update GDP Mexico
		}
		else if (choice2a=3 && choice2b=2) { //update Total export Mexico
		}
		else if (choice2a=3 && choice2b=3) { //update exp elas Mexico
		}
		else if (choice2a=3 && choice2b=4) { //update imp elas Mexico
		}

	//Error
		else {
			std::cout << red << "Error: enter 1, 2 or 3 and 1, 2, 3 or 4" <<std::endl; 
		}

	}


// Update Market data
	else if (choice1==2) {

	//Which field
		std::cout << blue << "Which market ? 1/2/3" << std::endl;
		std::cout << blue << " 1. Mineral Fuels" << std::endl;
		std::cout << blue << " 2. Food" << std::endl;
		std::cout << blue << " 3. Machinery and transport equipment" << std::endl;
		std::cout << blue << " 4. Total" << std::endl;

		std::cin >> choice3a;

	//Export between which countries
		std::cout << blue << " Which countries are exchanging ? 1/2/3/4/5/6" << std::endl;
		std::cout << blue << " 1. Exportations from Canada to the US" << std::endl;
		std::cout << blue << " 2. Exportations from Canada to Mexico" << std::endl;
		std::cout << blue << " 3. Exportations from the US to Canada " << std::endl;
		std::cout << blue << " 4. Exportations from the US to Mexico" << std::endl;
		std::cout << blue << " 5. Exportations from Mexico to Canada" << std::endl;
		std::cout << blue << " 6. Exportations from Mexico to the US" << std::endl;

		std::cin >> choice3b;

	// All cases

	//Mineral fuels
		if (choice3a=1 && choice3b=1) {
			//update fuels exp from Can to US
		}
		else if (choice3a=1 && choice3b=2) {
			//update fuels exp from Can to Mex
		}
		else if (choice3a=1 && choice3b=3) {
			//update fuels exp from US to Can
		}
		else if (choice3a=1 && choice3b=4) {
			//update fuels exp from US to Mex
		}
		else if (choice3a=1 && choice3b=5) {
			//update fuels exp from Mex to Can
		}
		else if (choice3a=1 && choice3b=6) {
			//update fuels exp from Mex to US
		}

	//food
		else if (choice3a=2 && choice3b=1) {
			//update food exp from Can to US
		}
		else if (choice3a=2 && choice3b=2) {
			//update food exp from Can to Mex
		}
		else if (choice3a=2 && choice3b=3) {
			//update food exp from US to Can
		}
		else if (choice3a=2 && choice3b=4) {
			//update food exp from US to Mex
		}
		else if (choice3a=2 && choice3b=5) {
			//update food exp from Mex to Can
		}
		else if (choice3a=2 && choice3b=6) {
			//update food exp from Mex to US
		}

	//Machinery and transport equipment
		else if (choice3a=3 && choice3b=1) {
			//update mach exp from Can to US
		}
		else if (choice3a=3 && choice3b=2) {
			//update mach exp from Can to Mex
		}
		else if (choice3a=3 && choice3b=3) {
			//update mach exp from US to Can
		}
		else if (choice3a=3 && choice3b=4) {
			//update mach exp from US to Mex
		}
		else if (choice3a=3 && choice3b=5) {
			//update mach exp from Mex to Can
		}
		else if (choice3a=3 && choice3b=6) {
			//update mach exp from Mex to US
		}

	//Total exportations
		else if (choice3a=4 && choice3b=1) {
			//update total exp from Can to US
		}
		else if (choice3a=4 && choice3b=2) {
			//update total exp from Can to Mex
		}
		else if (choice3a=4 && choice3b=3) {
			//update total exp from US to Can
		}
		else if (choice3a=4 && choice3b=4) {
			//update total exp from US to Mex
		}
		else if (choice3a=4 && choice3b=5) {
			//update total exp from Mex to Can
		}
		else if (choice3a=4 && choice3b=6) {
			//update total exp from Mex to US
		}


	//Error
		else {
			std::cout << red << "Error: Enter 1,2,3 or 4 and 1,2,3,4,5 or 6" << std::endl;
		}
}


//Error in type of update
	else {
		std::cout << red << "Error: Enter 1 or 2" << std::endl;
}


