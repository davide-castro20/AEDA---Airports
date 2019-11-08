#pragma once
#include "Flight.h"
#include "Employee.h"


class Flight;
class Plane;
class Employee;

class Local
{
private:
	string country;
	string city;
	float longit, latit;
public:
	Local();
	Local(string country, string city, float longit, float latit);
	string getCountry() const;
	string getCity() const;
	float getLon() const;
	float getLatit() const;
};


class Airport
{
public:
	vector<Plane*> planes; //não esquecer de usar new
	vector<Flight*> flights; //não esquecer de usar new
	vector <Employee*> employees;
	Local local;
	Airport() { planes = {}; flights = {}; };
	Airport(vector<Plane*> &planes, vector<Flight*> &flights, vector <Employee*> employees, Local local);
	Local getLocal() const;
};

