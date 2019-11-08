#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Flight.h"

bool badInput=true;

bool leapYear(int year);

int days(int year, int month);

std::vector<Flight*> convertIdToFlight(const std::vector<int> &flightIds, const std::vector<Flight*> &flights);

std::vector<Plane*> convertCatToPlane(const std::vector<string> &planeTypes, const std::vector<Plane*> &planes);

void trim(std::string &s); // Removes extra spaces from the begining and end of a string

void trimRight(std::string &s); // removes extra spaces from the end of a string

void trimLeft(std::string &s); // removes extra spaces from the beginning of a string

void decompose(std::string line, std::vector<std::string> &vect, char sep);

void decomposeInt(std::string line, std::vector<int> &vect, char sep);