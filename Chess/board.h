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

        static Board* getInstance();
        void init();
        std::vector<Piece*>& getPieces(Color color);
        Piece* getPieceForPosition(int row, int column);
        void deletePiece(int row, int column, Color color);
        Color getColorForCell(int row, int column);
        void addQueen(int row, int column, Color color);

    private:

        Board();

        void initByColor(Color color);
        void initMapPieces();
        int getPieceIndex(int row, int column, std::vector<Piece*> &pieces);
        Painter painter;
        std::map<Color, std::vector<Piece*>>pieces;

        static Board* instance;
};

#endif // H_BOARD
