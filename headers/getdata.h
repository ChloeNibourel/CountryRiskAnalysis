#include"libxl.h"

/// \file getdata.h
/// \brief defines functions to extract datas from excel file

/// \fn getdata
/// \brief loads an excel file and calls functions to read from it
void getdata (country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);

/// \fn getcountry
/// \brief gets values about countries from the excel file and attributes them to country class variables
void getcountry(libxl::Book* book, libxl::Sheet* sheet, country* mycountry, int j);

/// \fn getmarket
/// \brief gets values about markets from the excel file and attributes them to market class variables
void getmarket (libxl::Book* book, libxl::Sheet* sheet, market* mymarket, int k);

/// \fn getexports
/// \brief gets values of total exports between the three countries
void getexports(libxl::Book* book, libxl::Sheet* sheet, exportsnetwork* mynetwork);
