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
        void setPieceLocalNames(char a[10][60]);
        void initWhitePiece(char a[], int lin, int col, char name[]);
        void initializeWhitePieces();
        void initializeBlackPieces();
        void initWhitePawns(char a[], char b[], char c[]);
};

#endif // H_PAINTER
