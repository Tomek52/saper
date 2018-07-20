#include <iostream>
#include "Board.hpp"
int main()
{
    std::cout<<"Hello"<<std::endl;
    Board saper;
    int x;
    int y;
    while(1)
    {
           std::cin>>x;
    std::cin>>y;

    saper.interface(x,y);
    }

    return 0;
}
