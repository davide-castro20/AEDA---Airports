#pragma once

#include "Maintenance.h"
#include "Airport.h"
#include <set>
#include <queue>

class Airport;
class Maintenance;

/**
@brief Airports' set function
*/
struct AirportPtrCmp
{
	bool operator()(const Airport* lhs, const Airport* rhs) const;
};

#define AIRPORT_SET set<Airport*, AirportPtrCmp>

/**
@brief Employee's hash function
*/
struct employeeHash
{
	/**
@brief Returns table insertion index
*/
	int operator() (const Employee* emp) const;
	/**
@brief Compares two employees by equality
*/
	bool operator() (const Employee* emp1, const Employee* emp2) const;
};

/**
@brief Employee's hash table definition
*/
typedef unordered_set<Employee*, employeeHash, employeeHash> tabHEmployees;

/**
@brief O'connor company with several airports
*/
class Company
{
	/**
@brief Company airports
*/
	AIRPORT_SET airports;
	/**
@brief Employees hash table
*/
	tabHEmployees employees;
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
	AIRPORT_SET getAirports() const;
	/**
@brief Return the company's airports
*/
	tabHEmployees getEmployees() const;
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
	/**
@brief Rearranges the airports in the binary tree
*/
	void sortAirports();
};

