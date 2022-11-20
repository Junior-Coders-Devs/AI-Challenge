#ifndef H_PAWN
#define H_PAWN

#include "piece.h"

class Pawn : public Piece
{

public:

    Pawn(int row, int column);

    virtual void makeMove(int diffRow, int diffColumn);

    bool isPawnMove(int diffRow, int diffColumn);

};



#endif // H_PAWN
