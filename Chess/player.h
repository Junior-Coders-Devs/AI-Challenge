#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"
#include "movevalidator.h"


class Player
{
public:
    Player(Color color, Board board);

    bool makeMove(Board &board);
    virtual bool getMove(Board board, Piece*& piece, int &diffRow, int &diffCol);
protected:

    int convertCoordinateX(int coord);
    int convertCoordinateY(int coord);

    Color color;
    MoveValidator moveValidator;
    PiecePainter piecePainter;
    Painter painter;
};



#endif // H_PLAYER
