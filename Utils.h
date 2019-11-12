#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Flight.h"


using namespace std;

class Flight;
class Plane;
class Employee;
class Date;


bool leapYear(int year);

int days(int year, int month);

vector<Flight*> convertIdToFlight(const vector<int> &flightIds, const vector<Flight*> &flights);

vector<Plane*> convertCatToPlane(const vector<string> &planeTypes, const vector<Plane*> &planes);

void trim(string &s); // Removes extra spaces from the begining and end of a string

void trimRight(string &s); // removes extra spaces from the end of a string

void trimLeft(string &s); // removes extra spaces from the beginning of a string

void decompose(string line, std::vector<std::string> &vect, char sep);

void decomposeInt(string line, std::vector<int> &vect, char sep);

bool existingDate(string &dt);

bool endLaterThenBeg(string &endD, string &begD); // returns "true" if the string "begD" is a date later then the date on the "endD" string

bool checkBetweenDates(std::string date1, std::string date2, Date date); // returns "true" if the object "date" is a date between "date1" and "date2"

bool checkInt2(std::string s); // returns "true" if a string "sentence" can be converted to an integer

int checkInt(string sentence); // asks for an integer input until the user gives a valid integer and then returns it

bool checkCats(const string &cats); // checks the string with plane types

vector <Flight*> addEmployeeToFlight(vector<Flight*>flights, vector<Employee*> employees);

bool notInFlight(Employee *employee, Flight* flight);