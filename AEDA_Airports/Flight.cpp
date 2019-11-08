#include "Flight.h"


using namespace std;

Flight::Flight() 
{}

Flight::Flight(FlightSched &predictedSched, string destino, vector<Employee*> &crew, int id)
{
	predictedSchedule = predictedSched;
	this->id = id;
	destination = destino;
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

int Flight::getId() const
{
	return id;
}

string Flight::getDestination() const
{
	return destination;
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

void Flight::setDestination(string destination)
{
	this->destination = destination;
}

//void Flight::setDeparture(Airport * depart)
//{
//	departure = depart;
//}
//
//void Flight::setDestination(Airport * destin)
//{
//	destination = destin;
//}

void Flight::setCrew(vector<Employee*>& crew)
{
	employees = crew;
}
