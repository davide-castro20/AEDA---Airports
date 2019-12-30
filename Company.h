#pragma once

#include "Maintenance.h"
#include "Airport.h"
#include <queue>

class Airport;
class Maintenance;


/**
@brief O'connor company with several airports
*/
class Company
{
	/**
@brief Company airports
*/
	vector<Airport*> airports;
	/**
@brief Maintenance companies
	*/
	priority_queue<Maintenance> maintenanceCompanies;
public:
	Company();
	Company(string airports_file, string maintenance_file);
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
	/**
@brief Adds a maintenace company to the maintenance priority queue
*/
	void addMaintenanceCompany(Maintenance maintenaceCompany);

	/**
@brief Returns all maintenace companies
*/
	priority_queue<Maintenance> getMaintenaceCompanies();

/**
@brief Removes all maintenace companies
*/
	void clearMaintenance();
};

