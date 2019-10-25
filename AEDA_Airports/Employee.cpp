#include "Employee.h"

using namespace std;

Employee::Employee(string name, Date birthDate) {
	this->name = name;
	this->birthDate = birthDate;
}

string Employee::getName() const{
	return this->name;
}

Date Employee::getDate() const{
	return this->birthDate;
}

float Employee::getSalary() const{
	return this->salary;
}

bool Employee::setName(string name) {
	if (!isupper(name.at(0)))
		return false;
	for (size_t i = 0; i < name.length(); i++) {
		if(isdigit(name.at(i)))
			return false;
	}
	this->name=name;
	return true;
}

bool Employee::setDate(Date birthDate) {
	if (birthDate.isValid()) {
		this->birthDate = birthDate;
		return true;
	}
	return false;
}

bool Employee::setSalary(float salary) {
	if (salary < 0)
		return false;
	this->salary = salary;
	return true;
}
	
