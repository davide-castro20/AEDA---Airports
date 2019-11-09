#include "Employee.h"

using namespace std;

Employee::Employee()
{
}

Employee::Employee(string name, Date *birthDate) {
	this->name = name;
	this->birthDate = birthDate;
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
	
Pilot::Pilot()
{
}

//Pilot::Pilot(string name, Date * birthDate, char category, vector<Plane*>& planes, vector<Flight*>& flights)
//{
//}

Pilot::Pilot(string name, Date *birthDate, char category, vector <Plane*> &planes, vector <Flight*> &flights) : Employee(name, birthDate) {
	this->category = category;
	this->planes = planes;
	this->flights = flights;
}

char Pilot::getCategory() const {
	return category;
}

vector <Plane*> Pilot::getPlane() const {
	return planes; 
}

vector <Flight*> Pilot::getFlights() const {
	return flights;
}

void Pilot::setCategory(char categ)
{
	category = categ;
}

void Pilot::setFlights(vector<Flight*>& flights)
{
	this->flights = flights;
}

void Pilot::setPlanes(vector<Plane*>& planes)
{
	this->planes = planes;
}

double Pilot::calcSalary() {
	double total;
	if (category == 'A')
		total = 100.0 * flights.size();
	if (category == 'B')
		total = 150.0 * flights.size();
	if (category == 'C')
		total = 200.0 * flights.size();
	for (size_t i = 0; i < flights.size(); i++)
		total += (5/60) * flights.at(i)->getFlightDuration().getTotalMinutes(); //random formula
	return total;
}

FlightCrew::FlightCrew()
{
}

FlightCrew::FlightCrew(string name, Date *birthDate, string category, vector <Flight*> flights):Employee(name, birthDate) {
	this->category = category;
	this->flights = flights;
}

string FlightCrew::getCategory() {
	return category;
}


vector <Flight*> FlightCrew::getFlights() {
	return flights;
}

void FlightCrew::setCategory(string categ)
{
	category = categ;
}

void FlightCrew::setFlights(vector<Flight*>& flights)
{
	this->flights = flights;
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

Admin::Admin(string name, Date *birthDate, string department, string function) :Employee(name, birthDate) {
	this->department = department;
	this->function = function;
}

string Admin::getDepartment() {
	return department;
}

string Admin::getFunction() {
	return function;
}

double Admin::calcSalary() {
	return 3000;
}

BaseCrew::BaseCrew(string name, Date *birthDate, string category, Schedule *schedule) :Employee(name, birthDate){
	this->category = category;
	this->schedule = schedule;
}

string BaseCrew::getCategory() {
	return category;
}

Schedule BaseCrew::getSchedule() {
	return *schedule;
}

void BaseCrew::setCategory(string categ)
{
	category = categ;
}

void BaseCrew::setSchedule(Schedule * sched)
{
	schedule = sched;
}

double BaseCrew::calcSalary() {
	return 1500;
}