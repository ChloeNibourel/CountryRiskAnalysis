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
	exchange[1][1]= us -> us =0
	exchange[1][2]= us -> canada
	exchange[1][3]= us -> mexico
	
	exchange[2][1]= canada -> us
	exchange[2][2]= canada -> canada =0
	exchange[2][3]= canada -> mexico

	exchange[3][1]= mexico -> us
	exchange[3][2]= mexico -> canada 
	exchange[3][3]= mexico -> mexico =0	*/	
	std::array<double, 6> exchange;	
};

///\class exportsnetwork
///\brief contains data about total exports between countries
class exportsnetwork {
	/*
	exchange[1][1]= us -> us =0
	exchange[1][2]= us -> canada
	exchange[1][3]= us -> mexico
	
	exchange[2][1]= canada -> us
	exchange[2][2]= canada -> canada =0
	exchange[2][3]= canada -> mexico

	exchange[3][1]= mexico -> us
	exchange[3][2]= mexico -> canada 
	exchange[3][3]= mexico -> mexico =0
	*/
	public:
	std::array<std::array<double, 3>, 3> exports;
};