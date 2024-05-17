#include "../../tetris.h"

void refresh_clear_game_field() {
  clear_game_field();
  for (int y = 1; y < HEIGHT + 1; y++) {
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      if (game_info.field[y][x]) {
        mvwaddch(game_board_win, y, x, ' ' | COLOR_PAIR(2));
      } else {
        mvwaddch(game_board_win, y, x, ' ');
      }
    }
  }
}

void refresh_clear_next_field() {
  clear_next_field();
  for (int y = 1; y < HEIGHT / 3; y++) {
    for (int x = 1; x < WIDTH - 1; x++) {
      if (!game_info.next[y][x]) {
        mvwaddch(next_win, y, x, ' ');
      }
    }
  }
}

void draw_shape(WINDOW *win) {
  for (int i = 1; i < HEIGHT + 1; i++) {
    for (int j = 1; j < WIDTH * 2 + 1; j++) {
      if (game_field[i][j]) {
        mvwaddch(win, i, j, ' ' | COLOR_PAIR(1) | A_UNDERLINE);
      }
    }
  }
}

void update_draw_shape(int y, int x, shape_t shape, WINDOW *win) {
  set_shape(y, x, shape);
  draw_shape(win);
}

void draw_next_shape(int y, int x, shape_t shape, WINDOW *win) {
  for (int i = 0; i < shape.size; ++i) {
    for (int j = 0; j < shape.size; ++j) {
      if (shape.original_shape[i][j]) {
        mvwaddch(win, y + i, x + j * 2, ' ' | COLOR_PAIR(1) | A_UNDERLINE);
        mvwaddch(win, y + i, x + j * 2 + 1, ' ' | COLOR_PAIR(1) | A_UNDERLINE);
      }
    }
  }
}

void refresh_update_game_score(int count_lines) {
  if (score_win) {
    update_game_score(count_lines);
    mvwprintw(score_win, 2, 1, "%d", game_high_score);
    mvwprintw(score_win, 5, 1, "%d", game_score);
  }
}

void refresh_check_compleate_lines() {
  if (game_info.field && game_board_win) {
    int count_lines = 0;
    check_compleate_lines();
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      if (!game_info.field[0][x]) {
        mvwaddch(game_board_win, 0, x, ' ');
      }
    }

    refresh_update_game_score(count_lines);
  }
}

void refresh_update_game_level() {
  update_game_level();
  if (score_update) {
    for (int i = 5, k = 2; i < HEIGHT / 4 + 1 && k < 3; i++, k++) {
      for (int j = 0; j < WIDTH; j++) {
        mvwaddch(score_win, i, j, ' ');
        mvwaddch(score_win, k, j, ' ');
      }
    }
  }
  mvwprintw(level_win, 1, 7, "%d", game_level);
  mvwprintw(level_win, 2, 7, "%d", game_speed);
}

void start_handle(bool hold) {
  if (hold) {
    file_read();
    game_start = true;
  }
}

void pause_handle(bool hold) {
  if (hold) {
#ifndef __STRICT_ANSI__
    stop_timer();
#else
    if (game_start)
      pause_sequence = true;
    else {
      shape_y = 0;
      shape_x = WIDTH - 1;
    }
#endif
  } else {
    update_game_speed(false);
    pause_sequence = false;
  }
}

void terminate_handle(bool hold) {
  if (hold) {
    file_write();
    game_over = true;
  }
}

void userInput(UserAction_t action, bool hold) {
  switch (action) {
    case Start:
      start_handle(hold);
      break;
    case Pause:
      pause_handle(hold);
      break;
    case Terminate:
      terminate_handle(hold);
      break;
    case Left:
      if (hold && !pause_sequence) {
        move_horizontal(Left);
      }
      break;
    case Right:
      if (hold && !pause_sequence) {
        move_horizontal(Right);
      }
      break;
    case Up:
      break;
    case Down:
      if (hold && !pause_sequence) {
        bool collided = move_vertical();
        collided_handle(collided);
        if (collided) refresh_check_compleate_lines();
      }
      break;
    case Action:
      action_processing(hold);
      break;
    default:
      break;
  }
}

GameInfo_t updateCurrentState() {
  GameInfo_t info;
  info.high_score = game_score_for_next_level;
  if (game_pause) {
    info.pause = 1;
  } else {
    info.pause = 0;
  }

  refresh_clear_game_field();
  refresh_clear_next_field();

  update_draw_shape(shape_y, shape_x, shapes[current_shape], game_board_win);
  draw_next_shape(1, 2, shapes[next_shape], next_win);

  return info;
}

void timer_handler() {
  if (need_to_change_timer_interval) {
    timer.it_value.tv_sec = new_seconds_value;
    timer.it_value.tv_usec = new_microseconds_value;
    timer.it_interval.tv_sec = new_seconds_value;
    timer.it_interval.tv_usec = new_microseconds_value;
    setitimer(ITIMER_REAL, &timer, NULL);

    need_to_change_timer_interval = false;
  }

  userInput(Down, true);
}

void create_windows() {
  if (!game_board_win && !main_win && !info_win && !level_win && !next_win) {
    game_board_win = newwin(HEIGHT + 2, WIDTH * 2 + 2, 0, 0);
    main_win = newwin(HEIGHT + 2, WIDTH * 3 + 4, 0, 0);
    info_win = newwin(HEIGHT + 2, WIDTH + 2, 0, WIDTH * 2 + 2);
    level_win = derwin(info_win, HEIGHT / 5, WIDTH, 1, 1);
    score_win = derwin(info_win, HEIGHT / 4 + 2, WIDTH, HEIGHT / 4, 1);
    next_win = derwin(info_win, HEIGHT / 3 + 1, WIDTH, HEIGHT / 2 + 2, 1);
  }
}

void print_windows() {
  if (main_win && level_win && score_win) {
    wattron(main_win, COLOR_PAIR(3));
    mvwprintw(main_win, HEIGHT / 2 - 1, WIDTH / 2, "                     ");
    mvwprintw(main_win, HEIGHT / 2, WIDTH / 2, INTRO_MESSAGE);
    mvwprintw(main_win, HEIGHT / 2 + 1, WIDTH / 2, "                     ");
    wattroff(main_win, COLOR_PAIR(3));
    mvwprintw(level_win, 1, 1, "LEVEL:");
    mvwprintw(level_win, 2, 1, "SPEED:");
    mvwprintw(score_win, 1, 1, "Record:");
    mvwprintw(score_win, 4, 1, "SCORE:");
    mvwprintw(info_win, 20, 1, "Pause: %d", count_pause);
  }
}

void refresh_windows() {
  if (game_board_win && info_win && level_win && score_win && next_win) {
    box(game_board_win, 0, 0);
    box(info_win, 0, 0);
    box(level_win, 0, 0);
    box(score_win, 0, 0);
    box(next_win, 0, 0);
    refresh();
    wrefresh(game_board_win);
    wrefresh(info_win);
    wrefresh(level_win);
    wrefresh(score_win);
    wrefresh(next_win);
  }
}

void delete_windows() {
  delwin(main_win);
  delwin(game_board_win);
  delwin(info_win);
  delwin(level_win);
  delwin(score_win);
  delwin(next_win);
  delwin(pause_win);
  delwin(game_over_win);
}

void enter_key_handle() {
  game.pause = 0;
  userInput(Start, true);
  userInput(Pause, false);
}

void key_down_handle() {
  if (!game.pause && !is_over) {
#ifndef __STRICT_ANSI__
    start_timer(0, 5000);
#else
    milsec = 10;
#endif
  }
}

void key_left_handle() {
  is_moving = true;
  if (!game.pause && !is_over) {
    userInput(Left, true);
  }
}

void key_right_handle() {
  is_moving = true;
  if (!game.pause && !is_over) {
    userInput(Right, true);
  }
}

void key_action_handle() {
  if (!game.pause && !is_over) {
    userInput(Action, true);
  }
}

void key_pause_handle() {
  if (game_board_win) {
    if (!exit_game && game_start) {
      game_pause = !game_pause;
      if (game_pause) {
        wattron(game_board_win, COLOR_PAIR(3));
        mvwprintw(game_board_win, HEIGHT / 2, 1, "                    ");
        mvwprintw(game_board_win, HEIGHT / 2 + 1, 1, "  Game is Paused!   ");
        mvwprintw(game_board_win, HEIGHT / 2 + 2, 1, "                    ");
        wattroff(game_board_win, COLOR_PAIR(3));
        userInput(Pause, true);
        game.pause = 1;
        mvwprintw(info_win, 20, 1, "Pause: %d", ++count_pause);
      } else {
        userInput(Pause, false);
        game.pause = 0;
      }
    }
  }
}

void game_over_handle() {
  if (game_start) {
    exit_game = true;
    key_exit_handle();
    if (!game.pause) userInput(Terminate, true);
  }
}

void key_exit_handle() {
  if (game_board_win) {
    game_pause = !game_pause;
    if (game_pause) {
      wattron(game_board_win, COLOR_PAIR(3));
      mvwprintw(game_board_win, HEIGHT / 2, 3, "                ");
      mvwprintw(game_board_win, HEIGHT / 2 + 1, 3, "  GAME is OVER! ");
      mvwprintw(game_board_win, HEIGHT / 2 + 2, 3, "                ");
      wattroff(game_board_win, COLOR_PAIR(3));
      userInput(Pause, true);
      game.pause = 1;
    } else {
      userInput(Pause, false);
      game.pause = 0;
    }
  }
}

void check_game_state() {
  if (!game_pause && game_start) {
    game = updateCurrentState();
    refresh_windows();
  } else if (!game_start) {
    game.pause = 1;
    userInput(Pause, true);
    box(main_win, 0, 0);
    refresh();
    wrefresh(main_win);
  } else {
    overlay(game_board_win, pause_win);
  }

  for (int x = 0; x < WIDTH * 2 && !is_over; x++) {
    if (game_info.field[1][x]) {
      is_over = true;
    }
  }

  if (is_over) {
    exit_game = true;
    key_exit_handle();
  }
}