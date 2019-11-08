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
	FlightSched realSchedule;
	FlightSched predictedSchedule;
	bool canceled = false;
	bool completed = false;
	string destination;
	vector<Employee*> employees;

public:
	Flight();
	Flight(FlightSched &predictedSched, string destino, vector<Employee*> &crew, int id);
	bool isCanceled() const;
	bool isCompleted() const;
	/*Airport* getDeparture() const;
	Airport* getDestination() const;*/
	vector<Employee*> getEmployees() const;
	FlightSched getRealSchedule() const;
	FlightSched getPredictedSchedule() const;
	Time getFlightDuration() const;
	int getId() const;
	string getDestination() const;
	void setPredictedSchedule(FlightSched &predicted);
	void setRealSchedue(FlightSched &real);
	void setCanceled(bool cancel);
	void setCompleted(bool complete);
	void setDestination(string destination);
	/*
	void setDeparture(Airport *depart);
	void setDestination(Airport *destin);*/
	void setCrew(vector<Employee*> &crew);
};