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

void Employee::setName(string name) {
	for(size_t i = 0; i < name.length ; i++)

}

void setDate();
void setSalary();
