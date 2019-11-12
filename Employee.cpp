#include "Employee.h"

using namespace std;

Employee::Employee(string name, Date *birthDate,string type) {
	this->name = name;
	this->birthDate = birthDate;
	this->type = type;
}

string Employee::getName() const{
	return this->name;
}


Date Employee::getDate() const{
	return *birthDate;
}

double Employee::getSalary() const{
	return this->salary;
}

string Employee::getType() const {
	return this->type;
}

bool Employee::setName(string name) {
	if (name == "")
	{
		cout << "|There was an error with the selection of the name, please try again.\n";
		return false;
	}
	if (!isupper(name.at(0)))
	{
		cout << "|There was an error with the selection of the name, please try again.\n";
		return false;
	}
	for (size_t i = 0; i < name.length(); i++) {
		if (isdigit(name.at(i)))
		{
			cout << "|There was an error with the selection of the name, please try again.\n";
			return false;
		}
	}
	this->name=name;
	return true;
}

bool Employee::setDate(Date *birthDate) {
	if (birthDate->isValid()) {
		this->birthDate = birthDate;
		return true;
	}
	return false;
}

bool Employee::setSalary(float salary) {
	if (salary < 0)
		return false;
	this->salary = salary;
	return true;
}

bool Employee::operator==(Employee &emp2)
{
	return ((this->name == emp2.name) && (this->birthDate == emp2.birthDate));
}
	
Pilot::Pilot(string name, Date *birthDate, string category, vector <Plane*> &planes, vector <Flight*> &flights) : Employee(name, birthDate, "Pilot") {
	this->category = category;
	this->planes = planes;
	this->flights = flights;
}

string Pilot::getCategory() const {
	return category;
}

vector <Plane*> Pilot::getPlanes() const {
	return planes; 
}

string Pilot::getPlaneTypes() const
{
	vector<string> types;
	string typesS;
	bool in = false;
	for (size_t i = 0; i < planes.size(); i++)
	{
		for (size_t j = 0; j < types.size(); j++)
			if (planes.at(i)->getType() == types.at(j))
			{
				in = true;
			}
		if (!in)
			types.push_back(planes.at(i)->getType());
		in = false;
	}
	if (types.size() == 1)
		return types.at(0);
	else if (types.size() == 2)
		return types.at(0) + ", " + types.at(1);
	else
		return types.at(0) + ", " + types.at(1) + ", " + types.at(2);
}

vector <Flight*> Pilot::getFlights() const {
	return flights;
}

bool Pilot::setCategory(string categ)
{
	if (categ == "A" || categ == "B" || categ == "C") {
		category = categ;
		return true;
	}
	return false;
}

bool Pilot::setFlights(vector<Flight*>& flights)
{
	this->flights = flights;
	return true;
}

bool Pilot::setPlanes(vector<Plane*>& planes)
{
	this->planes = planes;
	return true;
}

double Pilot::calcSalary() {
	double total;
	if (category == "A")
		total = 100.0 * flights.size();
	if (category == "B")
		total = 150.0 * flights.size();
	if (category == "C")
		total = 200.0 * flights.size();
	for (size_t i = 0; i < flights.size(); i++)
		total += (5/60) * flights.at(i)->getFlightDuration().getTotalMinutes(); //random formula
	return total;
}

FlightCrew::FlightCrew(string name, Date *birthDate, string category, vector <Flight*> flights):Employee(name, birthDate,"Flight Crew") {
	this->category = category;
	this->flights = flights;
}

string FlightCrew::getCategory() const {
	return category;
}


vector <Flight*> FlightCrew::getFlights() const {
	return flights;
}

bool FlightCrew::setCategory(string categ)
{
	if (categ == "A" || categ == "B" || categ == "C") {
		category = categ;
		return true;
	}
	return false;
}

bool FlightCrew::setFlights(vector<Flight*>& flights)
{
	this->flights = flights;
	return true;
}

double FlightCrew::calcSalary() {
	double total;
	if (category == "A")
		total = 50.0 * flights.size();
	if (category == "B")
		total = 75.0 * flights.size();
	if (category == "C")
		total = 100.0 * flights.size();
	for (size_t i = 0; i < flights.size(); i++)
		total += (3 / 60) * flights.at(i)->getFlightDuration().getTotalMinutes(); //random formula
	return total;
}

Admin::Admin(string name, Date *birthDate, string department, string function) :Employee(name, birthDate,"Admin") {
	this->department = department;
	this->function = function;
}

string Admin::getDepartment() const {
	return department;
}

string Admin::getFunction() const {
	return function;
}

bool Admin::setDepartment(string depart) {
	for (size_t i = 0; i < depart.length(); i++) {
		if (isdigit(depart.at(i)))
			return false;
	}
	department= depart;
	return true;
}

bool Admin::setFunction(string func) {
	for (size_t i = 0; i < func.length(); i++) {
		if (isdigit(func.at(i)))
			return false;
	}
	function = func;
	return true;
}


double Admin::calcSalary() {
	return 3000;
}

BaseCrew::BaseCrew(string name, Date *birthDate, string category, Schedule *schedule) :Employee(name, birthDate,"Base Crew"){
	this->category = category;
	this->schedule = schedule;
}

string BaseCrew::getCategory() const {
	return category;
}

Schedule* BaseCrew::getSchedule() const{
	return schedule;
}

bool BaseCrew::setCategory(string categ)
{
	if (categ == "A"|| categ == "B" || categ == "C") {
		category = categ;
		return true;
	}
	return false;
}

bool BaseCrew::setSchedule(Schedule *sched)
{
	if (sched->isValid()) {
		schedule = sched;
		return true;
	}
	return false;
}


double BaseCrew::calcSalary() {
	return 1500;
}

bool Pilot::isFree(FlightSched *check)
{
	for (size_t i = 0; i < flights.size(); i++)
	{
		if (check->getDepartureDate() < flights.at(i)->getPredictedSchedule().getDepartureDate() && flights.at(i)->getPredictedSchedule().getDepartureDate() < check->getArrivalDate())
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
		else if (check->getDepartureDate() == flights.at(i)->getPredictedSchedule().getDepartureDate() && check->getArrivalDate() == flights.at(i)->getPredictedSchedule().getArrivalDate() && check->getStartHour() == flights.at(i)->getPredictedSchedule().getStartHour() && check->getEndHour() == flights.at(i)->getPredictedSchedule().getEndHour())
			return false;
	}
	return true;
}

void Pilot::addFlight(Flight * flight)
{
	this->flights.push_back(flight);
}

bool FlightCrew::isFree(FlightSched *check)
{
	cout << name << endl;
	for (size_t i = 0; i < flights.size(); i++)
	{
		if (check->getDepartureDate() < flights.at(i)->getPredictedSchedule().getDepartureDate() && flights.at(i)->getPredictedSchedule().getDepartureDate() < check->getArrivalDate())
			return false;
		else if (check->getDepartureDate() < flights.at(i)->getPredictedSchedule().getArrivalDate() && flights.at(i)->getPredictedSchedule().getArrivalDate() < check->getArrivalDate())
			return false;
		else if (check->getArrivalDate() == flights.at(i)->getPredictedSchedule().getDepartureDate() && !(check->getEndHour() < flights.at(i)->getPredictedSchedule().getStartHour()))
			return false;
		else if (check->getDepartureDate() == flights.at(i)->getPredictedSchedule().getArrivalDate() && !(flights.at(i)->getPredictedSchedule().getEndHour() < check->getStartHour()))
			return false;
	}
	return true;
}

void FlightCrew::addFlight(Flight * flight)
{
	this->flights.push_back(flight);
}

void Pilot::deleteFlight(int id)
{
	for (size_t i = 0; i < flights.size(); i++)
		if (flights.at(i)->getId() == id)
		{
			flights.erase(flights.begin() + i);
			return;
		}
}

void FlightCrew::deleteFlight(int id)
{
	for (size_t i = 0; i < flights.size(); i++)
		if (flights.at(i)->getId() == id)
		{
			flights.erase(flights.begin() + i);
			return;
		}
}
