#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"
#include "movevalidator.h"
#include "history.h"
#include<iostream>

class Player
{
public:
    Player(Color playerColor);

    bool makeMove();

protected:

    bool isCastling(Piece* &firstPiece, Piece* &secondPiece);
    virtual bool getMove(Piece*& piece, Piece*&enemyPiece, int &diffRow, int &diffCol, position &startPosition, bool &isTaken);
    Color playerColor;
    MoveValidator moveValidator;
    PiecePainter piecePainter;
    Painter painter;
};



#endif // H_PLAYER
