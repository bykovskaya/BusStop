#pragma once

#include<time.h>
#include <iostream>

const int MAX_COMP_NAME_LEN = 21;
const int TIME_SIZE = 6;

class Route
{
public:
	Route();
	Route(char* companyName, char* departTime, char* arrivalTime);
	~Route();

	friend std::ostream& operator << (std::ostream& out, const Route& obj);
	bool operator < (const Route& compare) const;
	bool operator == (const Route& compare) const;
	bool isEfficient(const Route& compare) const;

	int getDepTime() const;
	int getArrTime() const;
	bool isGrotty() const;

private:
	int getHour(const char* source) const;
	int getMin(const char* source) const;
	int getTime_t(const char* source) const;

	char companyName[MAX_COMP_NAME_LEN];
	char departureTime[TIME_SIZE];
	char arrivalTime[TIME_SIZE];
};

