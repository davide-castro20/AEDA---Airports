#include "Plane.h"

float Plane::calcExp(string type, int capacity, vector<Flight*> &flights) const
{
	if(type == "A")
		return 100 + flights.size()
}

Plane::Plane(string type, int capacity, vector<Flight*> &flights)
{
	this->type = type;
	this->capacity = capacity;
	this->flights = flights;
	this->expenses = calcExp(type, flights);
}
