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
};

#endif // H_PAINTER
