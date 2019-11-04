#pragma once

#include "Utils.h"
#include "Airport.h"
#include <fstream>


Company readAirports(string airports_file);
vector<Plane*> readPlanes(string planes_file);
vector<Flight*> readFlights(string flights_file);
vector<Employee*> readEmployees(string employees_file);