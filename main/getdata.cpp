///\file getdata.cpp
///\gets data about countrys from the excel (.xlsx) file and attributes the values to country classes

#include <iostream>
#include "libxl.h"
#include "../headers/getdata.h"

int main (){ // We will need to change the name of the functions, only calling it main to test wether it works.

	libxl::Book* book= xlCreateXMLBook();

	if((*book).load("../data.xlsx")){
		libxl::Sheet* sheet0 = (*book).getSheet(0);
		libxl::Sheet* sheet1 = (*book).getSheet(1);
		if(sheet0 && sheet1){
			//getmarket(book, sheet0);
			getcountry(book, sheet1);
		}
		else {
			std::cout<<"Error when loading the first sheet from the data file"<<std::endl;
		}
	}
	else {
		std::cout<<"Error when loading the data file"<<std::endl;
	}

	
	
}
/*
void getmarket(libxl::Book* book, libxl::Sheet* sheet){
	for (int j=1; j<=3; ++j){
		switch(j){
			case 1: std::cout<< "USA" << std::end; break;
			case 2: std::cout<< "Canada" << std::end; break;
			case 3: std::cout<< "Mexico" << std::end; break;
		}
			
		for(int i=2; i<=3; ++i){
			std::cout<< (*sheet).readNum(i, j) <<std::endl;
			///\bug here I'm printing on the terminal the values for the country, in the future we'll give those values to the class country
		}
	std::cout<<std::endl;
	}

} */

void getcountry(libxl::Book* book, libxl::Sheet* sheet){
	
	for (int j=1; j<=3; ++j){
		switch(j){
			case 1: std::cout<< "USA" << std::endl; break;
			case 2: std::cout<< "Canada" << std::endl; break;
			case 3: std::cout<< "Mexico" << std::endl; break;
		}
		
		for(int i=2; i<=3; ++i){
			std::cout<< (*sheet).readNum(i, j) <<std::endl;
			///\bug here I'm printing on the terminal the values for the country, in the future we'll give those values to the class country
		}
	std::cout<<std::endl;
	}

} 