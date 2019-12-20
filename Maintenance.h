#pragma once


class Maintenance {
	int nHours;
	int nMaintenances;
public:
	Maintenance();
	Maintenance(int nHours, int nMaintenances);
	int getHours() const;
	int getMaintenances() const;
	bool operator<(const Maintenance &m1) const;
};