#include "movement.h"





extern Camera3D cam;

void update_movement() {
    Ray ray = GetMouseRay(GetMousePosition(), cam);

    Vector3 pos = Vector3Add(ray.position, Vector3Scale(ray.direction, 5.0f));
    cam.target = pos;

    Vector3 forward = Vector3Subtract(cam.target, cam.position);
    forward = Vector3Normalize(forward);

    Vector3 up = {0.0f, 1.0f, 0.0f};
    Vector3 right = Vector3CrossProduct(forward, up);
    right = Vector3Normalize(right);

    float move_speed = 100.0f * GetFrameTime();

    if (IsKeyDown(KEY_W)) {
        cam.position = Vector3Add(cam.position, Vector3Scale(forward, move_speed));
        cam.target = Vector3Add(cam.target, Vector3Scale(forward, move_speed));
    }
    if (IsKeyDown(KEY_S)) {
        cam.position = Vector3Subtract(cam.position, Vector3Scale(forward, move_speed));
        cam.target = Vector3Subtract(cam.target, Vector3Scale(forward, move_speed));
    }
    if (IsKeyDown(KEY_A)) {
        cam.position = Vector3Subtract(cam.position, Vector3Scale(right, move_speed));
        cam.target = Vector3Subtract(cam.target, Vector3Scale(right, move_speed));
    }
    if (IsKeyDown(KEY_D)) {
        cam.position = Vector3Add(cam.position, Vector3Scale(right, move_speed));
        cam.target = Vector3Add(cam.target, Vector3Scale(right, move_speed));
    }
     if (IsKeyDown(KEY_UP)) {
        cam.position.y += move_speed;
        cam.target.y += move_speed;
    }
    if (IsKeyDown(KEY_DOWN)) {
        cam.position.y -= move_speed;
        cam.target.y -= move_speed;
    }
}
