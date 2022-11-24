#ifndef H_QUEEN
#define H_QUEEN

#include "piece.h"

class Queen: public Piece{
    public:
        Queen(int row, int column);
        void makeMove(int diffRow, int diffColumn);

    private:
        bool isValidMove(int diffRow, int diffColumn);
        bool isMoveLegal(int diffRow, int diffColumn);
};


#endif //H_QUEEN
