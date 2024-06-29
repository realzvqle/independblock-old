#include "terrain.h"

Camera3D cam;
Texture2D tex;

int main(){
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(1600, 900, "idk");
    cam = (Camera3D){(Vector3){0, 20, 10}, (Vector3){0, 0, 0}, (Vector3){0, 1, 0}, 70.0f, 0};

    tex = LoadTexture("grass.png");
    while(!WindowShouldClose()){
        UpdateCamera(&cam, CAMERA_FIRST_PERSON);
        BeginDrawing();
        ClearBackground(SKYBLUE);
        BeginMode3D(cam);
        DisableCursor();
        draw_terrain();
        EndMode3D();
        DrawFPS(10, 10);
        DrawText("+", (GetScreenWidth() - MeasureText("+", 30)) / 2, GetScreenHeight() / 2, 30, BLACK);
        EndDrawing();
    }
}