/// \file simulate.h
/// \brief defines functions necessary for simulation of different shocks


/// \fn choicesimulate
/// \brief gives the user different options of simulation: shock on GDP, exchange rate...
void choicesimulate(country* country1, country* country2, country* country3, market* market1, market* market2, market* market3, exportsnetwork* mynetwork);

/// \fn ProductionShock
/// \brief Determine the impact of a market shock
/// \bug Would using uscan/usmex change the marketvalue or the new value? We almost need markets to be a class defined to a country for this to work.

/// We want to make a qualitative judgement on whether a change in one country's market will have a large or small impact on that country. We want to take as inputs: country, the effected market, and the dollar change in the market in billions. Basically, if the marketchange is negative, the country will export less and import more, thus corresponding to a decrease in that country. Since prices will likely increase in the domestic market due to a shock in the supply, its trading partners will likely demand more of their domestic market's goods => an increase in income => increase demand for imports. 
void ProductionShock(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb,   market* mymarket, double change,   exportsnetwork* nafta);

<<<<<<< HEAD
void GDPShockImpact(country* mycountry, country* foreigncountry1, country* foreigncountry2, int choice, int choicea, int choiceb,  market* market1, market* market2, market* market3, double change, exportsnetwork* nafta);

void ExchangeRateShockImpact(country* domesticcountry, country* foreigncountry, int choice1, int choice2, market* market1, market* market2, market* market3, double change, exportsnetwork* nafta);

void InterestRateShockImpact(country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, market* market1, market* market2, market* market3, double change, exportsnetwork* nafta);


void InflationRateShockImpact(country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, market* market1, market* market2, market* market3, double change,   exportsnetwork* nafta);
=======

/// \fn GDP 
/// \brief Calculates GDP

/// This function calculates a countries GDP as a function of domestic consuption, total exports and total imports. The variable A = country.income - (country.totalexports - country.totalimports). In other words, A is the GDP when we exclude the trade balance. A will not change in our model unless it is updated.
double GDP(  country* mycountry, float nexports, float nimports);


/// \fn GDPShockImpact
/// \brief Determines the impact of a shock to GDP growth
/// \bug Inputting -3 will end program.

/// The GDPShockImpact takes as inputs country and a variable representing the shock to GDP called GDPChange := Percent change in GDP. If we see growth (GDPChange > 0) in a country, it will increase the demand for its imports. Thus we can expect its primary trading partners to increase the volume of their exports. If rather, we see a recession (GDPChange < 0) in a country, it will decrease the demand of their imports. Thus there is a risk for its primary trading partners' exports. 
void GDPShockImpact(  country* mycountry, double change);


/// \fn ExchangeRateShockImpact
/// \brief Impact of an exchange rate appreciation or depreciation on imports exports and GDP
/// \bug No matter the input, it either causes a big recession or good growth levels. Could be caused by our random elasticity values. 

/// ExchangeRate of country C will always refer to how many foreign currencies country C can buy with one unit of country C's currency (ex: If Pound is domestic and Euro foreign, and 1 Pound = 1.27 Euro, then the ExchangeRate is 1.27). Thus an appreciation relative to another currency means an increase in ExchangeRate. 

/// The function takes as inputs a country and a shock to the exchange rate. An appreciation (ExchangeRate > 0) in the currency makes imports less expensive thus increasing the demand for imports while making exports more expensive thus decreasing the foreign for the domestic country's exports. The opposite for a Depreciation (ExchangeRate <= 0).  We can calculate a prediction of the change in imports and exports using the elasticity of imports and exports. Using this we can calculate a prediction for the change in the domestic country's income. If the function is called, it will output the impact on trade and will generate the GDPShockImpact using the predicted income change.
void ExchangeRateShockImpact(  country* domesticcountry,   country* foreigncountry, int choice1, int choice2, double change,   exportsnetwork* nafta);


/// \fn InterestRateShockImpact
/// \brief Determine impact of a shock to interest rates. 

/// When there is an increase in interest rates, we see an increase in the domestic exchange rate since their is more demand for the domestic currency due to superior investment returns in that country. Thus an increase in interest rates will result in a currency appreciation and a decrease in interest rates will result in a currency depreciation. The function takes as inputs the country and the interest rate change, and outputs the effect on the exchange rate while calling the ExchangeRateShockImpact function. 
void InterestRateShockImpact(  country* domesticcountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta);


/// \fn InflationRateShockImpact
/// \brief Determine the impact of a shock of the inflation rate.

/// When there is an increase in inflation, it results in an increase in the domestic interest rate since banks run a higher risk when they lend money. When there is a decrease in inflation we see a decrease in interest rates. The function takes an inputs the country and the inflation rate change, and outputs the effect on interest rates while calling the InterestRateShockImpact function.
void InflationRateShockImpact(  country* mycountry,   country* foreigncountry1,   country* foreigncountry2, int choice, int choicea, int choiceb, double change,   exportsnetwork* nafta);
>>>>>>> 247dfca9c9e8b8aecd5b199449def0a95bb93078






