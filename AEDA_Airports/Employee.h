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

	void setName(string name);
	void setDate(Date birthDate);
	void setSalary();
	

	virtual float calcSalary();

};