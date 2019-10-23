#include "Utils.h"
#include "Schedule.h"
#include "Time.h"
#include "Date.h"

using namespace std;

Schedule::Schedule() {}

Schedule::Schedule(Time &start, Time &end)
{
	this->start = start;
	this->end = end;
}

Time Schedule::getStart() const { return start; }

Time Schedule::getEnd() const { return end; }

Time Schedule::getDuration() const
{
	Time duration;
	duration.setHours(end.getHours() - start.getHours());
	duration.setMinutes(end.getMinutes() - start.getMinutes());
	return duration;
}

void Schedule::setStart(Time &start)
{
	this->start = start;
}

void Schedule::setEnd(Time &end)
{
	this->end = end;
}



/*---------------FLIGHT SCHEDULE-------------*/

FlightSched::FlightSched() {}

FlightSched::FlightSched(Date departureD, Time departureH, Date arrivalD, Time arrivalH)
{
	departureDate = departureD;
	departureHour = departureH;
	arrivalDate = arrivalD;
	arrivalHour = arrivalH;
}

Date FlightSched::getDepartureDate() const
{
	return Date();
}

Date FlightSched::getArrivalDate() const
{
	return Date();
}

Time FlightSched::getDepartureHour() const
{
	return Time();
}

Time FlightSched::getArrivalHour() const
{
	return Time();
}

void FlightSched::setDepartureDate(Date & date)
{
	departureDate = date;
}

void FlightSched::setArrivalDate(Date & date)
{
	arrivalDate = date;
}

void FlightSched::setDepartureHour(Time & time)
{
	departureHour = time;
}

void FlightSched::setArrivalHour(Time & time)
{
	arrivalHour = time;
}

bool FlightSched::isValid() const
{
	Date departureD = departureDate;
	Date arrivalD = arrivalDate;
	Time departureH = departureHour;
	Time arrivalH = arrivalHour;
	if (departureD.isValid() && arrivalD.isValid() && departureH.isValid() && arrivalH.isValid())
	{
		if (departureD == arrivalD) //por alguma razao nao me deixa igualar departureDate e arrivalDate
		{
			if (departureH < arrivalH)
				return true;
		}
		else if (departureD < arrivalD)
			return true;
		else return false;
	}
	else return false;
}

