#pragma once

#include "Utils.h"

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
	unsigned int getTotalMinutes() const;
	void setHours(unsigned int hours);
	void setMinutes(unsigned int hours);
	bool isValid() const;
	bool operator<(const Time &time) const;
	bool operator==(const Time &time) const;
	Time operator-(Time &time) const;
	friend ostream& operator<<(ostream& out, const Time& time);
	string getTime() const;
};