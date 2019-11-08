#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Flight.h"

using namespace std;

class Flight;


bool badInput=true;

bool leapYear(int year);

int days(int year, int month);

vector<Flight*> convertIdToFlight(const vector<int> &flightIds, const vector<Flight*> &flights);

vector<Plane*> convertCatToPlane(const vector<string> &planeTypes, const vector<Plane*> &planes);

void trim(string &s); // Removes extra spaces from the begining and end of a string

void trimRight(string &s); // removes extra spaces from the end of a string

void trimLeft(string &s); // removes extra spaces from the beginning of a string

void decompose(string line, std::vector<std::string> &vect, char sep);

void decomposeInt(string line, std::vector<int> &vect, char sep);