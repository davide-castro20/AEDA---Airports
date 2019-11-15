#pragma once

#include "Plane.h"
#include "Date.h"
#include "Schedule.h"

class Schedule;
class FlightSched;
class Flight;
class Plane;
class Date;


class Employee {
public:
	Employee(string name, Date *birthDate,string type);

	string getName() const ;
	Date getDate() const;
	double getSalary() const;
	string getType() const;

	virtual string getCategory() const { return "Non existant for this employee"; }; //returns none if category is non existant
	virtual vector <Plane*> getPlanes() const { return {}; }; //returns empty vector if non existant
	virtual vector <Flight*> getFlights() const { return {}; }; //returns empty vector if non existant
	virtual string getDepartment() const { return "Non existant for this employee"; }; //returns none if department is non existant
	virtual string getFunction() const { return "Non existant for this employee"; }; //returns none if function is non existant
	virtual Schedule* getSchedule() const { Schedule *schedule = NULL; return schedule; };

	virtual bool setCategory(string category) { return true; };
	virtual bool setFlights(vector<Flight*> &flights) { return true; };
	virtual bool setSchedule(Schedule *schedule) { return true; };
	virtual bool setDepartment(string department) { return true; };
	virtual bool setFunction(string function) { return true; };
	/**
@brief Creates if employee is free on a certain flight schedule
*/
	virtual bool isFree(FlightSched *check) { return false; };
	virtual void addFlight(Flight* flight) { return; };
	virtual void deleteFlight(int id) { return; };
	virtual string getPlaneTypes() const { return ""; };

	bool setName(string name);
	bool setDate(Date *birthDate);
	bool setSalary(float salary);
	

	virtual double calcSalary() {return 0;}; //returns 0 but has no effect since all derivated classes will have this method

	bool operator==(Employee &emp2);
protected:
	string name;
	string type;
	double salary = calcSalary();
	Date *birthDate;
};

class Pilot : public Employee {
private:
	string category;//para simplificar apenas existem categorias A, B, C
	vector <Plane*> planes;
	vector <Flight*> flights;
public: 
	Pilot(string name, Date *birthDate, string category, vector <Plane*> &planes, vector <Flight*> &flights);

	string getCategory() const ;
	vector <Plane*> getPlanes() const;
	string getPlaneTypes() const;
	vector <Flight*> getFlights() const;
	bool setCategory(string categ);
	bool setFlights(vector<Flight*> &flights);
	bool setPlanes(vector<Plane*> &planes);
	bool isFree(FlightSched *check);
	void addFlight(Flight* flight);
	void deleteFlight(int id);
	

	double calcSalary();
};

class FlightCrew : public Employee {
private:
	string category;//para simplificar apenas existem categorias A, B, C
	vector <Flight*> flights;
public:
	FlightCrew(string name, Date *birthDate, string category,vector <Flight*> flights);

	string getCategory() const;
	vector <Flight*> getFlights() const;
	bool setCategory(string categ);
	bool setFlights(vector<Flight*> &flights);
	bool isFree(FlightSched *check);
	void addFlight(Flight* flight);
	void deleteFlight(int id);

	double calcSalary();
};

class Admin : public Employee {
private:
	string department;
	string function;
public:
	Admin(string name, Date *birthDate, string department, string function);

	string getDepartment() const;
	string getFunction() const;

	bool setDepartment(string depart);
	bool setFunction(string func);

	double calcSalary();
};

class BaseCrew : public Employee {
private:
	string category;
	Schedule *schedule;
public:
	BaseCrew(string name, Date *birthDate, string category, Schedule *schedule);

	string getCategory() const;
	Schedule* getSchedule() const;
	bool setCategory(string categ);
	bool setSchedule(Schedule *sched);



	double calcSalary();
};


class InvalidName
{
	string name;
public:
	InvalidName(string name) { this->name = name; };
	string getName() const { return name; };
};

class InvalidCategory
{
	string category;
public:
	InvalidCategory(string category) { this->category = category; };
	string getCategory() const { return category; };
};

class InvalidBirthDate
{
	Date* birthDate;
public:
	InvalidBirthDate(Date* date) { this->birthDate = date; };
	Date* getBirthDate() const { return birthDate; };
};

class InvalidPlaneTypes
{
	string planeTypes;
public:
	InvalidPlaneTypes(string planeTypes) { this->planeTypes = planeTypes; };
	string getPlaneTypes() const { return planeTypes; };
};
