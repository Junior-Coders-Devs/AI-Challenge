#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"
#include "movevalidator.h"


class Player
{
public:
    Player(Color color);

    bool makeMove();

protected:

    virtual bool getMove(Piece*& piece, int &diffRow, int &diffCol);

    int convertCoordinateX(int coord);
    int convertCoordinateY(int coord);

    Color color;
    MoveValidator moveValidator;
    PiecePainter piecePainter;
    Painter painter;
};



#endif // H_PLAYER
