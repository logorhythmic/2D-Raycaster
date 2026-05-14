#include "include/main.h"
#include <raylib.h>

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raycaster");
  SetTargetFPS(60);
  init_player_rays();
  init_random_boundaries();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(SKYBLUE);
    move_and_draw_player();
    update_player_rays();
    draw_random_boundaries();
    draw_all_rays();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
