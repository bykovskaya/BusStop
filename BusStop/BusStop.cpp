#include "RouteObserver.h"
#include<fstream>

int main()
{
    char readfileName[200] = {0};
    char writefName[200] = { 0 };
    RouteObserver routeObserver;

    std::cout << "Enter file name to read from:\n";
    std::cin >> readfileName;
    
    std::ifstream file(readfileName);
    
    if (file.is_open())
        file >> routeObserver; 
    else
    {
        std::cerr << "Faild to open file: " << readfileName << std::endl;
        return -7;
    }
    file.close();

    std::cout << "Enter file name to write to:\n";
    std::cin >> writefName;
   
    std::ofstream writefile(writefName);
    
    if (writefile.is_open())
        writefile << routeObserver;
    else
    {
        std::cerr << "Faild to open file: " << writefName << std::endl;
        return -8;
    }
    writefile.close();
    std::cout << "Result\n" << routeObserver;
}

