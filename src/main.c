#include <stdio.h>
#include "raylib.h"
#include "global.h"
#include "board.h"

#include "piece.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetWindowTitle("Chess");

    init_board();
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose()) {
        // update
        
        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        draw_field();

        for (int i = 0; i < 32; i++) {
            draw_piece(Board[i]);
        }

        EndDrawing();
    }

    // close window if loop ends
    CloseWindow();

    return 0;
}