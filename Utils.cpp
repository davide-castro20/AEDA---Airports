#include "Utils.h"


bool leapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	else if (year % 4 == 0 && year % 400 == 0)
		return true;
	return false;
}

int days(int year, int month)
{
	int d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month == 2 && leapYear(year))
		return 29;
	else
		return d[month - 1];
}

std::vector<Flight*> convertIdToFlight(std::vector<int> &flightIds, const std::vector<Flight*> &flights)
{
	std::vector<Flight*> flightsConv;
	for (size_t i = 0; i < flightIds.size(); i++)
	{
		for (size_t j = 0; j < flights.size(); j++)
		{
			if (flightIds.at(i) == flights.at(j)->getId())
			{
				flightsConv.push_back(flights.at(j));
				break;
			}
		}
	}
	return flightsConv;
}

std::vector<Plane*> convertCatToPlane(const std::vector<string>& planeTypes, const std::vector<Plane*>& planes)
{
	std::vector<Plane*> planesConv;
	for (size_t i = 0; i < planeTypes.size(); i++)
	{
		for (size_t j = 0; j < planes.size(); j++)
		{
			if (planeTypes.at(i) == planes.at(j)->getType())
			{
				planesConv.push_back(planes.at(j));
				break;
			}
		}
	}
}

void trimLeft(string &s)
{
	s.erase(0, s.find_first_not_of(" "));
}


void trimRight(string &s)
{
	s.erase(s.find_last_not_of(" ") + 1);
}

void trim(string &s)
{
	trimLeft(s);
	trimRight(s);
}

void decompose(std::string line, std::vector<std::string>& vect, char sep)
{
	istringstream iS(line);
	vector<string> elems;
	string elem;
	while (getline(iS, elem, ','))
	{
		trim(elem);
		if (elem != "" && elem.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos)
			elems.push_back(elem);
	}
	vect = elems;
}

void decomposeInt(std::string line, std::vector<int>& vect, char sep)
{
	istringstream iS(line);
	vector<int> elems;
	string elem;
	while (getline(iS, elem, ','))
	{
		trim(elem);
		if (elem != "" && elem.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ ") == string::npos)
			elems.push_back(stoi(elem));
	}
	vect = elems;
}

