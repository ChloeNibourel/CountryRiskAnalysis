#include <iostream>

/// \file updatedatas.cpp
/// \brief modify header files and excel file with new data

void update() {
	int choice1;
	int choice2a;
	int choice2b;
	int choice3a;
	int choice3b;

// Choose which kind of datas you want to update 

	std::cout << "Do you want to update : 1/2" << std::endl;
	std::cout << " 1. A country data : GDP, Total export, Elasticities" << std::endl;
	std::cout << " 2. A market data : export between 2 countries in a specific field" << std::endl;

	std::cin >> choice1;

// Update Country data
	// Which country

	if (choice1==1) { 
		std::cout << "Which country ? 1/2/3" << std::endl;
		std::cout << " 1. Canada" << std::endl;
		std::cout << " 2. United States" << std::endl;
		std::cout << " 3. Mexico" << std::endl;

		std::cin >> choice2a;

	// Which data
		std::cout << "Which data ? 1/2/3" << std::endl;
		std::cout << " 1. GDP" << std::endl;
		std::cout << " 2. Total Export" << std::endl;
		std::cout << " 3. Elasticity of Exportation" << std::endl;
		std::cout << " 4. Elasticity of Importation" << std::endl;

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
			std::cout << "Error: enter 1/2/3 and 1/2/3/4" <<std::endl; 
		}

	}

// Update Market data
	else if (choice1==2) {

}


