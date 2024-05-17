#ifndef C7_BRICKGAME_V1_0_1_TETRIS_H
#define C7_BRICKGAME_V1_0_1_TETRIS_H

#include <ctype.h>
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define WIDTH 10
#define HEIGHT 20
#define MAX_SIZE 4

#define ERROR 1
#define CALC_ERROR 2

#define ESCAPE 27
#define ENTER_KEY 10

#define WIN_INIT()                          \
  {                                         \
    initscr();                              \
    noecho();                               \
    nodelay(stdscr, true);                  \
    curs_set(0);                            \
    start_color();                          \
    init_pair(1, COLOR_BLACK, COLOR_CYAN);  \
    init_pair(2, COLOR_BLACK, COLOR_WHITE); \
    init_pair(3, COLOR_BLACK, COLOR_GREEN); \
  }

#define INTRO_MESSAGE "Press ENTER to start!"
#define SCORE_NULL_MESSAGE "High score is NULL!"
#define MEMORY_ALLOCATING_MESSAGE "Memory allocating is fail!"
#define FILE_OPEN_MESSAGE "File opening is fail!"
#define WRITE_SUCCES_MESSAGE "Record written successfully!"
#define WRITE_FIALED_MESSAGE "Failed to write record!"
#define FILE_NAME "game_info.txt"
#define MODES_READ "a+"
#define MODES_WRITE "w+"

typedef enum {
  SQUARE = 0,
  L_SHAPE,
  T_SHAPE,
  I_SHAPE,
  Z_SHAPE,
  S_SHAPE,
  J_SHAPE
} type_shape;

typedef struct {
  type_shape type;
  int size;
  int shape[MAX_SIZE][MAX_SIZE];
  int original_shape[MAX_SIZE][MAX_SIZE];
} shape_t;

extern shape_t shapes[];

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

extern bool game_field[HEIGHT + 1][WIDTH * 2 + 1];

void userInput(UserAction_t action, bool hold);
GameInfo_t updateCurrentState();

int init_game_field();
void remove_game_field();
int clear_game_field();
void refresh_clear_game_field();

int init_next_field();
void remove_next_field();
int clear_next_field();
void refresh_clear_next_field();

void default_rotation(shape_t *shape);
void update_draw_shape(int y, int x, shape_t shape, WINDOW *win);
void draw_next_shape(int y, int x, shape_t shape, WINDOW *win);
bool check_collision(int y, int x, shape_t shape);
void attaching_shape();
void check_compleate_lines();
void refresh_check_compleate_lines();
void rotate_shape(shape_t *shape);
void rotate_shape_revert(shape_t *shape);
void normolize_position_shape_in_left(shape_t *shape);
void normolize_position_shape_in_right(shape_t *shape);

void timer_handler();
void start_timer(int seconds, int milliseconds);
void stop_timer();
void file_read();
void file_write();
void refresh_update_game_level();
void update_game_level();
void update_game_speed(bool is_level_speed);
void update_game_score(int count_lines);

void delay_ms(unsigned int milliseconds);
void game_loop();
int init_game_info(GameInfo_t *game);
void create_windows();
void print_windows();
void refresh_windows();
void delete_windows();

void enter_key_handle();
void key_down_handle();
void key_left_handle();
void key_right_handle();
void key_action_handle();
void key_pause_handle();
void key_exit_handle();
void check_game_state();
void game_over_handle();
void move_horizontal(UserAction_t action);
bool move_vertical();
void collided_handle(bool collided);
void checking_field_boundaries();
void figure_alignment_after_rotation();
void start_handle(bool hold);
void pause_handle(bool hold);
void terminate_handle(bool hold);
void action_processing(bool hold);
void set_shape(int y, int x, shape_t shape);

// GLOBAL VARIABLES
extern WINDOW *game_board_win, *info_win, *level_win, *score_win, *next_win,
    *pause_win, *main_win, *game_over_win;

extern GameInfo_t game_info;
extern GameInfo_t game;

extern bool game_start;
extern bool game_over;
extern bool game_pause;
extern int game_level;
extern int game_speed;
extern int game_score;
extern int game_high_score;
extern int game_score_for_next_level;
extern bool is_over;
extern bool exit_game;
extern bool score_update;
extern bool pause_sequence;

extern int shape_y;
extern int shape_x;

extern int current_shape;
extern int next_shape;
extern int count_rotation;
extern bool is_moving;
extern int status_code_game_field;
extern int status_code_next_field;
extern int count_pause;

extern struct itimerval timer;
extern bool need_to_change_timer_interval;
extern int new_seconds_value;
extern int new_microseconds_value;

#ifdef __STRICT_ANSI__
extern unsigned int milsec;
#endif

#endif  // C7_BRICKGAME_V1_0_1_TETRIS_H
