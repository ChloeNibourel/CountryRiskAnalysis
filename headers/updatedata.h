/// \file updatedata.h
/// \brief creates functions to update datas in different files

/// \fn updatechoice
/// \brief gives the user options of types of updating he can make, calls the corresponding update functions from updatedatas.cpp
void updatechoice(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);

/// \fn updatecountry 
/// \brief takes as argument a country and a data to change, asks the user for the new value, updates both the country variable and the excel file
void updatecountry(country* mycountry, int chosencountry, int chosendata);

/// \fn updatemarket 
/// \brief takes as argument a market, and two countries, asks the user for the new value of exports between those countries, updates both the market var and the excel file
void updatemarket(market* mymarket, int countryfrom, int countryto, int chosenmarket);

/// \fn updatetotexports 
/// \brief takes as argument two countries, asks the user for the new value of exports between those countries, updates both the exportsnetwork var and the excel file
void updatetotexports(exportsnetwork* mynetwork, int countryfrom, int countryto);
