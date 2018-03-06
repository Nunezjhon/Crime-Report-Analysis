/*main.cpp*/

//
// Chicago Crime Analysis program in modern C++.
//
// Jhon Nunez
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

#include "classes.h"

using namespace std;
//-----------------------------------------------------------------------------------------------------------------------------------------
void sortByCrimeCode(vector<CrimeCode>& crimecode)//Sort by Crime Code
{
   
  cout << std::fixed;
  cout << std::setprecision(2);
  
   //sort by name
   sort(crimecode.begin(), 
       crimecode.end(),  
      
      []( CrimeCode &c1, CrimeCode &c2) 
      
      {
        
        if ( c1.getIUCR() < c2.getIUCR() )
          return true;
          
        else
          return false;
        
      }
 );

}
//-----------------------------------------------------------------------------------------------------------------------------------------
void sortByCrimeCount(vector<CrimeCode>& crimecode)//Sort by Crime Counter
{
   
  cout << std::fixed;
  cout << std::setprecision(2);
  
   //sort by name
   sort(crimecode.begin(), 
       crimecode.end(),  
      
      []( CrimeCode &c1, CrimeCode &c2) 
      
      {
        
        if ( c1.viewTotalCrimes() > c2.viewTotalCrimes( )  )
          return true;

        else
          return false;
        
      }
 );

}
//-----------------------------------------------------------------------------------------------------------------------------------------
void updateCrimeCounter(vector<CrimeCode>&crimecode , string x)//updates the crime counter
{
  
    for (CrimeCode& C: crimecode) 
    {
      if ( x == C.getIUCR() )
      {
        C.updateTotalCrimes();
      }
        
    }

}
//-----------------------------------------------------------------------------------------------------------------------------------------
int main()
{
  string line, iucr, pdescription, sdescription;//crime codes
  string datetime, arrest, domestic, beat, district, ward, community, year; //crime repl
  
  string  crimeCodesFilename, crimesFilename;

  int codeCount = 0;
  int reportCount = 0;

  cin >> crimeCodesFilename;
  cout << crimeCodesFilename << endl;
  
  cin >> crimesFilename;
  cout << crimesFilename << endl;

  ifstream  codesFile(crimeCodesFilename);
  ifstream  crimesFile(crimesFilename);

  cout << std::fixed;
  cout << std::setprecision(2);

  if (!codesFile.good())
  {
    cout << "**ERROR: cannot open crime codes file: '" << crimeCodesFilename << "'" << endl;
    return -1;
  }
  if (!crimesFile.good())
  {
    cout << "**ERROR: cannot open crimes file: '" << crimesFilename << "'" << endl;
    return -1;
  }
    
//-----------------------------------------------------------------------------------------------------------------------------------------
//----------------------------------------------------***CREATE CRIMECODE VECTOR***--------------------------------------------------------  
  vector<CrimeCode> crimecode; //create customers vector
  
  getline(codesFile,line);  //to skip the first line of the file
 
  
  while (getline(codesFile,line) ) 
  {
  
    stringstream ss(line);
  
    getline(ss,iucr,',');
    getline(ss,pdescription,',');
    getline(ss,sdescription);
    
    CrimeCode C(iucr ,pdescription, sdescription, 0 );
    
    crimecode.push_back(C); 
    
    codeCount++;
 
  }//end of while loop

//-----------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------***CREATE CRIMEREPORT VECTOR***-------------------------------------------------------
  vector<CrimeReport> crimereport; //create customers vector
  
  getline(crimesFile,line);  //to skip the first line of the file
 
  
  while (getline(crimesFile,line) )
  {
  
    stringstream ss(line);
  
    getline(ss, datetime,',');
    getline(ss, iucr,',');
    getline(ss, arrest,',');
    getline(ss, domestic,',');
    getline(ss, beat,',');
    getline(ss, district,',');
    getline(ss, ward,',');
    getline(ss, community,',');
    getline(ss, year);
    
    CrimeReport R(datetime, iucr , arrest, domestic, stoi(beat), stoi(district), stoi(ward), stoi(community), stoi(year) );
    
    crimereport.push_back(R);
    
    reportCount++;
    
    updateCrimeCounter(crimecode, iucr);
  
  }//end of while loop 
 
//----------------------------------------------------------------------------------------------------------------------------------------- 
  
  sortByCrimeCode(crimecode); // sort by crime code
   
  int x = reportCount - 1; 
   
  cout << "** Crime Analysis **\n" << endl;
  
  cout << "Date range: " << crimereport[0].getDateTime() << " - " << crimereport[x].getDateTime() << "\n" << endl;      
  
  cout << "# of crime codes: " << codeCount << endl;
  
  for (int n = 0 ; n < 3 ; n++)//print first 3 crimes codes
  {
    cout << crimecode[n].getIUCR() <<":  "<< crimecode[n].getPDescription() << ": " << crimecode[n].getSDescription() << endl;
  }
  
  cout << "..." << endl;
  
  for (int n = 3 ; n > 0 ; n--)//print last 3 crimes codes
  {
    cout << crimecode[codeCount-n].getIUCR() <<":  "<< crimecode[codeCount-n].getPDescription() << ": " << crimecode[codeCount-n].getSDescription() << "\n "  << endl;
  }
  
  cout << "# of crimes: " << reportCount << endl;
  
  for (int n = 0 ; n < 3 ; n++)//print first 3 crimes reports
  {
    
    cout << crimereport[n].getIUCR() 
         <<":  " << crimereport[n].getDateTime() 
         << ", " << crimereport[n].getBeat() 
         << ", " << crimereport[n].getDistrict()
         << ", " << crimereport[n].getWard() 
         << ", " << crimereport[n].getCommunity(); 
         
  
    if (crimereport[n].getArrest() == "TRUE" || crimereport[n].getArrest() == "true")
      cout << ", " << "arrested" ;
      
    if (crimereport[n].getDomestic() == "TRUE" || crimereport[n].getDomestic() == "true")
      cout << ", " << "domestic violence" ;
    
    cout << "" << endl;
  }
//-----------------------------------------------------------------------------------------------------------------------------------------
  cout << "..." << endl;
  
  for (int n = 3 ; n > 0 ; n--)//print last 3 crimes codes
  {

    cout << crimereport[reportCount - n].getIUCR() 
         <<":  " << crimereport[reportCount - n].getDateTime() 
         << ", " << crimereport[reportCount - n].getBeat() 
         << ", " << crimereport[reportCount - n].getDistrict()
         << ", " << crimereport[reportCount - n].getWard() 
         << ", " << crimereport[reportCount - n].getCommunity();
         
    //print arrested or domestic violence
    if (crimereport[reportCount - n].getArrest() == "TRUE" || crimereport[reportCount - n].getArrest() == "true")
      cout << ", " << "arrested" ;
      
    if (crimereport[reportCount - n].getDomestic() == "TRUE" || crimereport[reportCount - n].getDomestic() == "true")
      cout << ", " << "domestic violence" ;
    
    cout << "" << endl;
         
  }
 
  cout << "\n" << endl;
  cout << "** Top-5 Crimes **" << endl;
  cout << "Code:  " << "Total, Description" << endl;
  
  sortByCrimeCount(crimecode);
  
  for (int n = 0 ; n < 5 ; n++)//print top 5 crimes
  {
    cout << crimecode[n].getIUCR()  
         << ": " << crimecode[n].viewTotalCrimes()         
         <<":  "<< crimecode[n].getPDescription() 
         << ": " << crimecode[n].getSDescription() << endl;
  }

  cout << "** Done **" << endl;
  
   return 0;
}







