#include "player.h"
#ifdef DEBUG_LOGS
#include <iostream>
#endif // DEBUG_LOGS

Player::Player(Color playerColor)
{
    this->playerColor = playerColor;
    moveValidator.setColor(playerColor);
}

bool Player::getMove(Piece*& piece, int &diffRow, int &diffCol) {}

bool Player::makeMove() {

    Board* board = Board::getInstance();
    Piece* piece;
    int diffRow = -1, diffCol = -1;

    bool ok = getMove(piece, diffRow, diffCol);

    if(!ok)
        return false;

    if(piece->isValidMove(diffRow, diffCol)) {

        if(moveValidator.validateMove(diffRow, diffCol, piece->getRow(), piece->getColumn())) {

            Color pieceColor = board->getColorForCell(piece->getRow(), piece->getColumn());

#ifdef DEBUG_LOGS
            std::cout << "MUT PIESA: " << piece->getType() << ' ' << color << '\n';
            std::cout << "POZITIA ACTUALA: " << piece->getRow() << ' ' << piece->getColumn() << '\n';
#endif // DEBUG_LOGS

            piece->makeMove(diffRow, diffCol);

#ifdef DEBUG_LOGS
            std::cout << "POZITIA NOUA: " << piece->getRow() << ' ' << piece->getColumn() << '\n';
#endif // DEBUG_LOGS

            piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());

            int lineIndex = piece->getRow() - diffRow;
            int columnIndex = piece->getColumn() - diffCol;

            Color cellColor = piecePainter.getColorForCell(lineIndex, columnIndex);
            painter.drawEmptySquare(lineIndex, columnIndex, cellColor);

            Color oppositeColor = pieceColor;
            if(pieceColor == _WHITE) oppositeColor = _BLACK;
            else oppositeColor = _WHITE;

#ifdef DEBUG_LOGS
            std::cout << oppositeColor << '\n';
            std::cout << "STERG PIESA DE PE POZITIA " << piece->getRow() << ' ' << piece->getColumn() << '\n';
#endif // DEBUG_LOGS

            board->deletePiece(piece->getRow(), piece->getColumn(), oppositeColor);
            CV->isCheckMate(pieceColor);
            CV->isCheck(pieceColor);
            return true;
        }
    }
    return false;
}
