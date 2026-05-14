#include "include/main.h"
#include <raylib.h>

int main() {
  SetConfigFlags(FLAG_MSAA_4X_HINT);
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raycaster");
  SetTargetFPS(60);
  init_player_rays();
  init_random_boundaries();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(SKYBLUE);
    update_player_rays();
    draw_random_boundaries();
    draw_all_rays();

    move_and_draw_player();
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
