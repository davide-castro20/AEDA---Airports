#include "Flight.h"
#include "Utils.h"
#include "Airport.h"

using namespace std;

Flight::Flight() 
{}

Flight::Flight(FlightSched &predictedSched, Airport *depart, Airport *destin, vector<Employee*> &crew)
{
	predictedSchedule = predictedSched;
	departure = depart;
	destination = destin;
	employees = crew;
}

bool Flight::isCanceled() const
{
	return canceled;
}

bool Flight::isCompleted() const
{
	return completed;
}

Airport* Flight::getDeparture() const
{
	return departure;
}

Airport* Flight::getDestination() const
{
	return destination;
}

vector<Employee*> Flight::getEmployees() const
{
	return employees;
}

FlightSched Flight::getRealSchedule() const
{
	return realSchedule;
}

FlightSched Flight::getPredictedSchedule() const
{
	return predictedSchedule;
}

Time Flight::getFlightDuration() const
{
	return realSchedule.getDuration();
}

void Flight::setPredictedSchedule(FlightSched &predicted)
{
	predictedSchedule = predicted;
}

void Flight::setRealSchedue(FlightSched & real)
{
	realSchedule = real;
}

void Flight::setCanceled(bool cancel)
{
	canceled = cancel;
}

void Flight::setCompleted(bool complete)
{
	completed = complete;
}

void Flight::setDeparture(Airport * depart)
{
	departure = depart;
}

void Flight::setDestination(Airport * destin)
{
	destination = destin;
}

void Flight::setCrew(vector<Employee*>& crew)
{
	employees = crew;
}
