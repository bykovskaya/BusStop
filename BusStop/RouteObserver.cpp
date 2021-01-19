#include "RouteObserver.h"
#include<vector>

RouteObserver::RouteObserver() : listSize(0) {}

RouteObserver::~RouteObserver() {}

void getOptimizedList(std::list<Route>& optimizedList, RouteObserver& obj)
{
	std::vector<Route> vroutes;
	for (Route r : obj.routes)
	{
		vroutes.push_back(r);
		optimizedList.push_back(r);
	}

	bool add = false;

	for (int i = 0; i < obj.listSize - 1; i++)
	{
		for (int j = i + 1; j < obj.listSize; j++)
		{
			add = vroutes[i].isEfficient(vroutes[j]);
			if (!add)
				optimizedList.remove(vroutes[i]);
		}
	}
	vroutes.clear();

	for (Route r : optimizedList)
		vroutes.push_back(r);

	for (Route r : vroutes)
	{
		if (r.isGrotty())
		{
			Route temp = r;
			optimizedList.remove(temp);
			optimizedList.push_back(temp);
		}
	}
	
}

std::ostream& operator<<(std::ostream& out, RouteObserver& obj)
{
	std::list<Route> optimizedList;
	getOptimizedList(optimizedList, obj);

	for (Route& r : optimizedList)
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
		
		obj.routes.push_back(Route(compName, depTime, arrTime));
		obj.listSize++;
	}

	obj.routes.sort();

	return in;
}
