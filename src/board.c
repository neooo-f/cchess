#include "board.h"

void init_board() {
    for (int i = 0; i < 8; i++) {
        Board[i] = init_piece(1, "assets/img/pawn.svg", GRAY, (Position){1, i}); // black pawns
        Board[i + 8] = init_piece(1, "assets/img/pawn.svg", WHITE, (Position){6, i}); // white pawns
    }

    // black rooks  
    Board[16] = init_piece(5, "assets/img/rook.svg", GRAY, (Position){0, 0});
    Board[17] = init_piece(5, "assets/img/rook.svg", GRAY, (Position){0, 7});

    // white rooks
    Board[18] = init_piece(5, "assets/img/rook.svg", WHITE, (Position){7, 0});
    Board[19] = init_piece(5, "assets/img/rook.svg", WHITE, (Position){7, 7});

    // black knights
    Board[20] = init_piece(3, "assets/img/knight.svg", GRAY, (Position){0, 1});
    Board[21] = init_piece(3, "assets/img/knight.svg", GRAY, (Position){0, 6});

    // white knights
    Board[22] = init_piece(3, "assets/img/knight.svg", WHITE, (Position){7, 1});
    Board[23] = init_piece(3, "assets/img/knight.svg", WHITE, (Position){7, 6});

    // black bishops
    Board[24] = init_piece(3, "assets/img/bishop.svg", GRAY, (Position){0, 2});
    Board[25] = init_piece(3, "assets/img/bishop.svg", GRAY, (Position){0, 5});

    // white bishops
    Board[26] = init_piece(3, "assets/img/bishop.svg", WHITE, (Position){7, 2});
    Board[27] = init_piece(3, "assets/img/bishop.svg", WHITE, (Position){7, 5});

    // black queen
    Board[28] = init_piece(9, "assets/img/queen.svg", GRAY, (Position){0, 3});

    // white queen
    Board[29] = init_piece(9, "assets/img/queen.svg", WHITE, (Position){7, 3});

    // black king
    Board[30] = init_piece(0, "assets/img/king.svg", GRAY, (Position){0, 4});

    // white king
    Board[31] = init_piece(0, "assets/img/king.svg", WHITE, (Position){7, 4});
}

/* draw functions */
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