#ifndef H_MOVEVALIDATOR
#define H_MOVEVALIDATOR

#include "board.h"

class MoveValidator
{
public:
    MoveValidator();

    bool checkMove(int diffRow, int diffCol, int row, int column);
    void setBoard(Board *board);
    void setColor(Color color);

private:
    int validateCell(int row, int column);
    bool checkForColor(Color color, int row, int column);
    bool isHorseMoved(int diffRow, int diffCol);
    bool isPathGood(int diffRow, int diffCol, int row, int column, int moveX, int moveY);
    void makeMove(int &row, int &column, int moveX, int moveY);
    Board* board;
    Color color;

};



#endif // H_MOVEVALIDATOR
