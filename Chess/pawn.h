#ifndef H_PAWN
#define H_PAWN

#include "piece.h"
#include <cmath>

class Pawn : public Piece
{
    public:

        Pawn(int row, int column);

        void makeMove(int diffRow, int diffColumn);

    private:

        bool isMoveLegal(int diffRow, int diffColumn);
};



#endif // H_PAWN
