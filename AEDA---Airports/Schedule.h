
#include "Utils.h"
#include "Time.h"
#include "Date.h"


class Schedule
{
private:
	Time start;
	Time end;

public:
	Schedule();
	Schedule(Time &start, Time &end);
	Time getStart() const;
	Time getEnd() const;
	Time getDuration() const;
	void setStart(Time &start);
	void setEnd(Time &end);
};

class FlightSched
{
private:
	Date departureDate;
	Date arrivalDate;
	Time departureHour;
	Time arrivalHour;
public:
	FlightSched();
	FlightSched(Date departureD, Time departureH, Date arrivalD, Time arrivalH);
	Date getDepartureDate() const;
	Date getArrivalDate() const;
	Time getDepartureHour() const;
	Time getArrivalHour() const;
	void setDepartureDate(Date &date);
	void setArrivalDate(Date &date);
	void setDepartureHour(Time &time);
	void setArrivalHour(Time &time);

	bool isValid() const;
};