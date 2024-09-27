#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "raylib.h"

const int CELL_SIZE = 50;
const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

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

Piece* Board[32] = { NULL };

Piece* init_piece(int value, char* img_path, Color color, Position position) {
    Piece* p_piece = (Piece*)malloc(sizeof(Piece));

    if (p_piece == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }

    p_piece->value = value;

    Image piece_image = LoadImageSvg(img_path, 55, 55);
    Texture2D piece_texture = LoadTextureFromImage(piece_image);
    UnloadImage(piece_image);

    p_piece->texture = piece_texture;
    p_piece->color = color;
    p_piece->position = position;

    return p_piece;
}

void init_board() {
    // TODO: hardcoded positions -> cleanup later
    int i = 0;

    while (i != 8) {
        // 8 black pawns
        init_piece(1, "assets/img/pawn.svg", GRAY, (Position){1, i});
    }

    while (i != 16) {
        // 8 white pawns
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

    for (int row = 0; row <= rows; row++) {
        DrawLine(offset_x, offset_y + row * CELL_SIZE, offset_x + grid_width, offset_y + row * CELL_SIZE, BLACK);
    }

    for (int col = 0; col <= cols; col++) {
        DrawLine(offset_x + col * CELL_SIZE, offset_y, offset_x + col * CELL_SIZE, offset_y + grid_height, BLACK);
    }
}

// void draw_piece_in_middle(Piece* piece) {
//     if (piece != NULL) {
//         // Calculate the center position of the piece within its cell
//         int centerX = (SCREEN_WIDTH - (8 * CELL_SIZE)) / 2 + piece->col * CELL_SIZE + (CELL_SIZE - piece->texture.width) / 2;
//         int centerY = (SCREEN_HEIGHT - (8 * CELL_SIZE)) / 2 + piece->row * CELL_SIZE + (CELL_SIZE - piece->texture.height) / 2;

//         // Draw the texture in the center of the cell
//         DrawTexture(piece->texture, centerX, centerY, piece->color);
//     }
// }

int main(void) {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetWindowTitle("Chess");

    // Image test_image = LoadImageSvg("assets/img/king.svg", 55, 55);
    // Texture2D texture = LoadTextureFromImage(test_image);
    // UnloadImage(test_image);

    // init_board();

    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose()) {
        // update
        
        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        draw_field();

        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                // check if row and col have opposite parity
                if ((row + col) % 2 != 0) {
                    fill_field(row, col, BLACK);
                }
            }
        }

        // DrawTexture(texture, (SCREEN_WIDTH - texture.width) / 2, (SCREEN_HEIGHT - texture.height) / 2, GRAY);

        EndDrawing();
    }

    // close window if loop ends
    CloseWindow();

    return 0;
}