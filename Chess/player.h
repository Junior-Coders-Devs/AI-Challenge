#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"
#include "movevalidator.h"


class Player
{
public:
    Player(Color color, Board board);

    struct position
    {
        int row;
        int column;
    };

    bool makeMove(Board board);
    virtual void getMove(Board board);
    virtual void getMove(Board board, Piece*& piece, int &diffRow, int &diffCol);

protected:
    int convertCoordinateX(int coord);
    int convertCoordinateY(int coord);

    bool checkForPieceOfColor(int row, int column, Board board, Color color);
    bool checkForPieceOfOppositeColor(int row, int column, Board board, Color color);

    Color color;
    MoveValidator moveValidator;
    PiecePainter piecePainter;
    Painter painter;
};



#endif // H_PLAYER
