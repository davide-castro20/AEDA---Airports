#pragma once

#include "Utils.h"

using namespace std;

class Time
{
private:
	/**
@brief Time's hours
*/
	unsigned int hours;
	/**
@brief Time's minutes
*/
	unsigned int minutes;

public:
	Time();
	Time(unsigned int hours, unsigned int minutes);
	/**
@brief Returns the hours of the "Time" object
*/
	unsigned int getHours() const;
	/**
@brief Returns the minutes of the "Time" object
*/
	unsigned int getMinutes() const;
	/**
@brief Returns the total minutes of the "Time" object
*/
	unsigned int getTotalMinutes() const;
	/**
@brief Sets the hours of the "Time" object
*/
	void setHours(unsigned int hours);
	/**
@brief Sets the minutes of the "Time" object
*/
	void setMinutes(unsigned int hours);
	/**
@brief Checks if time is valid
*/
	bool isValid() const;
	/**
@brief Compares if the time is before than the one recived in the parameter
*/
	bool operator<(const Time &time) const;
	/**
@brief Compares if the ´time is equal to the one recived in the parameter
*/
	bool operator==(const Time &time) const;
	/**
@brief Returns the diference between the time and the one received in the parameter
*/
	Time operator-(Time &time) const;
	/**
@brief Shows the time in a user friendly way
*/
	friend ostream& operator<<(ostream& out, const Time& time);
	/**
@brief Returns a string with a formated time
*/
	string getTime() const;
};