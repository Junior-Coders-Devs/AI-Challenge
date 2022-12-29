#ifndef H_PAINTER
#define H_PAINTER

#include "piecepainter.h"

class Painter {

    public:
        Painter();

        void initializeWindow();
        void initializeBoard();
        void initializePieces();
        void drawEmptySquare(int row, int column, char image[]);

    private:
        void initializeWhitePieces();
        void initializeBlackPieces();

        PiecePainter piecePainter;
};

#endif // H_PAINTER
