#include "../../tetris.h"

int init_game_field() {
  int status_code = OK;
  bool error_occurred = false;
  game_info.field = (int **)calloc(HEIGHT + 1, sizeof(int *));
  if (game_info.field) {
    for (int i = 0; i < HEIGHT + 1 && !error_occurred; ++i) {
      game_info.field[i] = (int *)calloc(WIDTH * 2 + 1, sizeof(int));
      if (!game_info.field[i]) {
        status_code = ERROR;
        error_occurred = true;
      }
    }
    if (error_occurred) {
      remove_game_field();
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}

void remove_game_field() {
  if (game_info.field) {
    for (int i = 0; i < HEIGHT + 1; i++) {
      free(game_info.field[i]);
      game_info.field[i] = NULL;
    }
    free(game_info.field);
    game_info.field = NULL;
  }
}

int clear_game_field() {
  int status_code = OK;
  if (game_info.field) {
    for (int y = 1; y < HEIGHT + 1; y++) {
      for (int x = 1; x < WIDTH * 2 + 1; x++) {
        game_field[y][x] = false;
      }
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}

int init_next_field() {
  int status_code = OK;
  bool error_occurred = false;
  game_info.next = (int **)calloc(HEIGHT / 3, sizeof(int *));
  if (game_info.next) {
    for (int i = 0; i < HEIGHT / 3 && !error_occurred; ++i) {
      game_info.next[i] = (int *)calloc(WIDTH - 1, sizeof(int));
      if (!game_info.next[i]) {
        status_code = ERROR;
        error_occurred = true;
      }
    }
    if (error_occurred) {
      remove_next_field();
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}

void remove_next_field() {
  if (game_info.next) {
    for (int i = 0; i < HEIGHT / 3; i++) {
      free(game_info.next[i]);
      game_info.next[i] = NULL;
    }
    free(game_info.next);
    game_info.next = NULL;
  }
}

int clear_next_field() {
  int status_code = OK;
  if (game_info.next) {
    for (int y = 0; y < HEIGHT / 3; y++) {
      for (int x = 0; x < WIDTH - 1; x++) {
        game_info.next[y][x] = 0;
      }
    }
  } else {
    status_code = ERROR;
  }
  return status_code;
}

void set_shape(int y, int x, shape_t shape) {
  for (int i = 0; i < shape.size; ++i) {
    for (int j = 0; j < shape.size; ++j) {
      if (shape.shape[i][j]) {
        game_field[y + i][x + j * 2] = true;
        game_field[y + i][x + j * 2 + 1] = true;
      }
    }
  }
}

void move_horizontal(UserAction_t action) {
  if (action == Left)
    shape_x -= 2;
  else if (action == Right)
    shape_x += 2;

  if (check_collision(shape_y, shape_x, shapes[current_shape])) {
    if (action == Left)
      shape_x += 2;
    else if (action == Right)
      shape_x -= 2;
  } else {
    bool need_shifting = false;
    for (int y = 1; y < HEIGHT + 1; ++y) {
      if (game_field[y][action == Left ? 1 : WIDTH * 2]) {
        need_shifting = true;
      }
    }
    if (need_shifting) {
      if (action == Left)
        shape_x += 2;
      else if (action == Right)
        shape_x -= 2;
    }
  }
}

void default_rotation(shape_t *shape) {
  if (shape) {
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        shape->shape[i][j] = shape->original_shape[i][j];
      }
    }
  }
}

void rotate_shape(shape_t *shape) {
  if (shape) {
    int temp[4][4];
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        temp[i][j] = shape->shape[i][j];
      }
    }
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        shape->shape[j][shape->size - 1 - i] = temp[i][j];
      }
    }
  }
}

void rotate_shape_revert(shape_t *shape) {
  if (shape) {
    int temp[4][4];
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        temp[i][j] = shape->shape[i][j];
      }
    }
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        shape->shape[shape->size - 1 - j][i] = temp[i][j];
      }
    }
  }
}

void normolize_position_shape_in_left(shape_t *shape) {
  if (shape) {
    int minCol = shape->size - 1;
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        if (shape->shape[i][j] == 1 && j < minCol) {
          minCol = j;
          break;
        }
      }
    }
    for (int i = 0; i < shape->size; ++i) {
      for (int j = 0; j < shape->size; ++j) {
        if (j + minCol < shape->size) {
          shape->shape[i][j] = shape->shape[i][j + minCol];
        } else {
          shape->shape[i][j] = 0;
        }
      }
    }
  }
}

void normolize_position_shape_in_right(shape_t *shape) {
  if (shape) {
    int maxCol = 0;
    for (int i = 0; i < shape->size; ++i) {
      for (int j = shape->size - 1; j >= 0; --j) {
        if (shape->shape[i][j] == 1 && j > maxCol) {
          maxCol = j;
          break;
        }
      }
    }
    for (int i = 0; i < shape->size; ++i) {
      for (int j = shape->size - 1; j >= 0; --j) {
        if (j - (shape->size - 1 - maxCol) >= 0) {
          shape->shape[i][j] = shape->shape[i][j - (shape->size - 1 - maxCol)];
        } else {
          shape->shape[i][j] = 0;
        }
      }
    }
  }
}

bool check_collision(int y, int x, shape_t shape) {
  bool is_collision = false;
  for (int i = 0; i < shape.size && !is_collision; ++i) {
    for (int j = 0; j < shape.size && !is_collision; ++j) {
      if (y + i >= 1 && y + i < HEIGHT + 1 && x + j * 2 >= 1 &&
          x + j * 2 < WIDTH * 2 + 1) {
        if (shape.shape[i][j] && game_info.field[y + i][x + j * 2]) {
          is_collision = true;
        }
      }
    }
  }
  return is_collision;
}

void attaching_shape() {
  for (int y = 1; y < HEIGHT + 1; ++y) {
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      if (game_field[y][x]) {
        game_info.field[y][x] = 1;
      }
    }
  }
}

void update_game_score(int count_lines) {
  switch (count_lines) {
    case 1:
      game_score_for_next_level += 100;
      game_score += 100;
      break;
    case 2:
      game_score_for_next_level += 300;
      game_score += 300;
      break;
    case 3:
      game_score_for_next_level += 700;
      game_score += 700;
      break;
    case 4:
      game_score_for_next_level += 1500;
      game_score += 1500;
      break;
    default:
      break;
  }
  if (game_score > game_high_score) {
    game_high_score = game_score;
  }
}

void check_compleate_lines() {
  int count_lines = 0;
  for (int y = 1; y < HEIGHT + 1; y++) {
    bool complete_line = true;
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      if (!game_info.field[y][x]) {
        complete_line = false;
        break;
      }
    }
    if (complete_line) {
      for (int y_del = y; y_del > 1; y_del--) {
        for (int x = 1; x < WIDTH * 2 + 1; x++) {
          game_info.field[y_del][x] = game_info.field[y_del - 1][x];
        }
      }
      for (int x = 1; x < WIDTH * 2 + 1; x++) {
        game_info.field[0][x] = 0;
        game_field[0][x] = 0;
      }

      count_lines++;
    }
  }
  update_game_score(count_lines);
}

bool move_vertical() {
  bool is_collide = false;
  shape_y++;
  if (check_collision(shape_y, shape_x, shapes[current_shape])) {
    shape_y--;
    is_collide = true;
  }

  for (int x = 1; x < WIDTH * 2 + 1 && !is_collide; x++) {
    if (game_field[HEIGHT][x]) {
      is_collide = true;
    }
  }

  return is_collide;
}

void collided_handle(bool collided) {
  if (collided) {
    attaching_shape();
    default_rotation(&shapes[current_shape]);

    stop_timer();
    delay_ms(300);
    shape_y = 0;
    shape_x = WIDTH - 1;
    count_rotation = 0;
    current_shape = next_shape;
    next_shape = rand() % 7;

    check_compleate_lines();
    update_game_level();
    update_game_speed(false);
  }
}

void checking_field_boundaries() {
  bool is_bottom = false;
  for (int x = 1; x < WIDTH * 2 + 1; x++) {
    if ((current_shape != SQUARE) && (game_field[HEIGHT][x])) {
      is_bottom = true;
    }
  }
  if (is_bottom && current_shape != I_SHAPE) {
    shape_y = HEIGHT - 2;
  } else if (is_bottom && current_shape == I_SHAPE) {
    shape_y = HEIGHT - 3;
  }

  bool shift_is_right = false;
  for (int y = 1; y < HEIGHT + 1; ++y) {
    if ((current_shape != SQUARE) && (game_field[y][WIDTH * 2])) {
      shift_is_right = true;
    }
  }
  if (shift_is_right && current_shape != I_SHAPE) {
    shape_x = WIDTH * 2 - 5;
  } else if (shift_is_right && current_shape == I_SHAPE) {
    shape_x = WIDTH * 2 - 7;
  }

  bool shift_is_left = false;
  for (int y = 1; y < HEIGHT + 1; ++y) {
    if ((current_shape != SQUARE) && (game_field[y][1])) {
      shift_is_left = true;
    }
  }
  if (shift_is_left && current_shape != I_SHAPE) {
    shape_x = 1;
  } else if (shift_is_left && current_shape == I_SHAPE) {
    shape_x = 1;
  }
}

void update_game_level() {
  score_update = false;
  if (game_level <= 8) {
    if (game_score_for_next_level >= 600 && game_score_for_next_level < 1200) {
      game_score_for_next_level -= 600;
      game_level++;
      score_update = true;
    } else if (game_score_for_next_level >= 1200) {
      game_score_for_next_level -= 1200;
      game_level += 2;
      score_update = true;
    }
  } else if (game_level == 9) {
    if (game_score_for_next_level >= 600) {
      game_score_for_next_level -= 600;
      game_level++;
      score_update = true;
    }
  }
}

void figure_alignment_after_rotation() {
  switch (current_shape) {
    case L_SHAPE:
      normolize_position_shape_in_left(&shapes[current_shape]);
      if (count_rotation >= 4) {
        normolize_position_shape_in_right(&shapes[current_shape]);
        count_rotation = 0;
      }
      break;
    case T_SHAPE:
    case Z_SHAPE:
    case S_SHAPE:
      normolize_position_shape_in_left(&shapes[current_shape]);
      if (count_rotation >= 3) {
        normolize_position_shape_in_right(&shapes[current_shape]);
        count_rotation = -1;
      }
      break;
    case J_SHAPE:
      normolize_position_shape_in_right(&shapes[current_shape]);
      if (count_rotation >= 4) {
        normolize_position_shape_in_left(&shapes[current_shape]);
        count_rotation = 0;
      }
      break;
  }
}

void action_processing(bool hold) {
  if (hold) {
    count_rotation++;
    rotate_shape(&shapes[current_shape]);
    if (check_collision(shape_y, shape_x, shapes[current_shape])) {
      rotate_shape_revert(&shapes[current_shape]);
      count_rotation--;
    } else {
      checking_field_boundaries();
      figure_alignment_after_rotation();
    }
  }
}

void start_timer(int seconds, int milliseconds) {
  timer.it_value.tv_sec = seconds;
  timer.it_value.tv_usec = milliseconds;
  timer.it_interval.tv_sec = seconds;
  timer.it_interval.tv_usec = milliseconds;
  setitimer(ITIMER_REAL, &timer, NULL);
}

void stop_timer() {
  timer.it_value.tv_sec = 0;
  timer.it_value.tv_usec = 0;
  timer.it_interval.tv_sec = 0;
  timer.it_interval.tv_usec = 0;
  setitimer(ITIMER_REAL, &timer, NULL);
}

void update_game_speed(bool is_level_set) {
  if (game_level == 1 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(1, 0);
#else
    milsec = 1000;
#endif
    game_speed = 1;
    is_level_set = true;
  } else if (game_level == 2 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 900000);
#else
    milsec = 900;
#endif
    game_speed = 2;
    is_level_set = true;
  } else if (game_level == 3 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 800000);
#else
    milsec = 800;
#endif
    game_speed = 3;
    is_level_set = true;
  } else if (game_level == 4 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 700000);
#else
    milsec = 700;
#endif
    game_speed = 4;
    is_level_set = true;
  } else if (game_level == 5 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 600000);
#else
    milsec = 600;
#endif
    game_speed = 5;
    is_level_set = true;
  } else if (game_level == 6 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 500000);
#else
    milsec = 500;
#endif
    game_speed = 6;
    is_level_set = true;
  } else if (game_level == 7 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 400000);
#else
    milsec = 400;
#endif
    game_speed = 7;
    is_level_set = true;
  } else if (game_level == 8 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 300000);
#else
    milsec = 300;
#endif
    game_speed = 8;
    is_level_set = true;
  } else if (game_level == 9 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 200000);
#else
    milsec = 200;
#endif
    game_speed = 9;
    is_level_set = true;
  } else if (game_level == 10 && !is_level_set) {
#ifndef __STRICT_ANSI__
    stop_timer();
    start_timer(0, 100000);
#else
    milsec = 100;
#endif
    game_speed = 10;
    is_level_set = true;
  }
}

void delay_ms(unsigned int milliseconds) {
  clock_t start_time = clock();
  unsigned int ms_passed = 0;
  while (ms_passed < milliseconds) {
    ms_passed = (unsigned int)((clock() - start_time) * 1000 / CLOCKS_PER_SEC);
  }
}

int init_game_info(GameInfo_t *game) {
  int status_code = OK;
  if (game) {
    game->pause = 0;
    game->level = 0;
    game->high_score = 0;
    game->speed = 0;
    game->score = 0;
  } else {
    status_code = ERROR;
  }
  return status_code;
}