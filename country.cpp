#include <iostream>
#include <string> 
#include <cmath>
#include "country.h"

/// \file country.cpp
/// \brief macro level functions

///Countries will have associated functions to determine the impact of shocks at the macroeconomic
///level. 

/// \func GDP 
/// \brief calculates GDP

/// Calculates a countries GDP as a function of domestic consuption, total exports and total imports. 
/// The variable A is all the other variables that affect GDP, but that we are not interested in. 

double GDP(const country& mycountry, float nexports, float nimports) {
	double GDP = mycountry.A + nexports - nimports;	
	return GDP;
	}

/// \func GDP Shock
/// \brief Determines the impact of a shock to GDP growth

/// Use will input Country and GCPChange in percent. The Fact that the user has picked a country should cause the use of that countries GDPShockImpact. 
void GDPShockImpact(const country& mycountry, double GDPChange) {
	if (GDPChange > 0) {
		std::cout << "Increased demand for " << mycountry.name << "'s imports. Good time to invest in " << mycountry.othercountryexports << std::endl; /// \bug include othercountryexports in country's class. We want the program to output the other countries' names and export to domestic country.
		}
	if (GDPChange <= 0) {
		std::cout << "Decreased demand for " << mycountry.name << "'s imports. Risk for" << 			mycountry.othercountryexports << std::endl;
		}
	}

/// \func ExchangeRateShockImpact
/// \bried Impact of an exchange rate appreciation or depreciation on imports exports and GDP
/// \bug. We have to homogenize the direction of exchange rates. Domestic -> foreign or foreign -> Domestic

///Details

void ExchangeRateShockImpact(const country& mycountry, double ExchRChange) {
	double changeimports = ExchRChange*mycountry.elasticityimports;
	double changeexports = ExchRChange*mycountry.elasticityexports;
	double newimports = changeimports*mycountry.totalimports;
	double newexports = changeexports*mycountry.totalexports;
	double newincome = GDP(mycountry, newexports, newexports);
	double incomechange = (newincome - mycountry.income)/mycountry.income;
	if (ExchRChange > 0) { ///Depreciation
		std::cout << mycountry.name << " will see an increased demand in imports and a decreased demand in exports. Good for" << mycountry.othercountryexports << ". Risk for " << mycountry.exportmarkets << ".";
	}
	if (ExchRChange < 0) { ///Appreciation
		std::cout << mycountry.name << "will see a decreased demand in imports and an increased demand in exports. Good for " << mycountry.exportmarkets << " Risk for " << mycountry.othercountryexports << ".";
	}
}

/// \func InterestRateShockImpact
/// \brief Determine impact of a shock to interest rates. 

///Details

void InterestRateShockImpact(const country& mycountry, double IntRChange) {
	double ExchRChange = IntRChange;
	if (IntRChange > 0) {
		std::cout << "Depreciation of exchange rate. ";
		ExchangeRateShockImpact(mycountry, ExchRChange);
	}
	if (IntRChange <= 0) {
		std::cout << "Appreciation of exchange rate. ";
		ExchangeRateShockImpact(mycountry, ExchRChange);
	}
}

int main() {
	country Mexico;
	Mexico.name = "Mexico";
	Mexico.othercountryexports = "Canada's Food Exports and USA's Petrol Exports.";
	Mexico.elasticityimports = 0.45;
	Mexico.elasticityexports = -0.20;
	Mexico.totalimports = 204;
	Mexico.totalexports = 109;
	Mexico.A = 2094+109-204;
	Mexico.income = 2094;
	Mexico.exportmarkets = "Mexico's Pharmaceutical, Food, and Petrol markets";
	InterestRateShockImpact(Mexico, -5); 
}


