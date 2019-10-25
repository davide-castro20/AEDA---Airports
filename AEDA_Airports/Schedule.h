
#include "Utils.h"
#include "Time.h"
#include "Date.h"

class Schedule
{
private:
	Time startHour;
	Time endHour;

public:
	Schedule();
	Schedule(Time &start, Time &end);
	Time getStartHour() const;
	Time getEndHour() const;
	virtual Time getDuration() const;
	void setStartHour(Time &start);
	void setEndHour(Time &end);
};

class FlightSched : public Schedule
{
private:
	Date departureDate;
	Date arrivalDate;
public:
	FlightSched();
	FlightSched(Date &departureD, Time &startHour, Date &arrivalD, Time &endHour);
	Date getDepartureDate() const;
	Date getArrivalDate() const;
	Time getDuration() const;
	void setDepartureDate(Date &date);
	void setArrivalDate(Date &date);

	bool isValid() const;
};