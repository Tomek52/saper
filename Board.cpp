#include "Board.hpp"

Board::Board()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            board[i][j].number = 0;
            board[i][j].check = true; //false;
        }
    }
    addBombs(10);
}

void Board::showBoard()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(board[i][j].check == false)
            {
                std::cout<<" ";
            }
            else if(board[i][j].number<0)
            {
                std::cout<<"+";
            }
            else
            {
                std::cout<<board[i][j].number;
            }
        }
        std::cout<<std::endl;
    }
}

void Board::addBombs(int numberOfBombs)
{
    srand(time(NULL));
    for(int i; i<numberOfBombs; i++)
    {
        int x=std::rand()%10;
        int y=std::rand()%10;
        board[x][y].number=-1;
    }
}
