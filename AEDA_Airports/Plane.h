#pragma once

#include "Flight.h"

using namespace std;

class Flight;

//class capacityError
//{
//public:
//	int inputCapacity;
//	capacityError(int inputCapacity) { this->inputCapacity = inputCapacity;}
//};
//
//ostream & operator <<(ostream &out, const capacityError &error) 
//{
//	out << "Exeption was thrown trying to set the plane's capacity. Capacity received :" << error.inputCapacity; return out;
//}

class Plane
{
private:
	string type; //para simplificar apenas existem modelos A, B, C.
	int capacity;
	vector<Flight*> flights; //não esquecer de usar new
	float expenses;
public:
	Plane(string type, int capacity, vector<Flight*> &flights);
	float calcExp(string type, vector<Flight*> &flights) const;
	string getType() const;
	int getCapacity() const;
	vector<Flight*> getFlights() const;
	void setCapacity(int cap);
	bool setFlights(vector<Flight*> fly);
};