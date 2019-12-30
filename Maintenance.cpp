#include "Maintenance.h"


Maintenance::Maintenance() {

}

Maintenance::Maintenance(int nHours, int nMaintenances,string name) {
	this->nHours = nHours;
	this->nMaintenances = nMaintenances;
	this->name = name;
}

int Maintenance::getHours() const{
	return nHours;
}

string Maintenance::getName() const {
	return name;
}

int Maintenance::getMaintenances() const{
	return nMaintenances;
}

bool Maintenance::operator<(const Maintenance &m1) const {
	if (this->nHours > m1.getHours())
		return true;
	else if (this->nHours == m1.getHours())
		if (this->nMaintenances < m1.getMaintenances())
			return true;
	return false;

}