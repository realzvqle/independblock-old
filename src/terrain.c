#include "terrain.h"
#include "cube.h"
#include <math.h>



extern Camera3D cam;

typedef struct {
    Vector3 position;
    float size;
    Color color;
} Cube;

Cube cubes[1000];
int cubeCount = 0;

void draw_terrain(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            if(Vector3Distance(cam.position, (Vector3){i * 5, i * 5, j * 5}) >= 1500){
                continue;
            }
            draw_cube_lines((Vector3){i * 5, 0.5 * cos(i) * 5, j * 5}, 5, BLACK);
            draw_cube((Vector3){i * 5, 0.5 * cos(i) * 5, j * 5}, 5, DARKGREEN);   
        }
    }

    for (int i = 0; i < cubeCount; i++) {
        draw_cube_lines(cubes[i].position, cubes[i].size, BLACK);
        draw_cube(cubes[i].position,  cubes[i].size, cubes[i].color);
    }

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(cubeCount < 1000){
            Ray ray = GetMouseRay(GetMousePosition(), cam);
            Vector3 newPos = Vector3Add(ray.position, Vector3Scale(ray.direction, 5.0f));
            cubes[cubeCount++] = (Cube){newPos, 5.0f, GRAY};;
        }
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
        Ray ray = GetMouseRay(GetMousePosition(), cam);
        for (int i = 0; i < cubeCount; i++) {
            if(Vector3Distance(ray.position, cubes[i].position) <= 10){
                cubes[i] = cubes[cubeCount + 1];
                cubeCount--;
            }
        }
    }
}