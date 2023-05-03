#include "player.h"
#ifdef DEBUG_LOGS
#include <iostream>
#endif // DEBUG_LOGS
Player::Player(Color playerColor)
{
    this->playerColor = playerColor;
}

bool Player::getMove(Piece*& piece, int &diffRow, int &diffCol) {}

bool Player::makeMove()
{

    Board* board = Board::getInstance();
    Piece* piece;
    int diffRow = -1, diffCol = -1;

    bool ok = getMove(piece, diffRow, diffCol);

    if(!ok)
        return false;

    if(piece->isValidMove(diffRow, diffCol))
    {

        if(moveValidator.validateSpecialMove(diffRow, diffCol, piece->getRow(), piece->getColumn()))
        {
            Color pieceColor = board->getColorForCell(piece->getRow(), piece->getColumn());

            piece->makeMove(diffRow, diffCol);
            piecePainter.paintPiece(piece->getRow(), piece->getColumn(), piece->getType(), piece->getColor());

            int lineIndex = piece->getRow() - diffRow;
            int columnIndex = piece->getColumn();

            Color cellColor = piecePainter.getColorForCell(lineIndex, columnIndex);

            painter.drawEmptySquare(lineIndex, columnIndex, cellColor);
            painter.drawEmptySquare(lineIndex, columnIndex - diffCol, piecePainter.getColorForCell(lineIndex, columnIndex - diffCol));

            Color oppositeColor = pieceColor;

            if(pieceColor == _WHITE) oppositeColor = _BLACK;
            else oppositeColor = _WHITE;

            board->deletePiece(piece->getRow(), piece->getColumn(), oppositeColor);

            if(piece->getType() == PAWN)
                convertValidator.convertPawnIntoQueen(board, &piecePainter);

            return true;
        }

        if(moveValidator.validateMove(diffRow, diffCol, piece->getRow(), piece->getColumn()))
        {

            Color pieceColor = board->getColorForCell(piece->getRow(), piece->getColumn());

#ifdef DEBUG_LOGS
            std::cout << "MUT PIESA: " << piece->getType() << ' ' << pieceColor << '\n';
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

            int row = piece->getRow(), column = piece->getColumn();
            PieceType pieceType = piece->getType();

            board->deletePiece(piece->getRow(), piece->getColumn(), oppositeColor);

            if(piece->getType() == PAWN)
                convertValidator.convertPawnIntoQueen(board, &piecePainter);

            return true;
        }
    }

    return false;
}
