#ifndef H_PAWN
#define H_PAWN

#include "piece.h"
#include <cmath>

class Pawn : public Piece
{
    public:

        Pawn(int row, int column, Color color);

        void makeMove(int diffRow, int diffColumn);
        bool isValidMove(int diffRow, int diffColumn);
        PieceType getType();

    private:

        bool isMoveLegal(int diffRow, int diffColumn);
};



#endif // H_PAWN
