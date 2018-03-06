/*classes.h*/

//
// Classes for use with Chicago Crime Analysis program, e.g. "CrimeReport" 
// and "CrimeCode".
//
// Jhon Nunez
// U. of Illinois, Chicago
// CS 341: Spring 2018
// Project 02
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


class CrimeCode
{

private:
	string IUCR;
	string PRIMARY_DESCRIPTION;
	string SECONDARY_DESCRIPTION;
	int TotalCrimes = 0;

public:

	CrimeCode(string iucr, string pDescription, string sDescription, int totalcrimes)
		: IUCR(iucr), PRIMARY_DESCRIPTION(pDescription), SECONDARY_DESCRIPTION(sDescription), TotalCrimes(totalcrimes)
	{}

	string getIUCR() {
		return IUCR;
	}

	string getPDescription() {
		return PRIMARY_DESCRIPTION;
	}

	string getSDescription() {
		return SECONDARY_DESCRIPTION;
	}

	int updateTotalCrimes() {//update the totalcrimes

		TotalCrimes++;

	}

	int viewTotalCrimes() {//view the total crimes 
		return TotalCrimes;
	}

};
//-----------------------------------------------------------------------------------------------------------------------------------------

class CrimeReport
{

private:
	string DateTime;
	string IUCR;
	string Arrest;
	string Domestic;
	int Beat;
	int District;
	int Ward;
	int Community;
	int Year;

public:

	CrimeReport(string datetime, string iucr, string arrest, string domestic, int beat, int district, int ward, int community, int year)
		: DateTime(datetime), IUCR(iucr), Arrest(arrest), Domestic(domestic), Beat(beat), District(district), Ward(ward), Community(community), Year(year)
	{}

	string getIUCR() {
		return IUCR;
	}

	string getDateTime() {
		return DateTime;
	}

	int getDistrict() {
		return District;
	}

	int getBeat() {
		return Beat;
	}

	int getWard() {
		return Ward;
	}

	int getCommunity() {
		return Community;
	}

	string getArrest() {
		return Arrest;
	}

	string getDomestic() {

		return Domestic;
	}


};



