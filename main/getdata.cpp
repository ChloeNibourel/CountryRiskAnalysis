///\file getdata.cpp
///\brief gets data about countrys from the excel (.xlsx) file and attributes the values to country classes

#include <iostream>
#include "libxl.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/getdata.h"

///\fn getdata
///\brief loads an excel file and calls functions to read from it
void getdata (country* country1, country* country2, country* country3, market* market1, market* market2, market* market3){

	libxl::Book* book= xlCreateXMLBook();

	//loading an excel book
	if((*book).load("../data.xlsx")){
		//loading the first two sheets
		libxl::Sheet* sheet0 = (*book).getSheet(0);
		libxl::Sheet* sheet1 = (*book).getSheet(1);
		if(sheet0 && sheet1){
			
			getmarket(book, sheet0, market1, 1);
			getmarket(book, sheet0, market2, 2);
			getmarket(book, sheet0, market3, 3);
			
			getcountry(book, sheet1, country1, 1); 
			getcountry(book, sheet1, country2, 2);
			getcountry(book, sheet1, country3, 3);
			// The integer in the arguments is the number of the column corresponding to the coutry in Excel file
		}
		else {
			std::cout<<"Error when loading the sheets from the data file"<<std::endl;
		}
	}
	else {
		std::cout<<"Error when loading the data file"<<std::endl;
	}

	
	
}




///\fn getmarket
///\brief gets values about markets from the excel file and attributes it to market class variables
void getmarket(libxl::Book* book, libxl::Sheet* sheet, market* mymarket, int k){
	int i;
	switch(k){
		case 1: (*mymarket).good="food"; i=2; break;
		case 2: (*mymarket).good="machinery"; i=8; break;
		case 3: (*mymarket).good="fuel"; i=14; break;
		default : std::cout<< "Error : market not in the database";
	}
	
	for (int j=0; j<= 5; ++j){
		(*mymarket).exchange[j][0]= (*sheet).readNum(i+j, 3);
		(*mymarket).exchange[j][1]= (*sheet).readNum(i+j, 4);
	}
}


///\fn getcountry
///\brief gets values about countries from the excel file and attributes it to country class variables
void getcountry(libxl::Book* book, libxl::Sheet* sheet, country* mycountry, int j){
	switch(j){
		case 1: (*mycountry).name="USA"; break;
		case 2: (*mycountry).name="Canada"; break;
		case 3: (*mycountry).name="Mexico"; break;
		default : std::cout<< "Error : country not in the database";
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
