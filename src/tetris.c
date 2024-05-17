#include "global_variables.h"

int main() {
  WIN_INIT();
  create_windows();
  print_windows();

  init_game_info(&game);
  status_code_game_field = init_game_field();
  status_code_next_field = init_next_field();

  srand(time(NULL));
  current_shape = rand() % 7;
  count_rotation = 0;
  next_shape = rand() % 7;

  signal(SIGALRM, timer_handler);
#ifndef __STRICT_ANSI__
  start_timer(1, 0);
#endif

  wtimeout(game_board_win, 50);
  keypad(game_board_win, true);
  mousemask(ALL_MOUSE_EVENTS, NULL);

  game_loop();

  remove_game_field();
  remove_next_field();
  delete_windows();
  endwin();
  return 0;
}

void game_loop() {
  int ch;
  while (!game_over) {
    ch = wgetch(game_board_win);
    refresh_check_compleate_lines();
    refresh_update_game_level();
    update_game_speed(true);

    if (ch == ENTER_KEY) {
      enter_key_handle();
    } else if (ch == KEY_DOWN || ch == 's') {
      key_down_handle();
    } else if (ch == KEY_LEFT || ch == 'a') {
      key_left_handle();
    } else if (ch == KEY_RIGHT || ch == 'd') {
      key_right_handle();
    } else if (ch == ' ') {
      key_action_handle();
    } else if (ch == ESCAPE || status_code_game_field ||
               status_code_next_field) {
      game_over_handle();
    } else if (ch == 'p') {
      key_pause_handle();
    } else if (ch == KEY_RESIZE) {
      refresh_windows();
    }

    check_game_state();

#ifdef __STRICT_ANSI__
    userInput(Down, true);
    delay_ms(milsec);
#endif
  }
}
