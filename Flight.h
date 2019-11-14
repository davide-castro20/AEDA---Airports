#pragma once

#include "Schedule.h"
#include "Employee.h"

class FlightSched;
class Employee;
class Schedule;
class Time;



class Flight
{
private:
	int id;
	FlightSched *realSchedule;
	FlightSched *predictedSchedule;
	string destination;
	vector<Employee*> employees;
	Plane* plane;

public:
	Flight();
	Flight(FlightSched *predictedSched, string destino, vector<Employee*> &crew, Plane* plane, int id);
	vector<Employee*> getEmployees() const;
	vector<Employee*> getPilots() const;
	vector<Employee*> getCrew() const;
	FlightSched getRealSchedule() const;
	FlightSched getPredictedSchedule() const;
	Time getFlightDuration() const;
	int getId() const;
	string getDestination() const;
	Plane* getPlane() const;
	bool setPredictedSchedule(FlightSched *predicted);
	void setRealSchedue(FlightSched *real);
	void setCanceled(bool cancel);
	void setCompleted(bool complete);
	void setDestination(string destination);
	bool setCrew(vector<Employee*> crew);
	bool setCrewMemb(Employee* memb);
	bool setPlane(Plane * plane);
	bool deleteCrew(Employee * emp);
};