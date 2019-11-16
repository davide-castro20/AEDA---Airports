#pragma once

#include "Plane.h"
#include "Date.h"
#include "Schedule.h"

class Schedule;
class FlightSched;
class Flight;
class Plane;
class Date;

/**
@brief An employee, name, birthdate and salary
*/
class Employee {
public:
	Employee(string name, Date *birthDate,string type);
	/**
@brief Return the employee's name
*/

	string getName() const ;
	/**
@brief Return the employee's birthe date
*/
	Date getDate() const;
	/**
@brief Return the employee's salary
*/
	double getSalary() const;
	/**
@brief Return the employee's type (Pilot, Base Crew, Admin or Flight Crew)
*/
	string getType() const;
	/**
@brief Return the employee's category
*/
	virtual string getCategory() const { return "Non existant for this employee"; }; //returns none if category is non existant
	/**
@brief Return the planes that the employee will board (empty if the employee isn't a flight crew or pilot)
*/
	virtual vector <Plane*> getPlanes() const { return {}; }; //returns empty vector if non existant
	/**
@brief Return the flights that the employee will make (empty if the employee isn't a flight crew or pilot)
*/
	virtual vector <Flight*> getFlights() const { return {}; }; //returns empty vector if non existant
	/**
@brief Return the departement of the employee
*/
	virtual string getDepartment() const { return "Non existant for this employee"; }; //returns none if department is non existant
	/**
@brief Return the function that the employee realises
*/
	virtual string getFunction() const { return "Non existant for this employee"; }; //returns none if function is non existant
	/**
@brief Returns the employee's work schedule
*/
	virtual Schedule* getSchedule() const { Schedule *schedule = NULL; return schedule; };
	/**
@brief Sets the employee's category
*/
	virtual bool setCategory(string category) { return true; };
	/**
@brief Sets the employee's flights
*/
	virtual bool setFlights(vector<Flight*> &flights) { return true; };
	/**
@brief Sets the employee's schedule
*/
	virtual bool setSchedule(Schedule *schedule) { return true; };
	/**
@brief Sets the employee's departement
*/
	virtual bool setDepartment(string department) { return true; };
	/**
@brief Sets the employee's function
*/
	virtual bool setFunction(string function) { return true; };
	/**
@brief Creates if employee is free on a certain flight schedule
*/
	virtual bool isFree(FlightSched *check) { return false; };
	/**
@brief Adds a fligth to the employee (doesn't do anything if the employee isn't a pilot or flight crew)
*/
	virtual void addFlight(Flight* flight) { return; };
	/**
@brief Deletes a fligth from the employee (doesn't do anything if the employee isn't a pilot or flight crew)
*/
	virtual void deleteFlight(int id) { return; };
	/**
@brief Returns teh plane types the employee can board(emplty string if the employee isn't a pilot or flight crew)
*/
	virtual string getPlaneTypes() const { return ""; };
	/**
@brief Sets the employee's name
*/
	bool setName(string name);
	/**
@brief Sets the employee's birth date
*/
	bool setDate(Date *birthDate);
	/**
@brief Sets the employee's salary
*/
	bool setSalary(float salary);
	/**
@brief Calculates the employee's departement
*/
	virtual double calcSalary() {return 0;}; //returns 0 but has no effect since all derivated classes will have this method
	/**
@brief Compares two employees and checks if they are the same person
*/
	bool operator==(Employee &emp2);
protected:
	/**
@brief Employee's name
*/
	string name;
	/**
@brief Employee's type (Pilot, Flight Crew, Base Crew or Admin)
*/
	string type;
	/**
@brief Employee's salary
*/
	double salary = calcSalary();
	/**
@brief Employee's birth date
*/
	Date *birthDate;
};


/**
@brief Pilot, also an employee. Has planes, flights and category
*/
class Pilot : public Employee {
private:
	/**
@brief Pilot's category
*/
	string category;//para simplificar apenas existem categorias A, B, C
	/**
@brief Planes the pilot will fly
*/
	vector <Plane*> planes;
	/**
@brief Flights the pilot will realise
*/
	vector <Flight*> flights;
public: 
	Pilot(string name, Date *birthDate, string category, vector <Plane*> &planes, vector <Flight*> &flights);
	/**
@brief Returns the pilot's category
*/
	string getCategory() const ;
	/**
@brief Returns the planes that the pilot will fly
*/
	vector <Plane*> getPlanes() const;
	/**
@brief Returns the type of planes the pilot can fly
*/
	string getPlaneTypes() const;
	/**
@brief Returns the flights the pilot will realise
*/
	vector <Flight*> getFlights() const;
	/**
@brief Sets the pilot's category recieved as a parameter
*/
	bool setCategory(string categ);
	/**
@brief Sets the flights that the pilot will realise recieved as a parameter
*/
	bool setFlights(vector<Flight*> &flights);
	/**
@brief Sets the planes that the pilot will fly recieved as a parameter
*/
	bool setPlanes(vector<Plane*> &planes);
	/**
@brief Check if the pilot is free int the flight schedule recieved as a parameter
*/
	bool isFree(FlightSched *check);
	/**
@brief Adds a flight to the pilot
*/
	void addFlight(Flight* flight);
	/**
@brief Deletes a flight from the pilot
*/
	void deleteFlight(int id);
	/**
@brief Calculates the pilot's salary based on his category and flights
*/
	double calcSalary();
};


/**
@brief Flight crew, also an employee. Has flights and category 
*/
class FlightCrew : public Employee {
private:
	/**
@brief Flights crew category(A, B or C)
*/
	string category;//para simplificar apenas existem categorias A, B, C
	/**
@brief Flights the flight crew will realise
*/
	vector <Flight*> flights;
public:
	FlightCrew(string name, Date *birthDate, string category,vector <Flight*> flights);
	/**
@brief Returns the flight crew's category
*/
	string getCategory() const;
	/**
@brief Returns the flights the flight crew will realise
*/
	vector <Flight*> getFlights() const;
	/**
@brief Sets the flight crew's category
*/
	bool setCategory(string categ);
	/**
@brief Sets the flights the flight crew will realise
*/
	bool setFlights(vector<Flight*> &flights);
	/**
@brief Checks if the flight crew is free during the flight schedule recieved as parameter
*/
	bool isFree(FlightSched *check);
	/**
@brief Adds a flight to the flight crew
*/
	void addFlight(Flight* flight);
	/**
@brief Deletes a flight from the flight crew
*/
	void deleteFlight(int id);
	/**
@brief calculates the flight crew's salary
*/
	double calcSalary();
};



/**
@brief Administrator, also an employee. Has department and function
*/
class Admin : public Employee {
private:
	/**
@brief Department to which the admin belongs to
*/
	string department;
	/**
@brief Admin's function
*/
	string function;
public:
	Admin(string name, Date *birthDate, string department, string function);
	/**
@brief Returns the admin's department
*/
	string getDepartment() const;
	/**
@brief Returns the admin's function
*/
	string getFunction() const;
	/**
@brief Sets the admin's department
*/
	bool setDepartment(string depart);
	/**
@brief Sets the admin's function
*/
	bool setFunction(string func);
	/**
@brief Calculates the admin's salary
*/
	double calcSalary();
};


/**
@brief Base crew, also an employee. Has category and a working hour schedule
*/
class BaseCrew : public Employee {
private:
	/**
@brief Base crew's category
*/
	string category;
	/**
@brief Base crew's schedule
*/
	Schedule *schedule;
public:
	BaseCrew(string name, Date *birthDate, string category, Schedule *schedule);
	/**
@brief Returns the base crew's category
*/
	string getCategory() const;
	/**
@brief Returns the base crew's schedule
*/
	Schedule* getSchedule() const;
	/**
@brief Sets the base crew's category
*/
	bool setCategory(string categ);
	/**
@brief Sets the base crew's schedule
*/
	bool setSchedule(Schedule *sched);


	/**
@brief Calculates the base crew's salary
*/
	double calcSalary();
};


class InvalidName
{/**
@brief Name which caused the exeption
*/
	string name;
public:
	InvalidName(string name) { this->name = name; };
	/**
@brief Returns the name that caused the exeption
*/
	string getName() const { return name; };
};

class InvalidCategory
{/**
@brief Category which caused the exeption
*/
	string category;
public:
	InvalidCategory(string category) { this->category = category; };
	/**
@brief Return the category that caused the exeption
*/
	string getCategory() const { return category; };
};

class InvalidBirthDate
{/**
@brief Birth date which caused the exeption
*/
	string birthDate;
public:
	InvalidBirthDate(string date) { this->birthDate = date; };
	/**
@brief Returns the birthdate that caused the exeption
*/
	string getBirthDate() const { return birthDate; };
};

class InvalidPlaneTypes
{
	/**
@brief Plane type which caused the exeption
*/
	string planeTypes;
public:
	InvalidPlaneTypes(string planeTypes) { this->planeTypes = planeTypes; };
	/**
@brief Return the plane type that caused the exeption
*/
	string getPlaneTypes() const { return planeTypes; };
};

class FullCrew
{
	/**
@brief Message that indicates that the flights have a full flight crew
*/
	string msg;
public:
	FullCrew() { msg = "One of more of those flights have a full Flight crew!"; };
	/**
@brief Returns a message that indicates that the flights have a full flight crew
*/
	string getMsg() const { return msg; };
};

class NonExistantFlight
{
	/**
@brief Message that indicates that one or more flight IDs do not exist
*/
	string msg;
public:
	NonExistantFlight() { msg = "One of more of those flight ID's don't exist!"; };
	/**
@brief Returns a message that indicates that one or more flight IDs do not exist
*/
	string getMsg() const { return msg; };
};

class InvalidFlights
{/**
@brief Flights type which caused the exeption
*/
	string flights;
public:
	InvalidFlights(string flights) { this->flights = flights; };
	/**
@brief Return the flights that caused the exeption
*/
	string getFlights() const { return flights; };
};