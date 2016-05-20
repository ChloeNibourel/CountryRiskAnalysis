/// \file simulate.h
/// \brief defines functions necessary for simulation of different shocks


/// \fn choicesimulate
/// \brief gives the user different options of simulation: shock on GDP, exchange rate...

void choicesimulate(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);

/// \fn ProductionShock
/// \brief Determine the impact of a production shock to one of three markets. 

/// Once the user has chosen production shock, he is asked about the impacted country, the market (food, fuel, or machinery), and the degree of the shock. Given his choices, the program generates the inputs for the ProductionShock function. The function outputs the effect on the domestic market and on its two trading partners' markets.

void ProductionShock(country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb,   market* mymarket, double change, exportsnetwork* nafta);

/// \fn GDPShockImpact
/// \brief Determines the impact of a shock to GDP growth

/// Once the user has chosen the GDP Shock option, he is asked about the impacted country and the degree of the shcok. Given his choices, the program generates the inputs for the GDPShockImpact function. The function outputs the effect on the domestic country and the effect on foreign exports to the domestic country.

void GDPShockImpact(country* mycountry, country* foreigncountry1, country* foreigncountry2, int choice, int choicea, int choiceb,  market* market1, market* market2, market* market3, double change, exportsnetwork* nafta);


/// \fn ExchangeRateShockImpact
/// \brief Determines the impact of an exchange rate appreciation or depreciation on imports exports and GDP

/// Once the user has chosen the Exchange Rate shock option, he is asked about the impacted countries and the degree of the shock. The appropriate inputs for the ExchangeRateShockImpact function are generated from his answers. The function outputs the effect on the imports and exports between these two countries and specifies which markets will be most affected.

void ExchangeRateShockImpact(country* domesticcountry, country* foreigncountry, int choice1, int choice2, market* market1, market* market2, market* market3, double change, exportsnetwork* nafta);


/// \fn InterestRateShockImpact
/// \brief Determines the impact of a shock to domestic interest rates 

/// Once the user has chosen the Interest Rate shock option, he is asked about the impacted country and the degree of the shock. The appropriate inputs for the InterestRateShockImpact function are generated from his answers. The function outputs the effect on the exchange rate and thus the effect on the imports and exports between his two trading partners (specifying which markets will be most affected). 

void InterestRateShockImpact(country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, market* market1, market* market2, market* market3, double change, exportsnetwork* nafta);


/// \fn InflationRateShockImpact
/// \brief Determines the impact of a shock of the inflation rate.

/// Once the user has chosen the Inflation Rate shock option, he is asked about the impacted country and the degree of the shock. The appropriate inputs for the InflationRateShockImpact function are generated from his answers. The function outputs the effect on the interests rates, the exchange rates, and thus the effect on the imports and exports between its two trading partners (specifying which markets will be most affected). 

void InflationRateShockImpact(country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, market* market1, market* market2, market* market3, double change,   exportsnetwork* nafta);







