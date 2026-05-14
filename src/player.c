#include "include/player.h"
#include "include/main.h"
#include "include/vector.h"
#include "math.h"
#include <raylib.h>

#define _USE_MATH_DEFINES
#define MOVE_LEN 10
#define PLAYER_RAD 20.0f
#define ANGLE_CHANGE 0.1f
#define LINE_LEN 15.0f

Vector2 player_pos = {.x = SCREEN_WIDTH / 2.0f, .y = SCREEN_HEIGHT / 2.0f};
Vector2 player_dir = {.x = 1, .y = 0};
// Player angle is in RAD
float player_angle = 0;

static void move_player_keys() {
  if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
    player_angle += ANGLE_CHANGE;
    if (player_angle > 2 * M_PI) {

      player_angle -= 2 * M_PI;
    }

    player_dir.x = cos(player_angle);
    player_dir.y = sin(player_angle);
  }

  if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
    player_angle -= ANGLE_CHANGE;
    if (player_angle < 0) {
      player_angle += 2 * M_PI;
    }
    player_dir.x = cos(player_angle);
    player_dir.y = sin(player_angle);
  }

  if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
    player_pos = v_add(player_pos, v_scale(player_dir, MOVE_LEN));
  }

  if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
    player_pos = v_add(player_pos, v_scale(player_dir, -MOVE_LEN));
  }
}

static void move_player_mouse() {
  static bool isDragging = false;

  static bool use_mouse_rot = false;
  if (IsKeyPressed(KEY_R)) {
    use_mouse_rot = !use_mouse_rot;
  }

  Vector2 mouse_pos = GetMousePosition();
  float mouse_wheel_mov = GetMouseWheelMove();
  if (mouse_wheel_mov != 0) {
    player_angle += mouse_wheel_mov * 0.2f;
  }

  if (player_angle < 0) {
    player_angle += 2 * M_PI;
  }

  if (player_angle > 2 * M_PI) {

    player_angle -= 2 * M_PI;
  }

  if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
    if (CheckCollisionPointCircle(mouse_pos, player_pos, PLAYER_RAD)) {
      isDragging = true;
    }
  } else {

    if (use_mouse_rot) {
      Vector2 mouse_vec = GetMousePosition();
      mouse_vec = v_normalize(v_sub(mouse_vec, player_pos));
      player_dir = mouse_vec;
    }
  }
  if (isDragging) {
    player_pos = mouse_pos;

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
      isDragging = false;
    }
  }
}

static void draw_player() {
  // DrawRectangle(player_x, player_y, 50, 50, RED);
  DrawCircleV(player_pos, PLAYER_RAD, RED);
}

void move_and_draw_player(void) {
  move_player_keys();
  move_player_mouse();
  draw_player();
  // DrawLineEx(player_pos, v_add(player_pos, v_scale(player_dir,
  // LINE_LEN)), 5.0f,
  //            BLACK);
}
