#pragma once
#include <string>

using namespace std;

class Maintenance {
	/**
@brief Number of hours still available
*/
	int nHours;
	/**
@brief Ñumber of maintenances done
*/
	int nMaintenances;
	/**
@brief Name of the company
*/
	string name;
public:
	Maintenance();
	Maintenance(int nHours, int nMaintenances, string name);
	/**
@brief Returns hours still available
*/
	int getHours() const;
	/**
@brief Returns name of the company
*/
	string getName() const;
	/**
@brief Returns number of maintenances
*/
	int getMaintenances() const;
	/**
@brief Compares two maintenances by the soonest availability, and, if equal, number of maintenances done
*/
	bool operator<(const Maintenance &m1) const;
};