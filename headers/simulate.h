void choicesimulate(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);

void ProductionShock(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb,   market* mymarket, double change,   exportsnetwork* nafta);

double GDP(  country* mycountry, float nexports, float nimports);

void GDPShockImpact(  country* mycountry, double change);

void ExchangeRateShockImpact(  country* domesticcountry,   country* foreigncountry, int choice1, int choice2, double change,   exportsnetwork* nafta);

void InterestRateShockImpact(  country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta);


void InflationRateShockImpact(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta);






