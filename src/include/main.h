#ifndef MAIN_H
#define MAIN_H

#include "raylib.h"
#define SCREEN_WIDTH 1500
#define SCREEN_HEIGHT 800
#define LINE_COL BLACK

//------player.c functions-------//
void move_and_draw_player(void);

//------raycaster.c functions--------//
void init_player_rays(void);
void update_player_rays();
void init_random_boundaries();
void draw_random_boundaries(void);
void draw_rays(void);
void draw_all_rays(void);

#endif
