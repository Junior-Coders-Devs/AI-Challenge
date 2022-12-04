#ifndef H_PAINTER
#define H_PAINTER

#include "piecepainter.h"

class Painter {

    public:
        Painter();

        void initializeWindow();
        void initializeBoard();
        void initializePieces();

    private:
        void initializeWhitePieces();
        void initializeBlackPieces();
        void drawSquare(int row, int column, char image[]);

        PiecePainter piecePainter;
};

#endif // H_PAINTER
