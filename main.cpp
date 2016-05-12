/// \file main.cpp
/// \brief Choices: 1.Read 2.Update 3.Simulate 4.Exit
/// User have 4 choices opening the program
/// 1.Read some datas used to simulate
/// 2.Update some datas to improve the simulation
/// 3.Simulate different shocks 
/// 4.Exit the program

#include <iostream>

int main() {
	int choice; /// \bug if not int
	char exit;
/// do while: loop for the options of the program
	do {
		std::cout << "Welcome, what do you want to do ? 1/2/3/4"<<std::endl;
		std::cout << " 1. Read datas used"<<std::endl;
		std::cout << " 2. Update datas used"<<std::endl;
		std::cout << " 3. Simulate a shock"<<std::endl;	
		std::cout << " 4. Exit the program"<<std::endl;

		std::cin>>choice;
/// swtich: send the choice to the good function
		switch (choice) {
			case 1: read();
				break;
			case 2: update();
				break;
			case 3: simulate();
				break;
			case 4: break;
			default: std::cout<<"Error, enter 1, 2, 3 or 4" <<std::endl;
		}
///if: ask if want to do something else!!!	
	} while (choice!=4);
}


