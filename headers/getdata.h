#include"libxl.h"

void getdata (country* country1, country* country2, country* country3, market* market1, market* market2, market* market3);
void getcountry(libxl::Book* book, libxl::Sheet* sheet, country* mycountry, int j);
void getmarket (libxl::Book* book, libxl::Sheet* sheet, market* mymarket, int k);