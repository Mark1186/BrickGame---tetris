#ifndef C7_BRICKGAME_V1_0_1_GLOBAL_VARIABLES_H
#define C7_BRICKGAME_V1_0_1_GLOBAL_VARIABLES_H

#include "tetris.h"

bool game_field[HEIGHT + 1][WIDTH * 2 + 1];

shape_t shapes[] = {
    {SQUARE, 2, .shape = {{1, 1}, {1, 1}}, .original_shape = {{1, 1}, {1, 1}}},
    {L_SHAPE, 3, .shape = {{1, 0, 0}, {1, 0, 0}, {1, 1, 0}},
     .original_shape = {{1, 0, 0}, {1, 0, 0}, {1, 1, 0}}},
    {T_SHAPE, 3, .shape = {{0, 0, 0}, {1, 1, 1}, {0, 1, 0}},
     .original_shape = {{0, 0, 0}, {1, 1, 1}, {0, 1, 0}}},
    {I_SHAPE, 4,
     .shape = {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}},
     .original_shape =
         {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}}},
    {Z_SHAPE, 3, .shape = {{0, 0, 0}, {1, 1, 0}, {0, 1, 1}},
     .original_shape = {{0, 0, 0}, {1, 1, 0}, {0, 1, 1}}},
    {S_SHAPE, 3, .shape = {{0, 0, 0}, {0, 1, 1}, {1, 1, 0}},
     .original_shape = {{0, 0, 0}, {0, 1, 1}, {1, 1, 0}}},
    {J_SHAPE, 3, .shape = {{0, 0, 1}, {0, 0, 1}, {0, 1, 1}},
     .original_shape = {{0, 0, 1}, {0, 0, 1}, {0, 1, 1}}}};

// GLOBAL VARIABLES
WINDOW *game_board_win, *info_win, *level_win, *score_win, *next_win,
    *pause_win, *main_win, *game_over_win;

GameInfo_t game_info;
GameInfo_t game;

bool game_start = false;
bool game_over = false;
bool game_pause = false;
bool is_over = false;
int game_level = 1;
int game_speed = 0;
int game_score = 0;
int game_high_score = 0;
int game_score_for_next_level = 0;
bool exit_game = false;
bool score_update = false;
bool pause_sequence = false;

int shape_y = 1;
int shape_x = WIDTH - 1;

int current_shape = 0;
int next_shape = 0;
int count_rotation = 0;
bool is_moving = false;
int status_code_game_field = 0;
int status_code_next_field = 0;
int count_pause = 0;

struct itimerval timer;
bool need_to_change_timer_interval = false;
int new_seconds_value = 0;
int new_microseconds_value = 0;

#ifdef __STRICT_ANSI__
unsigned int milsec = 1000;
#endif

#endif  // C7_BRICKGAME_V1_0_1_GLOBAL_VARIABLES_H