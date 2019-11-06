#pragma once

#include "Utils.h"
#include "Airport.h"
#include <fstream>


vector<Plane*> readPlanes(string planes_file);
vector<Flight*> readFlights(string flights_file);
vector<Employee*> readEmployees(string employees_file);