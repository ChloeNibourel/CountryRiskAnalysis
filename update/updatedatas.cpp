/// \file updatedatas.cpp
/// \brief modify type country variable AND excel file with new data
#include <iostream>
#include"libxl.h"
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/updatedata.h"

///\fn updatecountry 
///\brief takes as argument a country and a data to change, asks the user for the new value, update both country and excel file
void updatecountry(country* mycountry,int chosencountry,  int chosendata){
	int i, j;
	double newvalue, currentvalue;
	bool write, save;
	
	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

	switch(chosendata){
		case 1:
			currentvalue = (*mycountry).income;; break;
		case 2:
			currentvalue = (*mycountry).totalimports; break;
		case 3:
			currentvalue = (*mycountry).totalexports; break;
		case 4:
			currentvalue = (*mycountry).elasticityimports; break;
		case 5:
			currentvalue = (*mycountry).elasticityexports; break;
		case 6:
			currentvalue = (*mycountry).A; break;
	}
			
	//Ask user for the new data
	std::cout << blue << "Current value is " << currentvalue << std::endl;
	std::cout << "Enter the new value :" << std::endl;
	
	std::cin>>newvalue;
	
	//Attributes to i and j the values of the row and column where this data is stored in Excel file
	i=chosendata+1;
	j=chosencountry;
	
	//update the Excel data file
	libxl::Book* book= xlCreateXMLBook();

	if((*book).load("data.xlsx")){
		libxl::Sheet* sheet = (*book).getSheet(1);
		if(sheet){
			write = (*sheet).writeNum(i, j, newvalue);
			save = (*book).save("data.xlsx");
		}
		
		else {std::cout<<"Error when loading the sheet from the data file"<<std::endl;}	

	}
	else {
		std::cout<<"Error when loading the data file"<<std::endl;
	}
	


	//If this updating was a success, update the type country variable itself
	if(write && save){
		
		switch(chosendata){
			case 1:
				(*mycountry).income=newvalue; break;
			case 2:
				(*mycountry).totalimports=newvalue; break;
			case 3:
				(*mycountry).totalexports=newvalue; break;
			case 4:
				(*mycountry).elasticityimports=newvalue; break;
			case 5:
				(*mycountry).elasticityexports=newvalue; break;
			case 6:
				(*mycountry).A=newvalue; break;
		}
	}	
}

void updatemarket(market* mymarket, int countryfrom, int countryto, int chosenmarket){
	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

	
	
	int k, row;
	//row is a value that will be used later on to determine more easily the position of the data to update in the Excel file
	row=1 + (1-chosenmarket)*6;

	//k is the position in the exchange array of the exchanges between the two countries chosen by the user
	if (countryfrom==1){
		switch (countryto){
			case 2 : k=1; break;
			case 3 : k=2; break;
		}
	}
	
	if (countryfrom==2){
		switch (countryto){
			case 1 : k=3; break;
			case 3 : k=4; break;
		}
	}
	
	if (countryfrom==3){
		switch (countryto){
			case 1 : k=5; break;
			case 2 : k=6; break;
		}
	}
	
	
	double newvalue, currentvalue;
	bool write, save;
	
	//Ask user for the new data
	std::cout << blue << "Current value is " << (*mymarket).exchange[k][1] << std::endl;
	std::cout << "Enter the new value :" << std::endl;
	
	std::cin>>newvalue;
	
	
	//update the Excel data file
	libxl::Book* book= xlCreateXMLBook();

	if((*book).load("data.xlsx")){
		libxl::Sheet* sheet = (*book).getSheet(0);
		if(sheet){
			write = (*sheet).writeNum(row+k, 3, newvalue);
			save = (*book).save("data.xlsx");
		}
		
		else {std::cout<<"Error when loading the sheet from the data file"<<std::endl;}	

	}
	else {
		std::cout<<"Error when loading the data file"<<std::endl;
	}
	
	//If this updating was a success, update the type country variable
	if(write && save){
		(*mymarket).exchange[k][1]=newvalue;
	}	
	
	
}

