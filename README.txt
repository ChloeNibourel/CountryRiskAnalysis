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
  
Usage:

  download the libxl library 
  http://www.libxl.com/download.html
  Extract libxl-3.6.5.0 and place in package folder

  Enter your folder
  $ make

  $ ./program
  
Documentation:
file:///home/john/RiskAnalysis2/html/index.html
