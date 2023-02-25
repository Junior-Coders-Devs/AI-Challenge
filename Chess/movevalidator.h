#ifndef H_MOVEVALIDATOR
#define H_MOVEVALIDATOR

#include "board.h"
#include "chesslog.h"

class MoveValidator
{
public:
    MoveValidator();
    bool validateMove(int diffRow, int diffCol, int row, int column);
    void setColor(Color color);
    void setWasCastling(bool wasCastling);
    bool getWasCastling();

private:
    int validateCell(int row, int column);
    bool checkForColor(Color color, int row, int column);
    bool isHorseMoved(int diffRow, int diffCol);
    bool isCastling(int diffRow, int diffCol, int row, int column);
    bool isPathGood(int diffRow, int diffCol, int row, int column, int moveX, int moveY);
    Color color;
    ChessLog* log;
    bool wasCastling;

};



#endif // H_MOVEVALIDATOR
