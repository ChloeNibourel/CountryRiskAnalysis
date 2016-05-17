#include <iostream>
#include <string>
/// \file country.h
/// \brief defines a class country with its caracteristics

/// \class country
/// \brief contains data about countries : elasticity, GDP, imports...
class country {
public: 
	std::string name;
	double elasticityimports;
	double elasticityexports;
	double income;
	double A;
	double totalimports;
	double totalexports;

	double GDP();
	void GDPShockImpact ();
	void ExchangeRateShockImpact ();
};
