#pragma once


#include "Utils.h"
#include "Airport.h"
#include "Company.h"
#include <fstream>

class Company;

vector<Plane*> readPlanes(string planes_file, const vector<Flight*> &flights);
vector<Flight*> readFlights(string flights_file);
vector<Employee*> readEmployees(string employees_file, const vector<Flight*> &flights, const vector<Plane*> &planes);