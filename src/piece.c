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