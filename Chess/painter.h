#ifndef H_PAINTER
#define H_PAINTER

#include "graphics.h"
#include "config.h"

class Painter {

    public:
        Painter();

        void initializeWindow();
        void initializeBoard();
        void initializePieces();

    private:
        void initializeWhitePieces();
        void initializeBlackPieces();
        void drawSquare(int row, int column, int patrat, char image[]);
        void loadPiece(int row, int column, char image[]);
};

#endif // H_PAINTER
