
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
	Time setStart(Time &start);
	Time setEnd(Time &end);
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

	bool isValid() const;
};