#include "Field.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

class Board
{
    int bombs_;
    public:
    Field board[10][10];
    Board(int bombs);
    void showBoard();
    void addBombs(int numberOfBombs);
    int interface(int x, int y); 
    void checkField(int x, int y);
    int victory();
};
