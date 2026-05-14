#ifndef VECTOR_H
#define VECTOR_H
#include "math.h"
#include "raymath.h"

static inline Vector2 v_add(Vector2 a, Vector2 b) {
  return (Vector2){a.x + b.x, a.y + b.y};
}

// Vector A - Vector  eB
static inline Vector2 v_sub(Vector2 a, Vector2 b) {
  return (Vector2){a.x - b.x, a.y - b.y};
}

static inline Vector2 v_scale(Vector2 a, float scale) {
  return (Vector2){a.x * scale, a.y * scale};
}

static inline Vector2 v_normalize(Vector2 a) {
  float mag = sqrt((a.x * a.x + a.y * a.y));

  if (mag > 0) {
    return (Vector2){a.x / mag, a.y / mag};
  }

  return (Vector2){0, 0};
}

static inline float v_det(Vector2 a, Vector2 b) {
  return (a.x * b.y - a.y * b.x);
}
static inline bool v_same(Vector2 a, Vector2 b) {
  if (a.x == b.x && a.y == b.y) {
    return true;
  }
  return false;
}

#endif
