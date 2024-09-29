#include "piece.h"

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

/**
 * draws piece to board
 */
void draw_piece(Piece* p_piece) {
    if (p_piece != NULL) {
        // calculates center position of the piece within its cell
        int center_x = (SCREEN_WIDTH - (8 * CELL_SIZE)) / 2 + p_piece->position.col * CELL_SIZE + (CELL_SIZE - p_piece->texture.width) / 2;
        int center_y = (SCREEN_HEIGHT - (8 * CELL_SIZE)) / 2 + p_piece->position.row * CELL_SIZE + (CELL_SIZE - p_piece->texture.height) / 2;

        DrawTexture(p_piece->texture, center_x, center_y, p_piece->color);
    }
}