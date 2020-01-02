#pragma once

#include "Flight.h"

using namespace std;


class Flight;
class FlightSched;


/**
@brief Capacity error class
*/
class capacityError
{
	/**
@brief Saves the capacity which caused the error
*/
public:
	/**
@brief Planes capacity
*/
	int inputCapacity;
	capacityError(int inputCapacity) { this->inputCapacity = inputCapacity;}
	/**
@brief Shows the error in a user friendly way
*/
	friend ostream & operator <<(ostream &out, const capacityError &error);
};


/**
@brief A plane, with type, capacity and flights it will do
*/
class Plane
{
private:
	/**
@brief Planes' type ("A","B" or "C")
*/
	string type; //para simplificar apenas existem modelos A, B, C.
	/**
@brief Planes' capacity
*/
	int capacity;
	/**
@brief Planes' flights
*/
	vector<Flight*> flights; //não esquecer de usar new
	/**
@brief Planes' expenses
*/
	double expenses;
	/**
@brief Plane's mean waiting time
*/
	int meanTime;
public:
	Plane(string type, int capacity, vector<Flight*> &flights);
	/**
@brief Calculates the planes expenses
*/
	double calcExp() const;
	/**
@brief Returns the planes' type
*/
	string getType() const;
	/**
@brief Returns the planes' capacity
*/
	int getCapacity() const;
	/**
@brief Returns the planes' flights
*/
	vector<Flight*> getFlights() const;
	/**
@brief Sets the planes' capacity
*/
	bool setCapacity(int cap);
	/**
@brief Sets the planes' type
*/
	bool setType(string type);
	/**
@brief Sets the planes' flights
*/
	bool setFlights(vector<Flight*> fly);
	/**
@brief Checks if plane is free at some flight schedule
*/
	bool isFree(FlightSched *check);
	/**
@brief Adds a flight to the plane
*/
	void addFlight(Flight* flight);
	/**
@brief Deletes a flight from a plane
*/
	void deleteFlight(int id);
	/**
@brief Returns the mean time the plane waits in the runway
*/
	int getMeanTime() const { return this->meanTime; };
};