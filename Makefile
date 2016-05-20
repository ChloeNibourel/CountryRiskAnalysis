all : 

	g++ -o program main/main.cpp main/getdata.cpp read/readdatas.cpp read/choiceread.cpp update/choiceupdate.cpp update/updatedatas.cpp main/genericchoices.cpp simulate/market.cpp simulate/GDPShockImpact.cpp simulate/ExchangeRateShockImpact.cpp simulate/InterestAndInflation.cpp simulate/choicesimulate.cpp -Ilibxl-3.6.5.0/include_cpp/ -Llibxl-3.6.5.0/lib -lxl -Wl,-rpath,libxl-3.6.5.0/lib -std=c++11
