# CountryRiskAnalysis
C++ project.

CountryRiskAnalysis is a program to simulate shocks on variables:
  -GDP
  -Exchange rate
  -Interest rate
  -Inflation rate
  -Production

It takes into account 3 countries and 3 markets

Objective:
After a shock, investors would have an idea on which market to invest and where.
They can anticipate the consequence of a shock in the short run.

Package contents:

  headers               headers defining class and function with documentation  
  main                  basic files to start the program
  read                  read datas from source and choose which data to read
  update                update datas on source and choose which data to update
  simulate              simulate a shock on different variables
  data.xlsx             basics datas on exports between countries
  genericchoices.cpp    choices often used
  
Usage:

  download the libxl library 
  http://www.libxl.com/download.html
  Extract libxl-3.6.5.0

  g++ -o program main/main.cpp main/getdata.cpp read/readdatas.cpp read/choiceread.cpp update/choiceupdate.cpp update/updatedatas.cpp genericchoices.cpp simulate/market.cpp simulate/country.cpp simulate/choicesimulate.cpp -Ilibxl-3.6.5.0/include_cpp/ -Llibxl-3.6.5.0/lib -lxl -Wl,-rpath,libxl-3.6.5.0/lib -std=c++11

  ./program
  
Documentation:
(link available soon)
