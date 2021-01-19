#pragma once

#include"Route.h"
#include<list>

const unsigned int MAX_ENTRIES_SIZE = 50;

class RouteObserver
{
public:
	RouteObserver();
	~RouteObserver();

	friend std::ostream& operator << (std::ostream& out, RouteObserver& obj);
	friend std::istream& operator >> (std::istream& in, RouteObserver& obj);
	friend void getOptimizedList(std::list<Route>& list_ref, RouteObserver& obj);

private:
	
	std::list<Route> routes;
	int listSize;
};

