#pragma once

#include "Flight.h"

using namespace std;


class Flight;
class FlightSched;

class capacityError
{
public:
	int inputCapacity;
	capacityError(int inputCapacity) { this->inputCapacity = inputCapacity;}
	friend ostream & operator <<(ostream &out, const capacityError &error);
};

class Plane
{
private:

	string type; //para simplificar apenas existem modelos A, B, C.
	int capacity;
	vector<Flight*> flights; //não esquecer de usar new
	double expenses;
public:
	Plane(string type, int capacity, vector<Flight*> &flights);
	double calcExp(string type, vector<Flight*> &flights) const;
	string getType() const;
	int getCapacity() const;
	vector<Flight*> getFlights() const;
	bool setCapacity(int cap);
	bool setType(string type);
	bool setFlights(vector<Flight*> fly);
	bool isFree(FlightSched *check);
	void addFlight(Flight* flight);
};