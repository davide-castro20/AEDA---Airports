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
	Manager man;
	man.name = "";
	man.birthDate = new Date(0, 0, 0);
	man.salary = 0;
	this->planes = planes;
	this->flights = flights;
	this->employees = employees;
	this->local = local;
	this->planesTxt = planestxt;
	this->employeeTxt = employeetxt;
	this->flightTxt = flightstxt;
	this->manager = man;
}

int Airport::totalWaitingTime() const
{
	int total = 0;
	for (size_t i = 0; i < planes.size(); i++)
	{
		total += planes.at(i)->getMeanTime();
	}
	return total;
}

double Airport::meanWaitingTime() const
{
	return this->totalWaitingTime()/planes.size();
}

bool Airport::operator<(const Airport &rhs) const
{
	if (this->flights.size() == rhs.flights.size())
	{
		return this->meanWaitingTime() < rhs.meanWaitingTime();
	}
	return this->flights.size() < rhs.flights.size();
}

Local Airport::getLocal() const
{
	return local;
}


