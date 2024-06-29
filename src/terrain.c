#include "terrain.h"
#include "cube.h"
#include <math.h>



extern Texture2D tex;



void draw_terrain(){
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            //float height = 5 * sin(i * -10) * sin(j * -10);
            draw_cube_lines((Vector3){i * 5, 0, j * 5}, 20, BLACK);
            //DrawCubeWires((Vector3){i * 5, 0, j * 5}, 20, 20, 20, BLACK);
            draw_cube((Vector3){i * 5, 0, j * 5}, 20, DARKGREEN);
        }
    }
}