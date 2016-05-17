///\file updatedatas.cpp
///\brief modify type country variable AND excel file with new data
#include <iostream>
#include"libxl.h"
#include "../headers/colors.h"
#include "../headers/country.h"
#include "../headers/market.h"
#include "../headers/updatedata.h"

///\func updatecountry 
///\brief takes as argument a country and a data to change, asks the user for the new value, updates both the country variable and the excel file
void updatecountry(country* mycountry,int chosencountry,  int chosendata){
	int i, j;
	double newvalue, currentvalue;
	bool write, save; 
	bool error;
	
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
	do{
		error=0;
		std::cout << blue << "Current value is " << currentvalue << std::endl;
		std::cout << "Enter the new value :" << def << std::endl;

		std::cin>>newvalue;
	
		if(std::cin.fail() ){ //if type wasn't right
    	    		std::cin.clear(); //clear stream
    	    		std::cin.ignore(); //ignore left over data
			std::cout << red << "Error : enter a numerical value" << def << std::endl;
			error=1;
		}
	} while (error==1); ///\bug : when someone enters a non-numerical value the std::cin.fail() doesn't notice it
	
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
		
		else {std::cout << red <<"Error when loading the sheet from the data file"<< def << std::endl;}	

	}
	else {
		std::cout << red <<"Error when loading the data file"<< def << std::endl;
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

///\func updatecountry 
///\brief takes as argument a market, and two countries, asks the user for the new value of exports between those countries, updates both the market var and the excel file
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
	std::cout << blue << "Current value is " << (*mymarket).exchange[countryfrom-1][countryto-1] << std::endl;
	std::cout << "Enter the new value :" << def << std::endl;
	
	std::cin>>newvalue;
	
	
	//update the Excel data file
	libxl::Book* book= xlCreateXMLBook();

	if((*book).load("data.xlsx")){
		libxl::Sheet* sheet = (*book).getSheet(0);
		if(sheet){
			write = (*sheet).writeNum(row+k, 3, newvalue);
			save = (*book).save("data.xlsx");
		}
		
		else {std::cout<< red <<"Error when loading the sheet from the data file"<< def << std::endl;}	

	}
	else {
		std::cout<< red << "Error when loading the data file"<< def <<std::endl;
	}
	
	//If this updating was a success, update the type country variable
	if(write && save){
		(*mymarket).exchange[countryfrom-1][countryto-1]=newvalue;
	}	
	
	
}

///\func updatetotexports 
///\brief takes as argument two countries, asks the user for the new value of exports between those countries, updates both the exportsnetwork var and the excel file
void updatetotexports(exportsnetwork* mynetwork, int countryfrom, int countryto){

	//colors
    Color::Modifier blue(Color::FG_BLUE);
    Color::Modifier red(Color::FG_RED);
    Color::Modifier def(Color::FG_DEFAULT);
	
	bool write, save;
	double newvalue;
	
	//Ask user for the new data
	std::cout << blue << "Current value is " << (*mynetwork).exports[countryfrom-1][countryto-1] << std::endl;
	std::cout << "Enter the new value :" << def << std::endl;
	
	std::cin>>newvalue;
		
	//update the Excel data file
	libxl::Book* book= xlCreateXMLBook();

	if((*book).load("data.xlsx")){
		libxl::Sheet* sheet = (*book).getSheet(0);
		if(sheet){
			write = (*sheet).writeNum(22+countryto , 1+countryfrom, newvalue);
			save = (*book).save("data.xlsx");
		}
		
		else {std::cout << red <<"Error when loading the sheet from the data file"<< def << std::endl;}	

	}
	else {
		std::cout<< red <<"Error when loading the data file"<< def <<std::endl;
	}
	


	//If this updating was a success, update the type country variable itself
	if(write && save){
		(*mynetwork).exports[countryfrom-1][countryto-1]=newvalue;		
	}
}
