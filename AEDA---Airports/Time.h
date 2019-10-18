#pragma once

#include "Utils.h"

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Time
{
private:
	unsigned int hours, minutes;

public:
	Time();
	Time(unsigned int hours, unsigned int minutes);
	unsigned int getHours() const;
	unsigned int getMinutes() const;
	bool isValid() const;
	bool operator<(Time &time) const;
};