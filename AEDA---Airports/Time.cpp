#include "Utils.h"
#include "Time.h"

using namespace std;

Time::Time() {}

Time::Time(unsigned int hours, unsigned int minutes)
{
	this->hours = hours;
	this->minutes = minutes;
}

unsigned int Time::getHours() const { return hours; }

unsigned int Time::getMinutes() const { return minutes; }

void Time::setHours(unsigned int hours) 
{ 
	this->hours = hours; 
}

void Time::setMinutes(unsigned int minutes)
{
	this->minutes = minutes;
}

bool Time::isValid() const 
{
	if (hours <= 23 && hours >= 0 && minutes <= 59 && minutes >= 0)
		return true;
	else 
		return false;
}

bool Time::operator<(Time &time) const
{
	if (this->hours == time.hours)
	{
		if (this->minutes < time.minutes)
			return true;
	}
	else if (this->hours < time.hours)
		return true;
	else
		return false;
}
