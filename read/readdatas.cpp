///\file readdatas.cpp
///\brief contains all functions that read data from excel file

#include <iostream>
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/readdata.h"


///\fn readcountry(country* mycountry)
///\brief function shows to the user all the datas from the country he chose to see
void readcountry(country* mycountry){
	std::cout << std::endl;
	std::cout << "Datas we use for " << (*mycountry).name << std::endl;
	std::cout << "GDP : " << (*mycountry).income << " Billion USD" << std::endl;
	std::cout << "Elasticity of importation : " << (*mycountry).elasticityimports << std::endl;
	std::cout << "Elasticity of exportation : " << (*mycountry).elasticityexports << std::endl;
	std::cout << "Total imports : " << (*mycountry).totalimports << " Billion USD" << std::endl;
	std::cout << "Total exports : " << (*mycountry).totalexports << " Billion USD" << std::endl;
	std::cout << std::endl;	
}

///\fn readmarket
///\brief function shows to the user all the data from the country he chose to see
void readmarket(market* mymarket){
	std::cout << std::endl;
	std::cout << "Datas for the market of " << (*mymarket).good << std::endl;
	std::cout << std::endl;
	
	//Tabulation used to display datas in matrix form
	std::cout << "Amounts exchanged in billion USD " << std::endl;
	std::cout << "\t \t FROM:" << std::endl;
	std::cout << "\t USA \t Canada  Mexico" << std::endl;
	std::cout << "TO:" << std::endl;
	for (int i=0; i<3; ++i){
		//Switch to write a different country name on each line of the matrix
		switch(i){
			case 0: std::cout << "USA \t"; break;
			case 1: std::cout << "Canada \t"; break;
			case 2: std::cout << "Mexico \t"; break;
		}
		for (int j=0; j<3; ++j){
			std::cout << (*mymarket).exchange[i][j] << "\t";
		}
		std::cout << std::endl;	
	}

}

///\fn
///\brief function shows the user the matrix of total exports between countries
void readexports (exportsnetwork* mynetwork){
	std::cout << std::endl;
	std::cout << "Total exports between the countries " << std::endl;
	std::cout << "\t \t FROM:" << std::endl;
	std::cout << "\t USA \t Canada  Mexico" << std::endl;
	std::cout << "TO:" << std::endl;
	for (int i=0; i<3; ++i){
		//Switch to write a different country name on each line of the matrix
		switch(i){
			case 0: std::cout << "USA \t"; break;
			case 1: std::cout << "Canada \t"; break;
			case 2: std::cout << "Mexico \t"; break;
		}
		for (int j=0; j<3; ++j){
			std::cout << (*mynetwork).exports[i][j] << "\t";
		}
		std::cout << std::endl;	
	}
}
		 
		  

