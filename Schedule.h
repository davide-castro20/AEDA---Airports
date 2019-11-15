#pragma once

#include "Time.h"
#include "Date.h"

class Date;
class Time;

using namespace std;

class InvalidSchedule
{
	/**
@brief Starting hours of the schedule that caused the error
*/
	Time *startHour;
	/**
@brief Ending hours of the schedule that caused the error
*/
	Time *endHour;
public:
	InvalidSchedule(Time *start, Time *end);
};

class InvalidFlightSched
{
	/**
@brief Starting hours of the flight schedule that caused the error
*/
	Time *startHour;
	/**
@brief Ending hours of the flight schedule that caused the error
*/
	Time *endHour;
	/**
@brief Departure date of the flight schedule that caused the error
*/
	Date *departureDate;
	/**
@brief Arrival date of the flight schedule that caused the error
*/
	Date *arrivalDate;
public:
	InvalidFlightSched(Date * departureD, Time * startH, Date * arrivalD, Time * endH);
};

class Schedule
{
protected:
	/**
@brief Starting hours of the schedule
*/
	Time *startHour;
	/**
@brief Ending hours of the schedule
*/
	Time *endHour;

public:
	Schedule();
	Schedule(Time *start, Time *end);
	/**
@brief Returns the starting hours of the schedule
*/
	Time getStartHour() const;
	/**
@brief Returns the ending hours of the schedule
*/
	Time getEndHour() const;
	/**
@brief Returns the schedule duration
*/
	virtual Time getDuration() const;
	/**
@brief Sets the starting hours of the schedule
*/
	void setStartHour(Time *start);
	/**
@brief Sets the ending hours of the schedule
*/
	void setEndHour(Time *end);
	/**
@brief Checks if schedule is valid
*/
	virtual bool isValid() const;
	/**
@brief Returns the schedule in a string format
*/
	virtual string getSched() const;
	
};

ostream& operator<<(ostream &out, const Schedule &sched);

class FlightSched : public Schedule
{
private:
	/**
@brief Departing date of the flight schedule
*/
	Date *departureDate;
	/**
@brief Arriving date of the flight schedule
*/
	Date *arrivalDate;
public:
	FlightSched();
	FlightSched(Date *departureD, Time *startHour, Date *arrivalD, Time *endHour);
	/**
@brief Returns the departure date of the flight schedule
*/
	Date getDepartureDate() const;
	/**
@brief Returns the arrival date of the flight schedule
*/
	Date getArrivalDate() const;
	/**
@brief Returns the duration of the flight schedule
*/
	Time getDuration() const;
	/**
@brief Sets the departure date of the flight schedule
*/
	void setDepartureDate(Date *date);
	/**
@brief Sets the arrival date of the flight schedule
*/
	void setArrivalDate(Date *date);

	/**
@brief Checks if flight schedule is valid
*/
	bool isValid() const;
	/**
@brief Returns the schedule in a string format
*/
	string getSched() const;
};