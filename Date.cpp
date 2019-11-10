#include "Date.h"

Date::Date() 
{
}

Date::Date(string date) {


	istringstream Dat(date);
	//string dayS, monthS, yearS;
	//getline(Dat, dayS, '/');
	//getline(Dat, monthS, '/');
	//getline(Dat, yearS, '/');
	char sep;
	Dat >> day;
	Dat >> sep;
	Dat >> month;
	Dat >> sep;
	Dat >> year;
	/*day = (unsigned short)stoi(dayS);
	month = (unsigned short)stoi(monthS);
	year = (unsigned short)stoi(yearS);*/
}


Date::Date(unsigned short day, unsigned short month, unsigned year) {

	this->day = day;
	this->month = month;
	this->year = year;
}


unsigned short Date::getDay() const {

	return day;

}


unsigned short Date::getMonth() const {

	return month;

}

unsigned Date::getYear() const {

	return year;

}

string Date::getDate() const
{
	return to_string(year) + "/" + to_string(month) + "/" + to_string(day);
}


void Date::setDay(unsigned short day) {

	this->day = day;

}
void Date::setMonth(unsigned short month) {

	this->month = month;

}

void Date::setYear(unsigned year) {

	this->year = year;

}


ostream& operator<<(ostream& out, const Date & date) {

	out << date.day << "/" << date.month << "/" << date.year;
	return out;
}

bool Date::operator<(const Date &date){
	
	int num1, num2;
	num1 = this->year * 10000 + this->month * 100 +this->day;
	num2 = date.year * 10000 + date.month * 100 + date.day;
	return num1 < num2;
}

bool Date::operator<=(const Date &date) {

	int num1, num2;
	num1 = this->year * 10000 + this->month * 100 + this->day;
	num2 = date.year * 10000 + date.month * 100 + date.day;
	return num1 <= num2;
}

bool Date::operator==(const Date &date)
{
	if ((this->year == date.year) && (this->month == date.month) && (this->day == date.day))
		return true;
	else return false;
}

bool Date::isValid(){
	int maxDays;
	if (year >= 0 && (month >= 1 && month <= 12))
	{
		maxDays = days(year, month);
		if (day >= 1 && day <= maxDays)
			return true;
	}
	return false;
}