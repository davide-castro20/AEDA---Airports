#include "Utils.h"
#include "Schedule.h"
#include "Time.h"
#include "Date.h"

using namespace std;

Schedule::Schedule() {}

Schedule::Schedule(Time &start, Time &end)
{
	this->startHour = start;
	this->endHour = end;
}

Time Schedule::getStartHour() const { return startHour; }

Time Schedule::getEndHour() const { return endHour; }

Time Schedule::getDuration() const
{
	Time duration;
	duration.setHours(endHour.getHours() - startHour.getHours());
	duration.setMinutes(endHour.getMinutes() - startHour.getMinutes());
	return duration;
}

void Schedule::setStartHour(Time &start)
{
	this->startHour = start;
}

void Schedule::setEndHour(Time &end)
{
	this->endHour = end;
}



/*---------------FLIGHT SCHEDULE-------------*/

FlightSched::FlightSched() {}

FlightSched::FlightSched(Date &departureD, Time &startHour, Date &arrivalD, Time &endHour) : Schedule(startHour, endHour)
{
	departureDate = departureD;
	arrivalDate = arrivalD;
}

Date FlightSched::getDepartureDate() const
{
	return departureDate;
}

Date FlightSched::getArrivalDate() const
{
	return arrivalDate;
}

Time FlightSched::getDuration() const
{
	Date departureD = departureDate;
	Date arrivalD = arrivalDate;
	Time start = this->getStartHour();
	Time end = this->getEndHour();
	unsigned int hours, minutes;
	if (departureD == arrivalD)
		return (end - start);
	else
	{
		hours = end.getHours() + (24 - start.getHours());
		minutes = end.getMinutes();
		if (start.getMinutes() > 0)
		{
			hours--;
			minutes += (60 - start.getMinutes());
		}
	}
	return Time(hours, minutes);
}


void FlightSched::setDepartureDate(Date & date)
{
	departureDate = date;
}

void FlightSched::setArrivalDate(Date & date)
{
	arrivalDate = date;
}


bool FlightSched::isValid() const
{
	Date departureD = departureDate;
	Date arrivalD = arrivalDate;
	Time departureH = this->getStartHour();
	Time arrivalH = this->getEndHour();
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
	return false;
}

