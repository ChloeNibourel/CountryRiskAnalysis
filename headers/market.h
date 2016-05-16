#include <string>
#include <array>
#include <vector>
///\class market
///\brief info about exchanges between usa - mexico - canada in a specific market : amount of exchanges and percentage of total exchanges
class market{
	public:
	std::string good;

	/* 
	Each component of the exchange array corresponds to tha data about total exports between two countries in the market :
	exchange[0][0]= us -> us =0
	exchange[0][1]= us -> canada
	exchange[0][2]= us -> mexico
	
	exchange[1][0]= canada -> us
	exchange[1][1]= canada -> canada =0
	exchange[1][2]= canada -> mexico

	exchange[2][0]= mexico -> us
	exchange[2][1]= mexico -> canada 
	exchange[2][1]= mexico -> mexico =0	*/
	*/
	std::array<std::array<double, 3>, 3> exchange;	
};

///\class exportsnetwork
///\brief contains data about total exports between countries
class exportsnetwork {
	/*
	exports[0][0]= us -> us =0
	exports[0][1]= us -> canada
	exports[0][2]= us -> mexico
	
	exports[1][0]= canada -> us
	exports[1][1]= canada -> canada =0
	exports[1][2]= canada -> mexico

	exports[2][0]= mexico -> us
	exports[2][1]= mexico -> canada 
	exports[2][1]= mexico -> mexico =0	*/		*/
	public:
	std::array<std::array<double, 3>, 3> exports;
};