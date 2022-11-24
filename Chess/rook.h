#ifndef H_ROOK
#define H_ROOK

#include "piece.h"

class Rook: public Piece{

    public:
        Rook(int row, int column);
        void makeMove(int diffRow, int diffColumn);

    private:
        bool isMoveLegal(int diffRow, int diffColumn);
};

#endif // H_ROOK
