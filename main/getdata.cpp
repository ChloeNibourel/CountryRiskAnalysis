///\file getdata.cpp
///\gets data about countrys from the excel (.xlsx) file and attributes the values to country classes

#include <iostream>
#include "libxl.h"
#include "../headers/getdata.h"
#include "../headers/country.h"

void getdata (country* country1, country* country2, country* country3){ // We will need to change the name of the functions, only calling it main to test wether it works.

	libxl::Book* book= xlCreateXMLBook();

	if((*book).load("../data.xlsx")){
		libxl::Sheet* sheet0 = (*book).getSheet(0);
		libxl::Sheet* sheet1 = (*book).getSheet(1);
		if(sheet0 && sheet1){
			//getmarket(book, sheet0);
			getcountry(book, sheet1, country1);
			getcountry(book, sheet1, country2);
			getcountry(book, sheet1, country3);
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


///\fcn takes an excel file and a country as input, and attributes data from this excel file to that country
void getcountry(libxl::Book* book, libxl::Sheet* sheet, country* mycountry){
	int j;
	if (&mycountry == usa){
		j=1;
		(&mycountry).name="USA";
	}
	else if (&mycountry==canada){
		j=2;
		(&mycountry).name="Canada";
	}
	else if (&mycountry==mexico){
		j=3;
		(&mycountry).name="Mexico";
	}
	
	int i=3;
	(&mycountry).name= (*sheet).readNum(i, j);
	
	
	for (int i=1; j<=3; ++j){
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