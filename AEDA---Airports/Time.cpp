#include "Utils.h"

#include <iostream>
#include <string>
#include <vector>

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

bool Time::isValid() const 
{
	if (hours <= 23 && hours >= 0 && minutes <= 59 && minutes >= 0)
		return true;
	else 
		return false;
}