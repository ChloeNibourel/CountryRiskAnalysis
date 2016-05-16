#include <iostream>
#include"libxl.h"
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/updatedata.h"

/// \file updatedatas.cpp
/// \brief modify type country variable AND excel file with new data

/// Choose the data you want to update and then change it in the different files 

///\fn updatecountry takes as argument a country and a data to change, asks the user for the new value, update both country and excel file
void updatecountry(country* mycountry,int chosencountry,  int chosendata){
	int i, j;
	double newvalue, currentvalue;
	bool write, save;
	
	//ask the questions in blue and errors in red
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);

	
	if(chosendata==1){
		currentvalue = (*mycountry).income;
	}
	
	else if(chosendata==2){
		currentvalue = (*mycountry).totalimports;
	}
	
	else if(chosendata==3){
		currentvalue = (*mycountry).totalexports;
	}
	
	else if(chosendata==4){
		currentvalue = (*mycountry).elasticityimports;
	}
	
	else if(chosendata==5){
		currentvalue = (*mycountry).elasticityexports;
	}
	
	else if(chosendata==6){
		currentvalue = (*mycountry).A;
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
	


	//If this updating was a success, update the type country variable
	if(write && save){
		if(chosendata==1){
			(*mycountry).income=newvalue;
		}
		
		else if(chosendata==2){
			(*mycountry).totalimports=newvalue;
		}
		
		else if(chosendata==3){
			(*mycountry).totalexports=newvalue;
		}
		
		else if(chosendata==4){
			(*mycountry).elasticityimports=newvalue;
		}
		
		else if(chosendata==5){
			(*mycountry).elasticityexports=newvalue;
		}
		
		else if(chosendata==6){
			(*mycountry).A=newvalue;
		}
	}
	
	
}
