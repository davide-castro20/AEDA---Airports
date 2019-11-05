#pragma once

#include "Utils.h"
#include "Airport.h"

class Company
{
	vector<Airport*> airports;
public:
	Company();
	Company(string airports_file);
	void addAirport(Airport* newAirport);
	vector<Airport*> getAirports() const;
};