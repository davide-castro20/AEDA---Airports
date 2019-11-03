#pragma once

#include "Plane.h"


class Flight;
class Plane;
class Date;
class Schedule;

class Employee {
public:
	Employee(string name, Date birthDate);

	string getName() const ;
	Date getDate() const;
	double getSalary() const;

	virtual string getCategory() { return "Non existant for this employee"; }; //returns none if category is non existant
	virtual vector <Plane*> getPlanes() { return {}; }; //returns empty vector if non existant
	virtual vector <Flight*> getFlights() { return {}; }; //returns empty vector if non existant
	virtual string getDeparment() { return "Non existant for this employee"; }; //returns none if department is non existant
	virtual string getFunction() { return "Non existant for this employee"; }; //returns none if function is non existant
	virtual Schedule getSchedule() { Schedule schedule; return schedule; };

	bool setName(string name);
	bool setDate(Date birthDate);
	bool setSalary(float salary);
	

	virtual double calcSalary() {return 0;}; //returns 0 but has no effect since all derivated classes will have this method
protected:
	string name;
	double salary = calcSalary();
	Date birthDate;
};

class Pilot : public Employee {
private:
	string category;//para simplificar apenas existem categorias A, B, C
	vector <Plane*> planes;
	vector <Flight*> flights;
public: 
	Pilot(string name, Date birthDate, string category, vector <Plane*> planes, vector <Flight*> flights);

	string getCategory();
	vector <Plane*> getPlane();
	vector <Flight*> getFlights();
	void setCategory(string categ);
	void setFlights(vector<Flight*> &flights);
	void setPlanes(vector<Plane*> &planes);

	double calcSalary();
};

class FlightCrew : public Employee {
private:
	string category;//para simplificar apenas existem categorias A, B, C
	vector <Flight*> flights;
public:
	FlightCrew(string name, Date birthDate, string category,vector <Flight*> flights);

	string getCategory();
	vector <Flight*> getFlights();
	void setCategory(string categ);
	void setFlights(vector<Flight*> &flights);

	double calcSalary();
};

class Admin : public Employee {
private:
	string department;
	string function;
public:
	Admin(string name, Date birthDate, string department, string function);

	string getDepartment();
	string getFunction();

	double calcSalary();
};

class BaseCrew : public Employee {
private:
	string category;
	Schedule schedule;
public:
	BaseCrew(string name, Date birthDate, string category, Schedule schedule);

	string getCategory();
	Schedule getSchedule();
	void setCategory(string categ);
	void setSchedule(Schedule &sched);

	double calcSalary();
};




