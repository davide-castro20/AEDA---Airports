#pragma once

#include "Schedule.h"
#include "Employee.h"

class FlightSched;
class Employee;
class Schedule;
class Time;



/**
@brief A flight with schedule and destination. Also a tripulation of 4, 2 pilots, 2 flight crew and a plane
*/
class Flight
{
private:
	/**
@brief Flight's ID
*/
	int id;/**
@brief Flight's real schedule (with the delays caused)
*/
	FlightSched *realSchedule;
	/**
@brief Flight's predicted schedule(the one from the .txt)
*/
	FlightSched *predictedSchedule;
	/**
@brief Flight's destination
*/
	string destination;
	/**
@brief Flight's employees (2 pilots and 2 flight crew members)
*/
	vector<Employee*> employees;
	/**
@brief Flight's plane
*/
	Plane* plane;

public:
	Flight();
	Flight(FlightSched *predictedSched, string destino, vector<Employee*> &crew, Plane* plane, int id);
	/**
@brief Returns the flight's employees
*/
	vector<Employee*> getEmployees() const;
	/**
@brief Returns the flight's pilots
*/
	vector<Employee*> getPilots() const;
	/**
@brief Returns the flight's flight crew
*/
	vector<Employee*> getCrew() const;
	/**
@brief Returns the flights's real schedule
*/
	FlightSched getRealSchedule() const;
	/**
@brief Returns the flight's predicted
*/
	FlightSched getPredictedSchedule() const;
	/**
@brief Returns the flight's duration
*/
	Time getFlightDuration() const;
	/**
@brief Returns the flight's id
*/
	int getId() const;
	/**
@brief Returns the flight's destination
*/
	string getDestination() const;
	/**
@brief Returns the flight's plane
*/
	Plane* getPlane() const;
	/**
@brief Sets the flight's precisted schedule
*/
	bool setPredictedSchedule(FlightSched *predicted);
	/**
@brief Sets the flight's real schedule
*/
	void setRealSchedue(FlightSched *real);
	/**
@brief Sets the flight's destination
*/
	void setDestination(string destination);
	/**
@brief Sets the flight's crew
*/
	bool setCrew(vector<Employee*> crew);
	/**
@brief Sets the flight's crew member
*/
	bool setCrewMemb(Employee* memb);
	/**
@brief Sets the flight's plane
*/
	bool setPlane(Plane * plane);
	/**
@brief Deletes a flight's crew member
*/
	bool deleteCrew(Employee * emp);
};