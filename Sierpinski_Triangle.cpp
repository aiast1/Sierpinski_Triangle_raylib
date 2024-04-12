#include "raylib.h"

void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, int depth);

int main(void) {
    const int screenWidth = 1280;
    const int screenHeight = 960;
    const int depth = 9; //4-8 looks good

    InitWindow(screenWidth, screenHeight, "Sierpinski Triangle");

    SetTargetFPS(30);

    float zoom = 1.0f;

    Vector2 center = { screenWidth / 2.0f, screenHeight / 2.0f };// center to eliminate streching

    while (!WindowShouldClose()) {

        if (IsKeyDown(KEY_UP)) zoom *= 1.01f;//
        if (IsKeyDown(KEY_DOWN)) zoom /= 1.01f;  


        BeginDrawing();

        ClearBackground(BLACK);


        Vector2 v1 = { screenWidth / 2.0f, 50.0f };
        Vector2 v2 = { 50.0f, screenHeight - 50.0f };
        Vector2 v3 = { screenWidth - 50.0f, screenHeight - 50.0f };

        // Adjust cords
        v1.x = center.x + (v1.x - center.x) * zoom;
        v1.y = center.y + (v1.y - center.y) * zoom;
        v2.x = center.x + (v2.x - center.x) * zoom;
        v2.y = center.y + (v2.y - center.y) * zoom;
        v3.x = center.x + (v3.x - center.x) * zoom;
        v3.y = center.y + (v3.y - center.y) * zoom;

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
