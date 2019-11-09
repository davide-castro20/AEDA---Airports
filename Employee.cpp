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
	if (!isupper(name.at(0)))
		return false;
	for (size_t i = 0; i < name.length(); i++) {
		if(isdigit(name.at(i)))
			return false;
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
	
Pilot::Pilot(string name, Date *birthDate, string category, vector <Plane*> planes, vector <Flight*> flights,string type) :Employee(name, birthDate, type) {
	this->category = category;
	this->planes = planes;
	this->flights = flights;
}

string Pilot::getCategory() const {
	return category;
}

vector <Plane*> Pilot::getPlane() const {
	return planes; 
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

FlightCrew::FlightCrew(string name, Date *birthDate, string category, vector <Flight*> flights,string type):Employee(name, birthDate,type) {
	this->category = category;
	this->flights = flights;
}

string FlightCrew::getCategory() {
	return category;
}


vector <Flight*> FlightCrew::getFlights() {
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

Admin::Admin(string name, Date *birthDate, string department, string function,string type) :Employee(name, birthDate,type) {
	this->department = department;
	this->function = function;
}

string Admin::getDepartment() {
	return department;
}

string Admin::getFunction() {
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

BaseCrew::BaseCrew(string name, Date *birthDate, string category, Schedule *schedule,string type) :Employee(name, birthDate,type){
	this->category = category;
	this->schedule = schedule;
}

string BaseCrew::getCategory() {
	return category;
}

Schedule BaseCrew::getSchedule() {
	return *schedule;
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