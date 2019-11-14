#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Flight.h"
#include "Plane.h"
#include "Employee.h"


using namespace std;

class Flight;
class Plane;
class Employee;
class Date;

/**
@brief Checks if year is a leap year
*/
bool leapYear(int year);

/**
@brief Number of days of a month
*/
int days(int year, int month);

/**
@brief Converts ID to flight
*/
vector<Flight*> convertIdToFlight(const vector<int> &flightIds, const vector<Flight*> &flights);

/**
@brief Converts categorys to plane
*/
vector<Plane*> convertCatToPlane(const vector<string> &planeTypes, const vector<Plane*> &planes);

/**
@brief Trims string s
*/
void trim(string &s); // Removes extra spaces from the begining and end of a string

/**
@brief Trims right side of a string
*/
void trimRight(string &s); // removes extra spaces from the end of a string


/**
@brief Trims left side of a string
*/
void trimLeft(string &s); // removes extra spaces from the beginning of a string
/**
@brief Decomposes a string
*/
void decompose(string line, std::vector<std::string> &vect, char sep);
/**
@brief Creates a string into ints
*/
void decomposeInt(string line, std::vector<int> &vect, char sep);

/**
@brief Checks if date is valid
*/
bool existingDate(string &dt);

/**
@brief Checks if end date ends after begin date
*/
bool endLaterThenBeg(string &endD, string &begD); // returns "true" if the string "begD" is a date later then the date on the "endD" string

/**
@brief Checks if date is between date1 and date2
*/
bool checkBetweenDates(Date date1, Date date2, Date date); // returns "true" if the object "date" is a date between "date1" and "date2"

/**
@brief Checks if a string can be converted into int
*/
bool checkInt2(std::string s); // returns "true" if a string "sentence" can be converted to an integer


int checkInt(string sentence); // asks for an integer input until the user gives a valid integer and then returns it

/**
@brief Adds employee to flight
*/
vector <Flight*> addEmployeeToFlight(vector<Flight*>flights, vector<Employee*> employees);
/**
@brief Checks if employee is not in flight
*/
bool notInFlight(Employee *employee, Flight* flight);
/**
@brief Checks if a string has no accented characters
*/
bool noAccent(string name);
/**
@brief Calculates plane's expences between two dates
*/
double inBetween(Plane* obj, int month1, int month2, int year1, int year2);
/**
@brief Calculates employee's expences between two dates
*/
double inBetween(Employee* obj, int month1, int month2, int year1, int year2);