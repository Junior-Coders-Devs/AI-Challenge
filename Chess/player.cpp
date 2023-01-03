#include "player.h"
#include <iostream>

bool Player::getMove(Board &board, Piece*& piece, int &diffRow, int &diffCol) {}

bool Player::makeMove(Board &board) {

    Piece* piece;
    int diffRow = -1, diffCol = -1;

    bool ok = getMove(board, piece, diffRow, diffCol);

    if(!ok)
        return false;

    if(piece->isValidMove(diffRow, diffCol)) {

        if(moveValidator.checkMove(diffRow, diffCol, piece->getRow(), piece->getColumn())) {


            Color pieceColor = board.getColorForCell(piece->getRow(), piece->getColumn());

            std::cout << "MUT PIESA: " << piece->getType() << ' ' << color << '\n';
            std::cout << "POZITIA ACTUALA: " << piece->getRow() << ' ' << piece->getColumn() << '\n';
            piece->makeMove(diffRow, diffCol);
            std::cout << "POZITIA NOUA: " << piece->getRow() << ' ' << piece->getColumn() << '\n';

            piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());

            int lineIndex = piece->getRow() - diffRow;
            int columnIndex = piece->getColumn() - diffCol;

            Color color = piecePainter.getColorForCell(lineIndex, columnIndex);
            painter.drawEmptySquare(lineIndex, columnIndex, color);

            Color oppositeColor = pieceColor;
            if(pieceColor == _WHITE) oppositeColor = _BLACK;
            else oppositeColor = _WHITE;
            std::cout << oppositeColor << '\n';
            std::cout << "STERG PIESA DE PE POZITIA " << piece->getRow() << ' ' << piece->getColumn() << '\n';
            board.deletePiece(piece->getRow(), piece->getColumn(), oppositeColor);

            return true;
        }
    }

    return false;
}

Player::Player(Color color, Board *board)
{
    this->color = color;
    moveValidator.setBoard(board);
    moveValidator.setColor(color);
}

int Player::convertCoordinateX(int coord)
{
    return 9 - ((coord - 30) / SQUARE_SIZE);
}

int Player::convertCoordinateY(int coord)
{
    return (coord - 30) / SQUARE_SIZE;
}
