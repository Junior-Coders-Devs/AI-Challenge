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


const char EMPTY_BLACK_CELL[] = "Backgrounds/Black.jpg";

const char EMPTY_WHITE_CELL[] = "Backgrounds/White.jpg";

enum Color {
    _WHITE,
    _BLACK
};

enum PieceType {
    KNIGHT,
    QUEEN,
    BISHOP,
    ROOK,
    PAWN,
    KING
};

#endif // H_CONFIG
