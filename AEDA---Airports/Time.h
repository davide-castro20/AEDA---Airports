#pragma once

#include "Utils.h"


class Time
{
private:
	unsigned int hours, minutes;

public:
	Time();
	Time(unsigned int hours, unsigned int minutes);
	unsigned int getHours() const;
	unsigned int getMinutes() const;
	unsigned int setHours(unsigned int hours);
	unsigned int setMinutes(unsigned int hours);
	bool isValid() const;
	bool operator<(Time &time) const;
};