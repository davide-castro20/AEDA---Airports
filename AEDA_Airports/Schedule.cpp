#include "Schedule.h"


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

bool Schedule::isValid() const
{
	Time start = startHour;
	Time end = endHour;
	if (start < end)
		return true;
	else
		return false;
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
	Time start = startHour;
	Time end = endHour;
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
	if (!isValid())
		throw InvalidFlightSched(departureDate, startHour, arrivalDate, endHour);
}

void FlightSched::setArrivalDate(Date & date)
{
	arrivalDate = date;
	if (!isValid())
		throw InvalidFlightSched(departureDate, startHour, arrivalDate, endHour);
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


InvalidFlightSched::InvalidFlightSched(Date & departureD, Time & startH, Date & arrivalD, Time & endH)
{
	startHour = startH;
	endHour = endH;
	departureDate = departureD;
	arrivalDate = arrivalD;
}

InvalidSchedule::InvalidSchedule(Time & start, Time & end)
{
	startHour = start;
	endHour = end;
}
