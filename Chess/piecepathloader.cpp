#include "piecepathloader.h"

PiecePathLoader::PiecePathLoader() {}


/**
    Functionality to get the path of a piece

    @params
    squareColor -> the color of the square it is in
    pieceColor -> the color of the piece
    type -> the piece type (Pawn,Queen,Rook etc.)
*/
const char* PiecePathLoader::getPath(Color squareColor, Color pieceColor, PieceType type) {

    switch(type) {

        case PAWN:
            return getPawnPath(squareColor, pieceColor);
        case ROOK:
            return getRookPath(squareColor, pieceColor);
        case KNIGHT:
            return getKnightPath(squareColor, pieceColor);
        case QUEEN:
            return getQueenPath(squareColor, pieceColor);
        case BISHOP:
            return getBishopPath(squareColor, pieceColor);
        case KING:
            return getKingPath(squareColor, pieceColor);
    }
}

const char* PiecePathLoader::getQueenPath(Color squareColor, Color pieceColor) {

    switch(squareColor) {

        case _BLACK:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnBlackPaths[1];
                case _WHITE:
                    return WhiteOnBlackPaths[5];
            }
        case _WHITE:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnWhitePaths[5];
                case _WHITE:
                    return WhiteOnWhitePaths[5];
            }
    }
}

const char* PiecePathLoader::getKingPath(Color squareColor, Color pieceColor) {

    switch(squareColor) {

        case _BLACK:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnBlackPaths[5];
                case _WHITE:
                    return WhiteOnBlackPaths[1];
            }
        case _WHITE:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnWhitePaths[1];
                case _WHITE:
                    return WhiteOnWhitePaths[1];
            }
    }
}
const char* PiecePathLoader::getKnightPath(Color squareColor, Color pieceColor) {

    switch(squareColor) {

        case _BLACK:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnBlackPaths[0];
                case _WHITE:
                    return WhiteOnBlackPaths[0];
            }
        case _WHITE:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnWhitePaths[0];
                case _WHITE:
                    return WhiteOnWhitePaths[0];
            }
    }
}
const char* PiecePathLoader::getPawnPath(Color squareColor, Color pieceColor) {

    switch(squareColor) {

        case _BLACK:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnBlackPaths[4];
                case _WHITE:
                    return WhiteOnBlackPaths[4];
            }
        case _WHITE:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnWhitePaths[4];
                case _WHITE:
                    return WhiteOnWhitePaths[4];
            }
    }
}
const char* PiecePathLoader::getRookPath(Color squareColor, Color pieceColor) {

    switch(squareColor) {

        case _BLACK:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnBlackPaths[3];
                case _WHITE:
                    return WhiteOnBlackPaths[3];
            }
        case _WHITE:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnWhitePaths[3];
                case _WHITE:
                    return WhiteOnWhitePaths[3];
            }
    }
}
const char* PiecePathLoader::getBishopPath(Color squareColor, Color pieceColor) {

    switch(squareColor) {

        case _BLACK:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnBlackPaths[2];
                case _WHITE:
                    return WhiteOnBlackPaths[2];
            }
        case _WHITE:
            switch(pieceColor) {
                case _BLACK:
                    return BlackOnWhitePaths[2];
                case _WHITE:
                    return WhiteOnWhitePaths[2];
            }
    }
}
