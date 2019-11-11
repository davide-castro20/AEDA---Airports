#include "Airport.h"


using namespace std;


//Class Local

Local::Local() {}

Local::Local(string country, string city, float longit, float latit)
{
	this->country = country;
	this->city = city;
	this->longit = longit;
	this->latit = latit;
}

string Local::getCountry() const
{
	return country;
}

string Local::getCity() const
{
	return city;
}

float Local::getLon() const
{
	return longit;
}

float Local::getLatit() const
{
	return latit;
}



//Class Airport

Airport::Airport(vector<Plane*>& planes, vector<Flight*>& flights, vector <Employee*> employees, Local local, string planestxt, string employeetxt, string flightstxt)
{
	this->planes = planes;
	this->flights = flights;
	this->employees = employees;
	this->local = local;
	this->planesTxt = planestxt;
	this->employeeTxt = employeetxt;
	this->flightTxt = flightstxt;
}

Local Airport::getLocal() const
{
	return local;
}


