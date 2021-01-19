#include "Route.h"

Route::Route() {}

Route::Route(char* comName, char* departTime, char* arrivTime)
{
	strcpy_s(companyName, MAX_COMP_NAME_LEN, comName);
	strcpy_s(departureTime, TIME_SIZE, departTime);
	strcpy_s(arrivalTime, TIME_SIZE, arrivTime);
}

Route::~Route() {}

bool Route::operator<(const Route& compare) const
{
	if (getTime_t(departureTime) < compare.getDepTime())
		return true;
	if (getTime_t(departureTime) == compare.getDepTime() && strcmp(companyName, compare.companyName)!=0)
	{
		if (strcmp(companyName, "Grotty")==0)
			return true;
	}
	return false;		 
}

bool Route::operator==(const Route& compare) const
{
	if (strcmp(arrivalTime, compare.arrivalTime) == 0 &&
		strcmp(departureTime, compare.departureTime) == 0 &&
		strcmp(companyName, compare.companyName) == 0)
		return true;
	return false;
}

bool Route::isEfficient(const Route& compare) const
{
	if(strcmp(arrivalTime, compare.arrivalTime)     == 0 && 
	   strcmp(departureTime, compare.departureTime) == 0 &&
	   strcmp(companyName, compare.companyName)     == 0)
		return false;
	
	if (getTime_t(departureTime) == compare.getDepTime())
	{
		if (getTime_t(arrivalTime) == compare.getArrTime())
		{
			if (strcmp(companyName, compare.companyName) != 0)
			{
				if (strcmp(companyName, "Posh") == 0)
					return true;
				else return false;
			}
		}
		if (getTime_t(arrivalTime) < compare.getArrTime())
			return true;
	}
	
	if (getTime_t(departureTime) < compare.getDepTime())
	{
		if (getTime_t(arrivalTime) < compare.getArrTime())
			return true;
	}
	
	if (getTime_t(departureTime) > compare.getDepTime())
	{
		if (getTime_t(arrivalTime) < compare.getArrTime() || getTime_t(arrivalTime) == compare.getArrTime())
			return true;
	}
	return false;
}

int Route::getDepTime()  const
{
	return getTime_t(departureTime);
}

int Route::getArrTime() const
{
	return getTime_t(arrivalTime);
}

bool Route::isGrotty() const
{
	if (strcmp(companyName, "Grotty") == 0)
			return true;
	
	return false;
}

int Route::getHour(const char* source) const
{
	int h = 0;
	h = (source[0] - '0') * 10 + (source[1] - '0');
	return h;
}

int Route::getMin(const char* source) const
{
	int m = 0;
	m = (source[3] - '0') * 10 + (source[4] - '0');
	return m;
}

int Route::getTime_t(const char* source) const
{
	return getHour(source)*60+getMin(source);
}

std::ostream& operator<<(std::ostream& out, const Route& obj)
{
	out << obj.companyName << " " << obj.departureTime << " " << obj.arrivalTime;
	return out;
}

