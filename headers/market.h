#include <string>
#include <vector>


class market{
	std::string good;
	//First component of the array is amount of exchanges in billions
	//Second component of the array is percentage of total exchanges between the two countries
	std::array<double, 2> uscan;
	std::array<double, 2> usmex;
	std::array<double, 2> canus;
	std::array<double, 2> canmex;
	std::array<double, 2> mexus;
	std::array<double, 2> mexcan;
	
	std::array <<std::array<double, 2>, 6> exchange;
	exchange = { uscan, usmex, canus, canmex, mexus, mexcan};
};