#ifndef H_KNIGHT
#define H_KNIGHT
#include "piece.h"
#include <bits/stdc++.h>
using namespace std;

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

    Knight(int row, int column);

    virtual void makeMove(int diffRow, int diffColumn);

    vector<MoveBy> getMoves();

private:
    const vector<MoveBy> moves = {{1, 2}, {1, -2}, {-1, -2}, {-2, 1},
        {2, -1}, {2, 1}, {-1, 2}, {-2, -1}
    };
};


#endif //H_KNIGHT
