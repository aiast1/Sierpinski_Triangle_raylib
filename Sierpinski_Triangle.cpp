﻿#include "raylib.h"


void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, int depth);

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 960;
    const int depth = 8; //4-8 looks good

    InitWindow(screenWidth, screenHeight, "Sierpinski Triangle");

    SetTargetFPS(20);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);

        Vector2 v1 = { screenWidth / 2.0f, 50.0f };
        Vector2 v2 = { 50.0f, screenHeight - 50.0f };
        Vector2 v3 = { screenWidth - 50.0f, screenHeight - 50.0f };

        DrawTriangle(v1, v2, v3, depth); 

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, int depth) {
    if (depth > 0) {
        
        Vector2 v12 = { (v1.x + v2.x) / 2, (v1.y + v2.y) / 2 };
        Vector2 v23 = { (v2.x + v3.x) / 2, (v2.y + v3.y) / 2 };
        Vector2 v31 = { (v3.x + v1.x) / 2, (v3.y + v1.y) / 2 };

        DrawTriangle(v1, v12, v31, depth - 1);
        DrawTriangle(v12, v2, v23, depth - 1);
        DrawTriangle(v31, v23, v3, depth - 1);
    }
    else {
        DrawTriangle(v1, v2, v3, GREEN);
    }
}