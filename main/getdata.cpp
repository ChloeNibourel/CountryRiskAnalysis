/// \file getdata.cpp
/// \brief gets data about countries from the excel (.xlsx) file and attributes the values to country class

#include <iostream>
#include "libxl.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/getdata.h"
#include "../headers/readdata.h"

/// \fn getdata
/// \brief loads an excel file and calls functions to read from it
void getdata (country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork){

	libxl::Book* book= xlCreateXMLBook();

	//loading an excel book
	if((*book).load("data.xlsx")){
		//loading the first two sheets
		libxl::Sheet* sheet0 = (*book).getSheet(0);
		libxl::Sheet* sheet1 = (*book).getSheet(1);
		if(sheet0 && sheet1){
			
			getmarket(book, sheet0, market1, 1);  // The integer in the arguments is used to know which country's data should be retrieved
			getmarket(book, sheet0, market2, 2);
			getmarket(book, sheet0, market3, 3);
			
			getcountry(book, sheet1, country1, 1);  // The integer in the arguments is the number of the column corresponding to the coutry in Excel file
			getcountry(book, sheet1, country2, 2);
			getcountry(book, sheet1, country3, 3);
			
			getexports(book, sheet0, mynetwork);
		}
		else {
			std::cout<<"Error when loading the sheets from the data file"<<std::endl;
		}
	}
	else {
		std::cout<<"Error when loading the data file"<<std::endl;
	}

	
	
}




/// \fn getmarket
/// \brief gets values about markets from the excel file and attributes them to market class variables
void getmarket(libxl::Book* book, libxl::Sheet* sheet, market* mymarket, int k){
	int i, d;
	switch(k){
		case 1: (*mymarket).good="food"; i=2; break;
		case 2: (*mymarket).good="machinery"; i=8; break;
		case 3: (*mymarket).good="fuel"; i=14; break;
		default : std::cout<< "Error : market not in the database";
	}
	
	d=0;
	for (int m=0; m<= 2; ++m){
		// d is a variable that will only be used to adjust our reading of the Excel file to the fact that there is no Excel line from one country to itself
		for (int j=0; j<= 2; ++j){
			if(m==j) { 
				(*mymarket).exchange[m][j] =0;
				--d;
			}
			else{
				(*mymarket).exchange[m][j]= (*sheet).readNum(i+d, 3);
			}
			++d;
		}
	}
}


/// \fn getcountry
/// \brief gets values about countries from the excel file and attributes them to country class variables
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

/// \fn getexports
/// \brief gets values of total exports between the three countries
void getexports(libxl::Book* book, libxl::Sheet* sheet, exportsnetwork* mynetwork){
	for (int i=0; i<3; ++i){
		for (int j=0; j<3; ++j){
			(*mynetwork).exports[i][j]=(*sheet).readNum(23+i, 2+j);
		}
	}
}
