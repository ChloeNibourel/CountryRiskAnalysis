#include <iostream>
#include <string>

class country {
public: 
	std::string name;
	std::string othercountryexports;
	float exchangerate /// \bug figure out how we want to read exchange rates.
	float elasticityimports
	float elasticityexports
	float Income
	float A
	float totalimports
	float totalexports

	double GDP();
	void GDPShockImpact ();
	void ExchangeRateShockImpact ();
};



