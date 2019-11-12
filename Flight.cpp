#include "Flight.h"



using namespace std;

Flight::Flight()
{}

Flight::Flight(FlightSched *predictedSched, string destino, vector<Employee*> &crew, Plane* plane, int id)
{
	static int flightIds = -1;
	if (id != -2)
	{
		if (id > flightIds)
			flightIds = id;
		this->id = id;
	}
	else
	{
		this->id = flightIds;
		flightIds++;
	}
	this->plane = plane;
	predictedSchedule = predictedSched;
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

vector<Employee*> Flight::getPilots() const
{
	vector<Employee*> pilots;
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees.at(i)->getType() == "Pilot")
			pilots.push_back(employees.at(i));
	}
	return pilots;
}

vector<Employee*> Flight::getCrew() const
{
	vector<Employee*> crew;
	for (size_t i = 0; i < employees.size(); i++)
	{
		if (employees.at(i)->getType() == "Flight Crew")
			crew.push_back(employees.at(i));
	}
	return crew;
}

FlightSched Flight::getRealSchedule() const
{
	return *realSchedule;
}

FlightSched Flight::getPredictedSchedule() const
{
	return *predictedSchedule;
}

Time Flight::getFlightDuration() const
{
	return predictedSchedule->getDuration();
}

int Flight::getId() const
{
	return id;
}

string Flight::getDestination() const
{
	return destination;
}

Plane * Flight::getPlane() const
{
	return plane;
}

bool Flight::setPredictedSchedule(FlightSched *predicted)
{
	if (predicted->isValid()) {
		predictedSchedule = predicted;
		return true;
	}
	return false;
	
}

void Flight::setRealSchedue(FlightSched * real)
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

bool Flight::setCrew(vector<Employee*>crew)
{
	employees = crew;
	return true;
}

bool Flight::setCrewMemb(Employee * memb)
{
	employees.push_back(memb);
	return true;
}

bool Flight::setPlane(Plane * plane)
{
	this->plane = plane;
	return true;
}

bool Flight::deleteCrew(Employee * emp)
{
	for(size_t i=0;i<employees.size();i++)
		if (emp == employees.at(i))
		{
			employees.erase(employees.begin() + i);
			return true;
		}
	return false;
}
