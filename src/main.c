#include "blockrendering.h"
#include "movement.h"



Camera3D cam;
Texture2D tex;

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(1600, 900, "idk");
    cam = (Camera3D){(Vector3){0, 20, 10}, (Vector3){0, 0, 0}, (Vector3){0, 1, 0}, 70.0f, 0};

    tex = LoadTexture("grass.png");
    while(!WindowShouldClose()){
        BeginDrawing();
        update_movement();
        ClearBackground(SKYBLUE);
        BeginMode3D(cam);
        DisableCursor();
        draw_blocks();
        EndMode3D();
        DrawFPS(10, 10);
        DrawText("+", (GetScreenWidth() - MeasureText("+", 40)) / 2, GetScreenHeight() / 2, 40, BLACK);
        EndDrawing();
    }
}