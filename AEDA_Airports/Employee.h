#pragma once

#include "Date.h"


class Employee {
private:
		string name;
		float salary;
		Date birthDate;
public:
	Employee(string name, Date birthDate);

	string getName() const ;
	Date getDate() const;
	float getSalary() const;

	bool setName(string name);
	bool setDate(Date birthDate);
	bool setSalary(float salary);
	

	//virtual float calcSalary();

};