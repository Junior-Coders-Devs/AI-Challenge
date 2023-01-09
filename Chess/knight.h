#ifndef H_KNIGHT
#define H_KNIGHT

#include "piece.h"
#include "moveby.h"
#include <vector>

class Knight : public Piece
{
    public:

        static const std::vector<MoveBy> moves;

        Knight(int row, int column, Color color);

        void makeMove(int diffRow, int diffColumn);
        bool isValidMove(int diffRow, int diffColumn);
        PieceType getType();

    private:

        static const std::vector<MoveBy> initMoves();

        bool isMoveLegal(int diffRow, int diffColumn);
};


#endif //H_KNIGHT
