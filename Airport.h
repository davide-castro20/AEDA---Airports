#pragma once
#include "Flight.h"
#include "Employee.h"
#include "Date.h"

class Flight;
class Plane;
class Employee;
class Date;

struct Manager {
	string name;
	Date birthDate;
	double salary;
};

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
	string flightTxt, employeeTxt, planesTxt;
	Manager manager;
	vector<Plane*> planes; //n�o esquecer de usar new
	vector<Flight*> flights; //n�o esquecer de usar new
	vector <Employee*> employees;
	Local local;
	Local getLocal() const;
	Airport() { planes = {}; flights = {}; };
	Airport(vector<Plane*> &planes, vector<Flight*> &flights, vector <Employee*> employees, Local local, string planestxt, string employeetxt, string flightstxt);
	bool setManager(Manager manager) { this->manager = manager; return true; };
};

