///\file getdata.cpp
///\brief gets data about countrys from the excel (.xlsx) file and attributes the values to country classes

#include <iostream>
#include "libxl.h"
#include "../headers/country.h"
#include "../headers/getdata.h"

///\fn getdata
///\brief loads an excel file and calls functions to read from it
void getdata (country* country1, country* country2, country* country3){

	libxl::Book* book= xlCreateXMLBook();

	//loading an excel book
	if((*book).load("../data.xlsx")){
		//loading the first two sheets
		libxl::Sheet* sheet0 = (*book).getSheet(0);
		libxl::Sheet* sheet1 = (*book).getSheet(1);
		if(sheet0 && sheet1){
			//getmarket(book, sheet0);
			getcountry(book, sheet1, country1, 1); 
			getcountry(book, sheet1, country2, 2);
			getcountry(book, sheet1, country3, 3);
			// The integer in the arguments is the number of the column corresponding to the coutry in Excel file
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
///\fn getmarket
///\brief gets values about markets from the excel file and attributes it to market class variables
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


///\fn getcountry
///\brief gets values about countries from the excel file and attributes it to country class variables
void getcountry(libxl::Book* book, libxl::Sheet* sheet, country* mycountry, int j){
	switch(j){
		case 1: (*mycountry).name="USA"; break;
		case 2: (*mycountry).name="Canada"; break;
		case 3: (*mycountry).name="Mexico";
	}
	
	int i=2;
	(*mycountry).income= (*sheet).readNum(i, j);
	
	++i;
	(*mycountry).totalexports= (*sheet).readNum(i, j);
	
	++i;
	(*mycountry).totalimports= (*sheet).readNum(i, j);
	
	++i;
	(*mycountry).elasticityimports= (*sheet).readNum(i, j);

	++i;
	(*mycountry).elasticityexports= (*sheet).readNum(i, j);

	++i;
	(*mycountry).A= (*sheet).readNum(i, j);

} 
