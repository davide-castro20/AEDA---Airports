#include "Plane.h"


double Plane::calcExp(string type, vector<Flight*> &flights) const
{
	double total = 0;
	if (type == "A") 
		total = 100.0 + flights.size() * 100.0;
	if (type == "B")
		total = 150.0 + flights.size() * 100.0;
	if (type == "C")
		total = 200.0 + flights.size() * 100.0;
	for (size_t i = 0; i < flights.size(); i++)
		total += (flights.at(i)->getFlightDuration().getTotalMinutes())*5.0;
	return total;
}


string Plane::getType() const
{
	return type;
}

int Plane::getCapacity() const
{
	return capacity;
}

vector<Flight*> Plane::getFlights() const
{
	return flights;
}

Plane::Plane(string type, int capacity, vector<Flight*> &flights)
{
	this->type = type;
	this->capacity = capacity;
	this->flights = flights;
	this->expenses = calcExp(type, flights);
}

ostream & operator <<(ostream &out, const capacityError &error)
{
	out << "Exeption was thrown trying to set the plane's capacity. Capacity received :" << error.inputCapacity; return out;
}

bool Plane::setCapacity(int cap)
{
	if (cap <= 0)
		return false;
	capacity = cap;
	return true;
}

bool Plane::setType(string type) {
	if (type == "A" || type == "B" || type == "C")
		return true;
	return false;
}

bool Plane::setFlights(vector<Flight*> fly)
{
	flights = fly;
	return true;
}

bool Plane::isFree(FlightSched *check)
{
	for (size_t i = 0; i < flights.size(); i++)
	{
		if ((check->getDepartureDate() == flights.at(i)->getPredictedSchedule().getDepartureDate()) && (flights.at(i)->getPredictedSchedule().getArrivalDate() == check->getArrivalDate()) && (check->getEndHour() == flights.at(i)->getPredictedSchedule().getEndHour()) && (check->getStartHour() == flights.at(i)->getPredictedSchedule().getStartHour()))
			return false;
		else if (check->getDepartureDate() < flights.at(i)->getPredictedSchedule().getDepartureDate() && flights.at(i)->getPredictedSchedule().getDepartureDate() < check->getArrivalDate())
		{
			return false;
		}
		else if (check->getDepartureDate() < flights.at(i)->getPredictedSchedule().getArrivalDate() && flights.at(i)->getPredictedSchedule().getArrivalDate() < check->getArrivalDate())
		{
			return false;
		}
		else if (check->getArrivalDate() == flights.at(i)->getPredictedSchedule().getDepartureDate() && !(check->getEndHour() < flights.at(i)->getPredictedSchedule().getStartHour()))
		{
			return false;
		}
		else if (check->getDepartureDate() == flights.at(i)->getPredictedSchedule().getArrivalDate() && !(flights.at(i)->getPredictedSchedule().getEndHour() < check->getStartHour()))
		{
			return false;
		}
	}
	return true;
}

void Plane::addFlight(Flight * flight)
{
	this->flights.push_back(flight);
}

void Plane::deleteFlight(int id)
{
	for (size_t i = 0; i < flights.size(); i++)
		if (flights.at(i)->getId() == id)
		{
			flights.erase(flights.begin() + i);
			return;
		}
}
