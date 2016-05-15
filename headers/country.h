#include <iostream>
#include <string>

class country {
public: 
	std::string name;
	std::string othercountryexports; /// \bug figure out how we want to read exchange rates.
	double elasticityimports;
	double elasticityexports;
	double income;
	double A;
	double totalimports;
	double totalexports;
	std::string exportmarkets;

	double GDP();
	void GDPShockImpact ();
	void ExchangeRateShockImpact ();
};



