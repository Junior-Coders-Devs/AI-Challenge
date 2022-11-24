#ifndef H_BISHOP
#define H_BISHOP

#include "piece.h"

class Bishop: public Piece{
    public:
        Bishop(int row, int column);
        void makeMove(int diffRow, int diffColumn);

    private:
        bool isValidMove(int diffRow, int diffColumn);
        bool isMoveLegal(int diffRow, int diffColumn);
};

#endif //H_BISHOP
