#pragma once


#include "Airport.h"



class Company
{
	/**
@brief Company airports
*/
	vector<Airport*> airports;
public:
	Company();
	Company(string airports_file);
	/**
@brief Adds an airport to the company
*/
	void addAirport(Airport* newAirport);
	/**
@brief Return the company's airports
*/
	vector<Airport*> getAirports() const;
	/**
@brief Removes an airport from the company
*/
	void deleteAirport(int index);
};