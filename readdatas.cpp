#include <iostream>
#include <colors.h>

/// \file readdatas.cpp
/// \brief show datas available for a given country

/// function read() : choose a country to have its
/// GDP, Total export, Export to other countries (total and by fields)
/// Countries: Canada, USA, Mexico
/// fields: Mineral fuels, Food, Machinery and transport equipments


void read() {
	int choice;

//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

//chose a country
	
	std::cout << blue << "Which country are you interested in ? 1/2/3" << std::endl;
	std::cout << blue << " 1. Canada" << std::endl;
	std::cout << blue << " 2. United States" << std::endl;
	std::cout << blue << " 3. Mexico" << std::endl;

	std::cin>> choice;

// Canada
	if (choice==1) {
		std::cout << "GDP of Canada is " << can.gdp << " Billion USD"<< std::endl;
		std::cout << "Total export of Canada is " << can.exp << " Billion USD"<< std::endl;
		std::cout << "In Canada, elasticity of exportation is " << can.elexp << " and 				elasticity of importation is " << can.elimp << std::endl;

		std::cout << std::endl;

		std::cout << "Canada exports " << ????? << " Billion USD to the United States"<< 				std::endl;
		std::cout << "  which include: " << std::endl;
		std::cout << "   " << ????? << " Billion USD of mineral fuels"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of food"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of machinery and transport 			equipments"<< std::endl;

		std::cout << std::endl;

		std::cout << "Canada exports " << ????? << " Billion USD to Mexico"<< std::endl;
		std::cout << "  which include: " << std::endl;
		std::cout << "   " << ????? << " Billion USD of mineral fuels"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of food"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of machinery and transport 			equipments"<< std::endl;
	}

//USA
	else if (choice==2) {
		std::cout << "GDP of the US is " << usa.gdp << " Billion USD"<< std::endl;
		std::cout << "Total export of the US is " << usa.exp << " Billion USD"<< std::endl;
		std::cout << "In the US, elasticity of exportation is " << usa.elexp << " and 				elasticity of importation is " << usa.elimp << std::endl;

		std::cout << std::endl;

		std::cout << "The US exports " << ????? << " Billion USD to Canada"<< std::endl;
		std::cout << "  which include: " << std::endl;
		std::cout << "   " << ????? << " Billion USD of mineral fuels"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of food"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of machinery and transport 			equipments"<< std::endl;

		std::cout << std::endl;

		std::cout << "The US exports " << ????? << " Billion USD to Mexico"<< std::endl;
		std::cout << "  which include: " << std::endl;
		std::cout << "   " << ????? << " Billion USD of mineral fuels"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of food"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of machinery and transport 			equipments"<< std::endl;
	}

//Mexico
	else if (choice==3) {
		std::cout << "GDP of Mexico is " << mex.gdp << " Billion USD"<< std::endl;
		std::cout << "Total export of Mexico is " << mex.exp << " Billion USD"<< std::endl;
		std::cout << "In Mexico, elasticity of exportation is " << mex.elexp << " and 				elasticity of importation is " << mex.elimp << std::endl;

		std::cout << std::endl;

		std::cout << "Mexico exports " << ????? << " Billion USD to Canada"<< std::endl;
		std::cout << "  which include: " << std::endl;
		std::cout << "   " << ????? << " Billion USD of mineral fuels"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of food"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of machinery and transport 			equipments"<< std::endl;

		std::cout << std::endl;

		std::cout << "Mexico exports " << ????? << " Billion USD to the United States"<< 				std::endl;
		std::cout << "  which include: " << std::endl;
		std::cout << "   " << ????? << " Billion USD of mineral fuels"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of food"<< std::endl;
		std::cout << "   " << ????? << " Billion USD of machinery and transport 			equipments"<< std::endl;
	}

//Wrong answer
	else { 
		std::cout << red << "Error: choose 1, 2 or 3"<< std::endl;
	}
}
