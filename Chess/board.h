#ifndef H_BOARD
#define H_BOARD

#include "painter.h"

class Board {

    public:
        Board();
        void init();

    private:
        Painter painter;
};

#endif // H_BOARD
