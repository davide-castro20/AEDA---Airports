#pragma once


#include "Utils.h"
#include "Airport.h"
#include "Company.h"
#include <fstream>

class Company;
/**
@brief Reades planes file
*/
vector<Plane*> readPlanes(string planes_file, const vector<Flight*> &flights);
/**
@brief Reads flights file
*/
vector<Flight*> readFlights(string flights_file);

/**
@brief Reads employees files
*/
vector<Employee*> readEmployees(string employees_file, tabHEmployees &employeesT, const vector<Flight*> &flights, const vector<Plane*> &planes, string city);

/**
@brief Reads old employees file
*/
void readOldEmployees(string old_employees_file, tabHEmployees &employees, string city);