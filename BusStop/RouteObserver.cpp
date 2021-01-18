#include "RouteObserver.h"

RouteObserver::RouteObserver() : listSize(0)  {}

RouteObserver::~RouteObserver() {}

void RouteObserver::getOptimizedList(std::list<Route>& optimizedList)
{
	
}

std::ostream& operator<<(std::ostream& out, RouteObserver& obj)
{
	for(Route& r: obj.routes)
		out << r << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, RouteObserver& obj)
{
	char compName[MAX_COMP_NAME_LEN];
	char depTime[TIME_SIZE], arrTime[TIME_SIZE];

	for (int i = 0; i < MAX_ENTRIES_SIZE; i++)
	{
		in >> compName >> depTime >> arrTime;
		if (!in)
			break;
		//obj.routes[i] = Route(compName, depTime, arrTime);
		obj.routes.push_back( Route(compName, depTime, arrTime));
		obj.listSize++;
	}
	obj.routes.sort();

	return in;
}
