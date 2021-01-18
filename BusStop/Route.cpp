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
	time_t t1 = getTime_t(departureTime);
	time_t t2 = compare.getDepTime();
	return t1 < t2;		 
}

int Route::getDepTime()  const
{
	return getTime_t(departureTime);
}

int Route::getArrTime() const
{
	return getTime_t(arrivalTime);
}

char* Route::getCompName(char* dest) const
{
	if (strlen(dest) != MAX_COMP_NAME_LEN)
		dest = (char*)malloc(MAX_COMP_NAME_LEN * sizeof(char));
	strcpy_s(dest, MAX_COMP_NAME_LEN, companyName);
	return dest;
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

