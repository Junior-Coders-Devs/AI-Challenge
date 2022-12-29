#ifndef H_BISHOP
#define H_BISHOP

#include "piece.h"

class Bishop: public Piece{
    public:
        Bishop(int row, int column, Color color);
        void makeMove(int diffRow, int diffColumn);
        PieceType getType();

    private:
        bool isValidMove(int diffRow, int diffColumn);
        bool isMoveLegal(int diffRow, int diffColumn);
};

#endif //H_BISHOP
