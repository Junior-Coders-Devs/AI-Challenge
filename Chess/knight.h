#ifndef H_KNIGHT
#define H_KNIGHT

#include "piece.h"
#include <vector>

class Knight : public Piece
{
    public:

        struct MoveBy
        {
            int rowDiff;
            int columnDiff;

            bool operator == (MoveBy & a) const
            {
                return (a.rowDiff == rowDiff && a.columnDiff == columnDiff);
            }

        };

        Knight(int row, int column, Color color);

        void makeMove(int diffRow, int diffColumn);
        bool isValidMove(int diffRow, int diffColumn);
        PieceType getType();

    private:

        bool isMoveLegal(int diffRow, int diffColumn);

        const std::vector<MoveBy> moves = {{1, 2}, {1, -2}, {-1, -2}, {-2, 1},
                                           {2, -1}, {2, 1}, {-1, 2}, {-2, -1}
        };
};


#endif //H_KNIGHT
