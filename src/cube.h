#ifndef CUBE_H_INCLUDED
#define CUBE_H_INCLUDED



#include "main.h"
#include "../externel/raylib/rlgl.h"
#include "../externel/raylib/raymath.h"





void draw_cube(Vector3 pos, float size, Color color);
void draw_cube_lines(Vector3 pos, float size, Color color);


typedef struct {
    Vector3 position;
    float size;
    Color color;
} Cube;

#endif