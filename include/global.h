#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdlib.h>

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int value;
    Texture2D texture;
    Color color;
    Position position;
} Piece;

extern const int CELL_SIZE;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern Piece* Board[32];

#endif