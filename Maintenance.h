#pragma once
#include <string>

using namespace std;

class Maintenance {
	int nHours;
	int nMaintenances;
	string name;
public:
	Maintenance();
	Maintenance(int nHours, int nMaintenances, string name);
	int getHours() const;
	string getName() const;
	int getMaintenances() const;
	bool operator<(const Maintenance &m1) const;
};