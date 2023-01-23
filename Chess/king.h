#ifndef H_KING
#define H_KING

#include "piece.h"

class King: public Piece{

    public:
        King(int row, int column, Color color);
        void makeMove(int diffRow, int diffColumn);
        bool isValidMove(int diffRow, int diffColumn);
        PieceType getType();
        std::vector<MoveBy> getValidPositions();

    private:
        bool isMoveLegal(int diffRow, int diffColumn);

};

#endif // H_KING
