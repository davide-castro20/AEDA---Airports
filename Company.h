#pragma once


#include "Airport.h"



class Company
{
	vector<Airport*> airports;
public:
	Company();
	Company(string airports_file);
	/**
@brief Adds an airport to the company
*/
	void addAirport(Airport* newAirport);
	vector<Airport*> getAirports() const;
	/**
@brief Removes an airport from the company
*/
	void deleteAirport(int index);
};