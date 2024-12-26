#include <raylib.h>

int main() {
  InitWindow(800, 600, "Empire Earth - The New Age");

  Camera3D camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  Vector3 cube_position = {0.0f, 0.0f, 0.0f};
  DisableCursor();
  SetTargetFPS(60);

  while (!WindowShouldClose()) {
    UpdateCamera(&camera, CAMERA_FREE);
    if (IsKeyPressed('Z'))
      camera.target = (Vector3){0.0f, 0.0f, 0.0f};

    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);
    DrawCube(cube_position, 2.0f, 2.0f, 2.0f, RED);
    DrawGrid(10, 1.0f);
    EndMode3D();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
