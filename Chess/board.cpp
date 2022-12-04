#include "board.h"

Board::Board() {}

void Board::init() {
    painter.initializeWindow();
    painter.initializeBoard();
    painter.initializePieces();
}
