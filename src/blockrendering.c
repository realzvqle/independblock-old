#include "blockrendering.h"
#include "cube.h"
#include <math.h>



extern Camera3D cam;


Cube cubes[MAX_CUBES];
static int cubeCount = 0;


static inline bool is_adjacent_to_existing_block(Vector3 pos, float cubeSize) {
    for (int i = 0; i < cubeCount; i++) {
        Vector3 existingPos = cubes[i].position;

        if ((fabs(pos.x - existingPos.x) == cubeSize && pos.y == existingPos.y && pos.z == existingPos.z) ||
            (fabs(pos.y - existingPos.y) == cubeSize && pos.x == existingPos.x && pos.z == existingPos.z) ||
            (fabs(pos.z - existingPos.z) == cubeSize && pos.x == existingPos.x && pos.y == existingPos.y)) {
            return true;
        }
    }
    return false;
}

void draw_blocks(){

    for (int i = 0; i < cubeCount; i++) {
        draw_cube_lines(cubes[i].position, cubes[i].size, BLACK);
        draw_cube(cubes[i].position,  cubes[i].size, cubes[i].color);
    }
    

    if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
        if(cubeCount < MAX_CUBES){  
            Ray ray = GetMouseRay(GetMousePosition(), cam);
            Vector3 newPos = Vector3Add(ray.position, Vector3Scale(ray.direction, 5.0f));        
            Vector3 gridPos = {
                roundf(newPos.x / 5.0f) * 5.0f,
                roundf(newPos.y / 5.0f) * 5.0f,
                roundf(newPos.z / 5.0f) * 5.0f
            };
            if(cubeCount == 0){
                cubes[cubeCount++] = (Cube){gridPos, 5.0f, GRAY};
            }
            else{
                if (is_adjacent_to_existing_block(gridPos, 5.0f)) {
                    cubes[cubeCount++] = (Cube){gridPos, 5.0f, GRAY};
                }
            }
            
            
        }
    }
    if(IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)){
        Ray ray = GetMouseRay(GetMousePosition(), cam);
        Vector3 pos = Vector3Add(ray.position, Vector3Scale(ray.direction, 5.0f));
        for (int i = 0; i < cubeCount; i++) {
            if(Vector3Distance(pos, cubes[i].position) <= 3.0f){
                cubes[i] = cubes[cubeCount - 1];
                cubeCount--;
            }
        }
    }
}