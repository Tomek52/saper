#include "Field.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Board
{
    public:
    Field board[10][10];
    Board();
    void showBoard();
    void addBombs(int numberOfBombs);
    int interface(int x, int y); 
};
