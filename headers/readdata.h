/// \file readdata.h
/// \brief creates function to read our datas from different files

/// \fn read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3)
/// \brief lets the user chose what data he wants to read
void read(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);


/// \func readcountry
/// \brief function shows to the user all the datas from the country he chose to see
void readcountry(country* mycountry);

/// \fn readmarket
/// \brief shows to the user all the data from the country he chose to see
void readmarket(market* mymarket);

/// \func readexports
/// \brief function shows the user the matrix of total exports between countries
void readexports (exportsnetwork* mynetwork);


