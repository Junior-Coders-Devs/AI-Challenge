#ifndef H_BOARD
#define H_BOARD

#include <vector>
#include <map>
#include "painter.h"
#include "piece.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "knight.h"


class Board {

    public:
        Board();
        void init();
        void initByColor(Color color);
        void initMapPieces();
        std::vector<Piece*> getPieces(Color color);
    private:
        Painter painter;
        std::map<Color, std::vector<Piece*>> pieces;
};

#endif // H_BOARD
