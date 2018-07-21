#include <iostream>
#include "Board.hpp"
int main()
{
    std::cout<<"Hello this is saper game, in this beta version there are 10 bombs marked as + sign, the board size is 10x10, let's start the game!"<<std::endl;
    Board saper(10);
    int x;
    int y;
    int state=0;

    while(state>=0)
    {
        switch(state)
        {
            case 0:
                {
                    std::cout<<"Write x coordinate for the range 0-9 end press enter"<<std::endl;
                    std::cin>>x;
                    std::cout<<"Write y coordinate for the range 0-9 end press enter"<<std::endl;
                    std::cin>>y;
                    state=1;
                    break;
                }
            case 1:
                {
                    state=saper.interface(x,y);
                    break;
                }
        }
    }
    return 0;
}
