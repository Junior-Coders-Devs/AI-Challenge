#include "player.h"

bool Player::getMove(Board board, Piece*& piece, int &diffRow, int &diffCol) {}

bool Player::makeMove(Board &board) {

    Piece* piece;
    int diffRow = -1, diffCol = -1;

    bool ok = getMove(board, piece, diffRow, diffCol);

    if(!ok)
        return false;

    if(piece->isValidMove(diffRow, diffCol)) {

        if(moveValidator.checkMove(diffRow, diffCol, piece->getRow(), piece->getColumn())) {

            piece->makeMove(diffRow, diffCol);
            piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());

            /// TODO: In Painter sa facem o metoda de drawEmptySquare pentru o culoare data
            int lineIndex = piece->getRow() - diffRow;
            int columnIndex = piece->getColumn() - diffCol;

            Color color = piecePainter.getColorForCell(lineIndex, columnIndex);

            painter.drawEmptySquare(lineIndex, columnIndex, color);

            board.deletePiece(piece->getRow(), piece->getColumn(), _BLACK);

            return true;
        }
    }

    return false;
}

Player::Player(Color color, Board board)
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
