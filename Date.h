#pragma once

#include "Utils.h"

using namespace std;

class Date {
private:
	/**
@brief Date's day
*/
	unsigned short day;
	/**
@brief Date's month
*/
	unsigned short month;
	/**
@brief Date's year
*/
	unsigned year;

public:
	// Constructors

	Date(); // Default constructor
	Date(string date); // constructor from a string date
	Date(unsigned short day, unsigned short month, unsigned year); // constructor from the separate elements of the date

	// GET methods
	/**
@brief Returns the day corresponding to the selecated "Date"
*/
	unsigned short getDay() const;
	/**
@brief Returns the month corresponding to the selecated "Date"
*/
	unsigned short getMonth() const;
	/**
@brief Returns the year corresponding to the selecated "Date"
*/
	unsigned getYear() const;
	/**
@brief Returns the string of the date corresponding to the selecated "Date"
*/
	string getDate() const; // get the date on the form of a string (year/month/day)

	// SET methods

	/**
@brief Sets the day in the selecated "Date"
*/
	void setDay(unsigned short day);
	/**
@brief Sets the month in the selecated "Date"
*/
	void setMonth(unsigned short month);
	/**
@brief Sets the day in the selecated "Date"
*/
	void setYear(unsigned year);

	// other methods

	/**
@brief Shows the "Date" in a user friendly way
*/
	friend ostream& operator<<(ostream& out, const Date & date); // overload of operator << (display the formatted date on a ostream)
	/**
@brief Compares if the date is smaller than the one recived in the parameter
*/
	bool operator<(const Date &date);
	/**
@brief Compares if the date is smaller or equal than the one recived in the parameter
*/
	bool operator<=(const Date &date);
	/**
@brief Compares if the date is equal to the one recived in the parameter
*/
	bool operator==(const Date &date);
	/**
@brief Checks if the date is valid
*/
	bool isValid();

};
