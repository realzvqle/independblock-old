#include "cube.h"


extern Camera3D cam;



void draw_cube(Vector3 pos, float size, Color color){
    float half = size / 2.0f;
    
    rlPushMatrix();
    rlTranslatef(pos.x, pos.y, pos.z);
    rlBegin(RL_QUADS);
    rlColor4ub(color.r, color.g, color.b, color.a);
    
    Vector3 toCam = Vector3Subtract(cam.position, pos);

    Vector3 frontVector = { 0, 0, 1 };
    Vector3 backVector = { 0, 0, -1 };
    Vector3 topVector = { 0, 1, 0 };
    Vector3 bottomVector = { 0, -1, 0 };
    Vector3 rightVector = { 1, 0, 0 };
    Vector3 leftVector = { -1, 0, 0 };

    float dotFront = Vector3DotProduct(toCam, frontVector);
    float dotBack = Vector3DotProduct(toCam, backVector);
    float dotTop = Vector3DotProduct(toCam, topVector);
    float dotBottom = Vector3DotProduct(toCam, bottomVector);
    float dotRight = Vector3DotProduct(toCam, rightVector);
    float dotLeft = Vector3DotProduct(toCam, leftVector);


    if(dotFront > 0){
        rlVertex3f(-half, -half, half);
        rlVertex3f(half, -half, half);
        rlVertex3f(half, half, half);
        rlVertex3f(-half, half, half);
    }
    
    if(dotBack > 0){
        rlVertex3f(-half, -half, -half);
        rlVertex3f(-half, half, -half);
        rlVertex3f(half, half, -half);
        rlVertex3f(half, -half, -half);
    }
    
    if(dotTop > 0){
        rlVertex3f(-half, half, -half);
        rlVertex3f(-half, half, half);
        rlVertex3f(half, half, half);
        rlVertex3f(half, half, -half);
    }
   
    if(dotBottom > 0){
        rlVertex3f(-half, -half, -half);
        rlVertex3f(half, -half, -half);
        rlVertex3f(half, -half, half);
        rlVertex3f(-half, -half, half);
    }
    
    
    if(dotRight > 0){
        rlVertex3f(half, -half, -half);
        rlVertex3f(half, half, -half);
        rlVertex3f(half, half, half);
        rlVertex3f(half, -half, half);
    }
    

    if(dotLeft > 0){
        rlVertex3f(-half, -half, -half);
        rlVertex3f(-half, -half, half);
        rlVertex3f(-half, half, half);
        rlVertex3f(-half, half, -half);
    } 
    
    rlEnd();
    rlPopMatrix();
}


void draw_cube_lines(Vector3 pos, float size, Color color){
    float half = size / 2.0f;
    
    rlPushMatrix();
    rlTranslatef(pos.x, pos.y, pos.z);
    rlBegin(RL_LINES);
    rlColor4ub(color.r, color.g, color.b, color.a);

    Vector3 toCam = Vector3Subtract(cam.position, pos);

    Vector3 frontVector = { 0, 0, 1 };
    Vector3 backVector = { 0, 0, -1 };
    Vector3 topVector = { 0, 1, 0 };
    Vector3 bottomVector = { 0, -1, 0 };
    Vector3 rightVector = { 1, 0, 0 };
    Vector3 leftVector = { -1, 0, 0 };

    float dotFront = Vector3DotProduct(toCam, frontVector);
    float dotBack = Vector3DotProduct(toCam, backVector);
    float dotTop = Vector3DotProduct(toCam, topVector);
    float dotBottom = Vector3DotProduct(toCam, bottomVector);
    float dotRight = Vector3DotProduct(toCam, rightVector);
    float dotLeft = Vector3DotProduct(toCam, leftVector);


    if(dotFront > 0){
        rlVertex3f(-half, -half, half);
        rlVertex3f(half, -half, half);
        rlVertex3f(half, half, half);
        rlVertex3f(-half, half, half);
    }
    
    if(dotBack > 0){
        rlVertex3f(-half, -half, -half);
        rlVertex3f(-half, half, -half);
        rlVertex3f(half, half, -half);
        rlVertex3f(half, -half, -half);
    }
    
    if(dotTop > 0){
        rlVertex3f(-half, half, -half);
        rlVertex3f(-half, half, half);
        rlVertex3f(half, half, half);
        rlVertex3f(half, half, -half);
    }
   
    if(dotBottom > 0){
        rlVertex3f(-half, -half, -half);
        rlVertex3f(half, -half, -half);
        rlVertex3f(half, -half, half);
        rlVertex3f(-half, -half, half);
    }
    
    
    if(dotRight > 0){
        rlVertex3f(half, -half, -half);
        rlVertex3f(half, half, -half);
        rlVertex3f(half, half, half);
        rlVertex3f(half, -half, half);
    }
    

    if(dotLeft > 0){
        rlVertex3f(-half, -half, -half);
        rlVertex3f(-half, -half, half);
        rlVertex3f(-half, half, half);
        rlVertex3f(-half, half, -half);
    } 
    
    rlEnd();
    rlPopMatrix();
}

