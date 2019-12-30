#pragma once

#include "Flight.h"
#include "Employee.h"
#include "Date.h"

class Flight;
class Plane;
class Employee;
class Date;



/**
@brief Manager of an airport
*/
struct Manager {
	/**
@brief Manager's name
*/
	string name;
	/**
@brief Manager's birth date
*/
	Date* birthDate;
	/**
@brief Manager's salary
*/
	double salary;
};


/**
@brief Place of an airport with country,city and coordinates
*/
class Local
{
private:
	/**
@brief Local's country
*/
	string country;
	/**
@brief Local's city
*/
	string city;
	/**
@brief Local's longitude
*/
	float longit;
	/**
@brief Local's latitude
*/
	float latit;
public:
	Local();
	Local(string country, string city, float longit, float latit);
	/**
@brief Return the local's country
*/
	string getCountry() const;
	/**
@brief Return the local's city
*/
	string getCity() const;
	/**
@brief Return the local's longitude
*/
	float getLon() const;
	/**
@brief Return the local's latitude
*/
	float getLatit() const;
};


/**
@brief Airport class with employees, planes, location, flights and a manager
*/
class Airport
{
public:
	/**
@brief Variable which saves the .txt of the airport's flights
*/
	string flightTxt;
	/**
@brief Variable which saves the .txt of the airport's employees
*/
	string employeeTxt;
	/**
@brief Variable which saves the .txt of the airport's planes
*/
	string planesTxt;
	/**
@brief Airport's manager
*/
	Manager manager;
	/**
@brief Vector with airport's planes
*/
	vector<Plane*> planes; //n�o esquecer de usar new
	/**
@brief Vector with airport's flights
*/
	vector<Flight*> flights; //n�o esquecer de usar new
	/**
@brief Vector with airport'semployees
*/
	vector <Employee*> employees;
	/**
@brief Airport's local
*/
	Local local;
	/**
@brief Return's the airport's local
*/
	Local getLocal() const;

	Airport() { planes = {}; flights = {}; };

	Airport(vector<Plane*> &planes, vector<Flight*> &flights, vector <Employee*> employees, Local local, string planestxt, string employeetxt, string flightstxt);
	/**
@brief Sets the airport's manager
*/
	bool setManager(Manager manager) { this->manager = manager; return true; };

	int totalWaitingTime() const;

	double meanWaitingTime() const;
	
	bool operator<(const Airport &rhs) const;

};

