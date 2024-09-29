#ifndef PIECE_H
#define PIECE_H

#include "raylib.h"
#include "global.h"
#include <stdio.h>
#include <stdlib.h>

Piece* init_piece(int value, char* img_path, Color color, Position position);

#endif