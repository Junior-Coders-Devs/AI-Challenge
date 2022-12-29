#include "player.h"


void Player::getMove(Board board){};

void Player::getMove(Board board, Piece*& piece, int &diffRow, int &diffCol) {}

bool Player::makeMove(Board board) {

    Piece* piece;
    int diffRow = -1, diffCol = -1;

    getMove(board, piece, diffRow, diffCol);

    if(piece->isValidMove(diffRow, diffCol)) {

        if(moveValidator.checkMove(diffRow, diffCol, piece->getRow(), piece->getColumn())) {

            piece->makeMove(diffRow, diffCol);
            piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());

            char background[PATH_SIZE];

            /// TODO: In Painter sa facem o metoda de drawEmptySquare pentru o culoare data
            int lineIndex = piece->getRow() - diffRow;
            int columnIndex = piece->getColumn() - diffCol;

            if((lineIndex + columnIndex) % 2 == 1)
                strcpy(background, EMPTY_WHITE_CELL);
            else
                strcpy(background, EMPTY_BLACK_CELL);

            painter.drawEmptySquare(lineIndex, columnIndex, background);

            /// TODO: AR TREBUI ELIMINATA SI DIN MAP !!!!
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

bool Player::checkForPieceOfColor(int row, int column, Board board, Color color)
{
    Piece* piece = board.getPieceForPosition(row, column);

    if(piece == NULL) {
        return false;
    }

    return piece->getColor() == color;
}

bool Player::checkForPieceOfOppositeColor(int row, int column, Board board, Color color)
{
    if(color == _WHITE)
        color = _BLACK;
    else color = _WHITE;

    return checkForPieceOfColor(row, column, board, color);
}
