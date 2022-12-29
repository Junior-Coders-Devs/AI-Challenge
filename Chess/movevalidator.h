#ifndef H_MOVEVALIDATOR
#define H_MOVEVALIDATOR

#include "board.h"

class MoveValidator
{
public:
    MoveValidator();

    bool checkMove(int diffRow, int diffCol, int row, int column);
    void setBoard(Board board);
    void setColor(Color color);

private:
    int checkCell(int row, int column);
    bool checkForColor(Board board, Color color, int row, int column);

    Board board;
    Color color;

};



#endif // H_MOVEVALIDATOR
