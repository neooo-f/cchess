#ifndef BOARD_H
#define BOARD_H

#include "raylib.h"
#include "global.h"
#include "piece.h"

void init_board(void);
void draw_field(void);
void fill_field(int row, int col, Color color);

#endif