#pragma once

#include "Utils.h"
#include "Schedule.h"
#include "Employee.h"
#include "Airport.h"

class Airport;
class Employee;

class Flight
{
private:
	FlightSched realSchedule;
	FlightSched predictedSchedule;
	bool canceled = false;
	bool completed = false;
	Airport* departure;
	Airport* destination;
	vector<Employee*> employees;

public:
	Flight();
	Flight(FlightSched &predictedSched, Airport *depart, Airport *destin, vector<Employee*> &crew);
	bool isCanceled() const;
	bool isCompleted() const;
	Airport* getDeparture() const;
	Airport* getDestination() const;
	vector<Employee*> getEmployees() const;
	FlightSched getRealSchedule() const;
	FlightSched getPredictedSchedule() const;
	Time getFlightDuration() const;
	void setPredictedSchedule(FlightSched &predicted);
	void setRealSchedue(FlightSched &real);
	void setCanceled(bool cancel);
	void setCompleted(bool complete);
	void setDeparture(Airport *depart);
	void setDestination(Airport *destin);
	void setCrew(vector<Employee*> &crew);
};