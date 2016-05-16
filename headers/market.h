#include <string>
#include <array>
#include <vector>
///\class market
///\brief info about exchanges between usa - mexico - canada in a specific market : amount of exchanges and percentage of total exchanges
class market{
	public:
	std::string good;

	/* 
	Each component of the exchange array corresponds to tha data about exchanges between two countries in the market :
	exchange[1]= us -> canada
	exchange[1]= us -> mexico
	exchange[1]= canada -> us
	exchange[1]= canada -> mexico
	exchange[1]= mexico -> us
	exchange[1]= mexico -> canada
	
	Inside array<double, 2> :
	First component of the array is amount of exchanges in billions
	Second component of the array is percentage of total exchanges between the two countries */
	
	std::array<std::array<double, 2>, 6> exchange;	
};