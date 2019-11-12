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

unsigned int Time::getTotalMinutes() const
{
	return hours * 60 + minutes;
}

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

bool Time::operator<(const Time &time) const
{
	if (this->hours == time.hours)
	{
		if (this->minutes < time.minutes)
			return true;
	}
	else if (this->hours < time.hours)
		return true;
	return false;
}

Time Time::operator-(Time & time) const
{
	unsigned int hours = this->hours;
	unsigned int minutes = this->minutes;
	if (time.getMinutes() > this->minutes)
	{
		hours = this->hours - 1;
		minutes += 60;
	}
	minutes = minutes - time.getMinutes();
	hours = hours - time.getHours();

	return Time(hours, minutes);

}

string Time::getTime() const
{
	string time;
	if (hours <= 9)
	{
		if (minutes <= 9)
			time = '0' + to_string(hours) + ':' + '0' + to_string(minutes);
		else
			time = '0' + to_string(hours) + ':' + to_string(minutes);
	}
	else
	{
		if (minutes <= 9)
			time = to_string(hours) + ':' + '0' + to_string(minutes);
		else
			time = to_string(hours) + ':' + to_string(minutes);
	}
	return time;
}

ostream& operator<<(ostream& out, const Time& time)
{
	out << right << setw(2) << setfill('0') << time.hours << ':' << setw(2) << setfill('0') << time.minutes;
	return out;
}

bool Time::operator==(const Time &time) const
{
	return this->getHours() == time.getHours() && this->getMinutes() == time.getMinutes();
}
