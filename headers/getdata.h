#include"libxl.h"

/// \file getdata.h
/// \brief defines functions to extract datas from excel file

void getdata (country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);
void getcountry(libxl::Book* book, libxl::Sheet* sheet, country* mycountry, int j);
void getmarket (libxl::Book* book, libxl::Sheet* sheet, market* mymarket, int k);
void getexports(libxl::Book* book, libxl::Sheet* sheet, exportsnetwork* mynetwork);
