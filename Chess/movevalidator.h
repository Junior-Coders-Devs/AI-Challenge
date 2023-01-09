#ifndef H_MOVEVALIDATOR
#define H_MOVEVALIDATOR

#include "board.h"

class MoveValidator
{
public:
    MoveValidator();

    bool validateMove(int diffRow, int diffCol, int row, int column);
    void setColor(Color color);

private:
    int validateCell(int row, int column);
    bool checkForColor(Color color, int row, int column);
    bool isHorseMoved(int diffRow, int diffCol);
    bool isPathGood(int diffRow, int diffCol, int row, int column, int moveX, int moveY);
    Color color;

};



#endif // H_MOVEVALIDATOR
