#pragma once
#include "Utils.h"
#include "Plane.h"
#include "Flight.h"

class Plane;
class Flight;
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
	vector<Flight*> flights;
	vector<Employee*> employees;
	Local local;
	Airport() { planes = {};};
	Airport(vector<Plane*> &planes,vector<Flight*> &flights, vector <Employee*> &employees, Local &local);
	Local getLocal() const;
};

