#include "RouteObserver.h"
#include<fstream>

int main()
{
    RouteObserver routeObserver;
    std::ifstream file("routes.txt");
    
    if (file.is_open())
        file >> routeObserver; 

    file.close();

    std::cout << "Result\n" << routeObserver;
}

