#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"
#include "movevalidator.h"
#include "checkvalidator.h"

class Player
{
public:
    Player(Color playerColor);

    bool makeMove();

protected:

    virtual bool getMove(Piece*& piece, int &diffRow, int &diffCol);

    Color playerColor;
    MoveValidator moveValidator;
    PiecePainter piecePainter;
    Painter painter;
    CheckValidator* CV;
};



#endif // H_PLAYER
