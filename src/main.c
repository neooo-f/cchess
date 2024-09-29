#include <stdio.h>
#include "raylib.h"
#include "global.h"
#include "board.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib [core] example - basic window");
    SetWindowTitle("Chess");

    // Image test_image = LoadImageSvg("assets/img/king.svg", 55, 55);
    // Texture2D texture = LoadTextureFromImage(test_image);
    // UnloadImage(test_image);

    init_board();
    SetTargetFPS(60);

    // game loop
    while (!WindowShouldClose()) {
        // update
        
        // draw
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        draw_field();

        // DrawTexture(texture, (SCREEN_WIDTH - texture.width) / 2, (SCREEN_HEIGHT - texture.height) / 2, GRAY);

        EndDrawing();
    }

    // close window if loop ends
    CloseWindow();

    return 0;
}