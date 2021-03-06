#include "Board.hpp"

Board::Board(int bombs)
    : bombs_(bombs)
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            board[i][j].number = 0;
            board[i][j].setCheck(false);
        }
    }
    addBombs(bombs_);
}

void Board::showBoard()
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(board[i][j].getCheck() == false)
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
            std::cout<<" ";
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

        for(int m=-1; m<2; m++)
        {
            for(int n=-1; n<2; n++)
            {
                if(board[x+n][y+m].number<0) continue;
                if((x+n)<0) continue;
                if((y+m)<0) continue;
                if((x+n)>9) continue;
                if((y+m)>9) continue;
                board[x+n][y+m].number +=1;
            }
        }
    }
}

int Board::interface(int x, int y)
{
    if(board[x][y].number<0)
    {
        board[x][y].setCheck(true);
        showBoard();
        std::cout<<"Game over"<<std::endl;
        return -1;
    }
    else
    {
        checkField(x,y);
        showBoard();
        if(victory()==bombs_)
        {
            std::cout<<"You won"<<std::endl;
            return -1;
        }
    }
    return 0;
}

void Board::checkField(int x, int y)
{
   if(board[x][y].number<0) return;
   else if(x<0) return;
   else if(y<0) return;
   else if(x>9) return;
   else if(x>9) return;
   else if(!board[x][y].getCheck())
   {
       board[x][y].setCheck(true);
       if(board[x][y].number>0) return;
       else
       {
           checkField(x-1,y-1);
           checkField(x-1,y);
           checkField(x-1,y+1);
           checkField(x+1,y-1);
           checkField(x+1,y);
           checkField(x+1,y+1);
           checkField(x,y-1);
           checkField(x,y+1);
       }
   }
   
}

int Board::victory()
{
    int bombs;
    for (int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(board[i][j].getCheck()==false) bombs++;
        }
    }
    return bombs;
}
