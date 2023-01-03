#ifndef H_CONFIG
#define H_CONFIG


const int WINDOW_HEIGHT = 760;
const int WINDOW_WIDTH = 760;

const int OFFSET_X = 100;
const int OFFSET_Y = 100;

const int SQUARE_SIZE = 70;

const int PATH_SIZE = 105;

const char BlackOnBlackPaths[][PATH_SIZE] = {
                                            "BlackOnBlack/knight.jpg",
                                            "BlackOnBlack/queen.jpg",
                                            "BlackOnBlack/bishop.jpg",
                                            "BlackOnBlack/rook.jpg",
                                            "BlackOnBlack/pawn.jpg",
                                            "BlackOnBlack/king.jpg"};

const char BlackOnWhitePaths[][PATH_SIZE] = {
                                            "BlackOnWhite/knight.jpg",
                                            "BlackOnWhite/king.jpg",
                                            "BlackOnWhite/bishop.jpg",
                                            "BlackOnWhite/rook.jpg",
                                            "BlackOnWhite/pawn.jpg",
                                            "BlackOnWhite/queen.jpg"};

const char WhiteOnBlackPaths[][PATH_SIZE] = {
                                            "WhiteOnBlack/knight.jpg",
                                            "WhiteOnBlack/king.jpg",
                                            "WhiteOnBlack/bishop.jpg",
                                            "WhiteOnBlack/rook.jpg",
                                            "WhiteOnBlack/pawn.jpg",
                                            "WhiteOnBlack/queen.jpg"};

const char WhiteOnWhitePaths[][PATH_SIZE] = {
                                            "WhiteOnWhite/knight.jpg",
                                            "WhiteOnWhite/king.jpg",
                                            "WhiteOnWhite/bishop.jpg",
                                            "WhiteOnWhite/rook.jpg",
                                            "WhiteOnWhite/pawn.jpg",
                                            "WhiteOnWhite/queen.jpg"};


const char EMPTY_BLACK_CELL[] = "Backgrounds/Black.jpg";

const char EMPTY_WHITE_CELL[] = "Backgrounds/White.jpg";

enum Color {
    _WHITE,
    _BLACK,
    _UNDEFINED
};

enum PieceType {
    KNIGHT,
    QUEEN,
    BISHOP,
    ROOK,
    PAWN,
    KING
};

struct position
{
    int row;
    int column;
};
#endif // H_CONFIG
