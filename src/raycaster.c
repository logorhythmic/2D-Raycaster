#include "include/main.h"
#include "include/player.h"
#include "include/vector.h"
#include "math.h"
#include <float.h>
#include <raylib.h>
#include <stdio.h>

#define FOV 180
#define D_SPACING 3
#define D_R 0.0174533
#define LINE_THICK 0.5f
#define NUM_OF_BOUNDARIES 5
#define BOUND_THICK 2.0f

#define NUM_OF_RAYS (int)(FOV / D_SPACING)
Vector2 base_ray_array[FOV / D_SPACING];
Vector2 ray_array[FOV / D_SPACING];

typedef struct {
  Vector2 start_vec;
  Vector2 end_vec;
} boundary_vec;

boundary_vec boundary_array[NUM_OF_BOUNDARIES];

void init_random_boundaries() {
  for (int i = 0; i < NUM_OF_BOUNDARIES; i++) {

    boundary_array[i].start_vec =
        (Vector2){.x = GetRandomValue(0, SCREEN_WIDTH),
                  .y = GetRandomValue(0, SCREEN_HEIGHT)};

    boundary_array[i].end_vec =
        (Vector2){.x = GetRandomValue(0, SCREEN_WIDTH),
                  .y = GetRandomValue(0, SCREEN_HEIGHT)};
  }
}
void draw_random_boundaries(void) {
  for (int i = 0; i < NUM_OF_BOUNDARIES; i++) {
    DrawLineEx(boundary_array[i].start_vec, boundary_array[i].end_vec,
               BOUND_THICK, BLACK);
  }
}

void init_player_rays() {
  float deg = -((((float)NUM_OF_RAYS - 1.0f) / 2.0f) * (float)D_SPACING);
  for (int i = 0; i < NUM_OF_RAYS; i++) {
    base_ray_array[i] = (Vector2){.x = cos(deg * D_R), .y = sin(deg * D_R)};
    deg += D_SPACING;
  }
}

void update_player_rays() {
  float delta_cos = cos(player_angle);
  float delta_sin = sin(player_angle);

  for (int i = 0; i < NUM_OF_RAYS; i++) {
    float old_x = ray_array[i].x;
    ray_array[i].x =
        base_ray_array[i].x * delta_cos - base_ray_array[i].y * delta_sin;
    ray_array[i].y =
        base_ray_array[i].x * delta_sin + base_ray_array[i].y * delta_cos;
  }
}

typedef struct {
  bool valid;
  Vector2 point_vec;
  float dist;
} intersect_data;

intersect_data calc_intersection(Vector2 player_ray, Vector2 start_vec,
                                 Vector2 end_vec) {
  Vector2 V = v_sub(start_vec, player_pos);
  Vector2 R = v_sub(end_vec, start_vec);
  Vector2 S = player_ray;
  float D = v_det(S, R);
  if (D == 0) {
    return (intersect_data){.valid = false, .point_vec = player_pos, .dist = 0};
  }
  float D1 = v_det(V, R);
  float D2 = v_det(V, S);
  float t = D1 / D;
  float s = D2 / D;
  if (t > 0.0f && s > 0.0f && s <= 1.0f) {
    return (intersect_data){.valid = true,
                            .point_vec = v_add(player_pos, v_scale(S, t)),
                            .dist = t};
  }
  return (intersect_data){.valid = false, .point_vec = player_pos, .dist = 0};
}

void draw_all_rays() {

  for (int i = 0; i < NUM_OF_RAYS; i++) {
    float min_distance = FLT_MAX;
    Vector2 closest_point = player_pos;
    for (int j = 0; j < NUM_OF_BOUNDARIES; j++) {

      intersect_data intersect = calc_intersection(v_normalize(ray_array[i]),
                                                   boundary_array[j].start_vec,
                                                   boundary_array[j].end_vec);
      bool isValid = intersect.valid;
      Vector2 intersection_point = intersect.point_vec;
      float dist = intersect.dist;
      if (dist < min_distance && isValid) {
        min_distance = dist;
        closest_point = intersection_point;
      }
    }
    TraceLog(LOG_INFO, "Drawing line x: %d, Drawing line y: %d\n",
             closest_point.x, closest_point.y);
    DrawLineV(player_pos, closest_point, WHITE);
  }
}
