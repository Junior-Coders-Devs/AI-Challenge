#ifndef H_PLAYER
#define H_PLAYER

#include "board.h"
#include "movevalidator.h"


class Player
{
public:
    Player(Color color, Board board);

    struct element
    {
        int row;
        int column;
    };
    Color color;
    MoveValidator moveValidator;

    int convertCoordinateX(int coord);
    int convertCoordinateY(int coord);
    virtual void makeMove(Board board);
    bool checkForSamePiece(int row, int column, Board board, Color color);
    bool checkForEnemyPiece(int row, int column, Board board, Color color);
};



#endif // H_PLAYER
