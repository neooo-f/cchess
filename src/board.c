#include "board.h"

void init_board() {
    for (int i = 0; i < 8; i++) {
        Board[i] = init_piece(1, "assets/img/pawn.svg", GRAY, (Position){1, i}); // black pawns
        Board[i * 2] = init_piece(1, "assets/img/pawn.svg", WHITE, (Position){6, i}); // white pawns
    }   
}

void fill_field(int row, int col, Color color) {
    int rows = 8;
    int cols = 8;

    // calculates grid offset
    int grid_width = cols * CELL_SIZE;
    int grid_height = rows * CELL_SIZE;

    int offset_x = (SCREEN_WIDTH - grid_width) / 2;
    int offset_y = (SCREEN_HEIGHT - grid_height) / 2;

    // calculates the top-left corner of the block to be colored
    int block_x = offset_x + col * CELL_SIZE;
    int block_y = offset_y + row * CELL_SIZE;

    DrawRectangle(block_x, block_y, CELL_SIZE, CELL_SIZE, color);
}

void draw_field() {
    // draws a 8 by 8 chess field, colored black and white
    int rows = 8;
    int cols = 8;

    int grid_width = cols * CELL_SIZE;
    int grid_height = rows * CELL_SIZE;

    int offset_x = (SCREEN_WIDTH - grid_width) / 2;
    int offset_y = (SCREEN_HEIGHT - grid_height) / 2;

    // draw rows
    for (int row = 0; row <= rows; row++) {
        DrawLine(offset_x, offset_y + row * CELL_SIZE, offset_x + grid_width, offset_y + row * CELL_SIZE, BLACK);
    }

    // draw cols
    for (int col = 0; col <= cols; col++) {
        DrawLine(offset_x + col * CELL_SIZE, offset_y, offset_x + col * CELL_SIZE, offset_y + grid_height, BLACK);
    }

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            // check if row and col have opposite parity
            if ((row + col) % 2 != 0) {
                fill_field(row, col, BLACK);
            }
        }
    }
}

// TODO: maybe next file game.c