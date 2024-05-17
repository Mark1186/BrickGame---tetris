#include <check.h>

#include "../../global_variables.h"
#include "../../tetris.h"

START_TEST(s21_test_init_game_field) {
  int status_code = init_game_field();
  ck_assert_int_eq(status_code, OK);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_init_next_field) {
  int status_code = init_next_field();
  ck_assert_int_eq(status_code, OK);
  remove_next_field();
}
END_TEST

START_TEST(s21_test_clear_game_field1) {
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, ERROR);
}
END_TEST

START_TEST(s21_test_clear_game_field2) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_clear_game_field3) {
  // DEFAULT GAME FIELD
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH * 2; x++) {
      ck_assert_int_eq(game_info.field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape1) {
  init_game_field();
  // SQUARE SHAPE
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  set_shape(1, 1, shapes[SQUARE]);
  // AUTO TESTING
  for (int i = 1; i <= HEIGHT; i++) {
    for (int j = 1; j <= WIDTH * 2; j++) {
      if (game_field[i][j])
        ck_assert_int_eq(game_field[i][j], 1);
      else
        ck_assert_int_eq(game_field[i][j], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape2) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // SQUARE SHAPE
  set_shape(1, 1, shapes[SQUARE]);
  // MANUAL TESTING
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  ck_assert_int_eq(game_field[3][1], 0);
  ck_assert_int_eq(game_field[3][2], 0);
  ck_assert_int_eq(game_field[4][1], 0);
  ck_assert_int_eq(game_field[4][2], 0);
  ck_assert_int_eq(game_field[3][3], 0);
  ck_assert_int_eq(game_field[3][4], 0);
  ck_assert_int_eq(game_field[4][3], 0);
  ck_assert_int_eq(game_field[4][4], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape3) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // L-SHAPE
  set_shape(1, 1, shapes[L_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[L_SHAPE].size; y++) {
    for (int x = 0; x < shapes[L_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape4) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // L-SHAPE
  set_shape(1, 1, shapes[L_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  ck_assert_int_eq(game_field[1][3], 0);
  ck_assert_int_eq(game_field[4][1], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape5) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // J-SHAPE
  set_shape(1, 1, shapes[J_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[J_SHAPE].size; y++) {
    for (int x = 0; x < shapes[J_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape6) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // J-SHAPE
  set_shape(1, 1, shapes[J_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  ck_assert_int_eq(game_field[1][1], 0);
  ck_assert_int_eq(game_field[4][1], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape7) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // S-SHAPE
  set_shape(1, 1, shapes[S_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[S_SHAPE].size; y++) {
    for (int x = 0; x < shapes[S_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape8) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // S-SHAPE
  set_shape(1, 1, shapes[S_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  ck_assert_int_eq(game_field[2][1], 0);
  ck_assert_int_eq(game_field[2][2], 0);
  ck_assert_int_eq(game_field[3][5], 0);
  ck_assert_int_eq(game_field[3][6], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape9) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // Z-SHAPE
  set_shape(1, 1, shapes[Z_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[Z_SHAPE].size; y++) {
    for (int x = 0; x < shapes[Z_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape10) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // Z-SHAPE
  set_shape(1, 1, shapes[Z_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  ck_assert_int_eq(game_field[2][5], 0);
  ck_assert_int_eq(game_field[2][6], 0);
  ck_assert_int_eq(game_field[3][1], 0);
  ck_assert_int_eq(game_field[3][2], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape11) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // T-SHAPE
  set_shape(1, 1, shapes[T_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[T_SHAPE].size; y++) {
    for (int x = 0; x < shapes[T_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape12) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // T-SHAPE
  set_shape(1, 1, shapes[T_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  ck_assert_int_eq(game_field[3][1], 0);
  ck_assert_int_eq(game_field[3][2], 0);
  ck_assert_int_eq(game_field[3][5], 0);
  ck_assert_int_eq(game_field[3][6], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape13) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // I-SHAPE
  set_shape(1, 1, shapes[I_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[I_SHAPE].size; y++) {
    for (int x = 0; x < shapes[I_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_draw_shape14) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // I-SHAPE
  set_shape(1, 1, shapes[I_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  ck_assert_int_eq(game_field[1][1], 0);
  ck_assert_int_eq(game_field[1][2], 0);
  ck_assert_int_eq(game_field[2][1], 0);
  ck_assert_int_eq(game_field[2][2], 0);
  ck_assert_int_eq(game_field[3][1], 0);
  ck_assert_int_eq(game_field[3][2], 0);
  ck_assert_int_eq(game_field[4][1], 0);
  ck_assert_int_eq(game_field[4][2], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_clear_game_field4) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // I-SHAPE
  set_shape(1, 1, shapes[I_SHAPE]);
  // AUTO
  for (int y = 0; y < shapes[I_SHAPE].size; y++) {
    for (int x = 0; x < shapes[I_SHAPE].size; x++) {
      if (game_field[y][x])
        ck_assert_int_eq(game_field[y][x], 1);
      else
        ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  clear_game_field();
  for (int y = 0; y < HEIGHT + 1; y++) {
    for (int x = 0; x < WIDTH * 2 + 1; x++) {
      ck_assert_int_eq(game_field[y][x], 0);
    }
  }
  remove_game_field();
}
END_TEST

START_TEST(s21_test_clear_game_field5) {
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  // I-SHAPE
  set_shape(1, 1, shapes[I_SHAPE]);
  // MANUAL
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  clear_game_field();
  ck_assert_int_eq(game_field[1][3], 0);
  ck_assert_int_eq(game_field[1][4], 0);
  ck_assert_int_eq(game_field[2][3], 0);
  ck_assert_int_eq(game_field[2][4], 0);
  ck_assert_int_eq(game_field[3][3], 0);
  ck_assert_int_eq(game_field[3][4], 0);
  ck_assert_int_eq(game_field[4][3], 0);
  ck_assert_int_eq(game_field[4][4], 0);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_clear_next_field1) {
  int status_code = clear_next_field();
  ck_assert_int_eq(status_code, ERROR);
}
END_TEST

START_TEST(s21_test_clear_next_field2) {
  init_next_field();
  int status_code = clear_next_field();
  ck_assert_int_eq(status_code, OK);
  remove_next_field();
}
END_TEST

START_TEST(s21_test_move_shape1) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = WIDTH - 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][9], 1);
  ck_assert_int_eq(game_field[1][10], 1);
  ck_assert_int_eq(game_field[1][11], 1);
  ck_assert_int_eq(game_field[1][12], 1);
  ck_assert_int_eq(game_field[2][9], 1);
  ck_assert_int_eq(game_field[2][10], 1);
  ck_assert_int_eq(game_field[2][11], 1);
  ck_assert_int_eq(game_field[2][12], 1);

  clear_game_field();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][11], 1);
  ck_assert_int_eq(game_field[1][12], 1);
  ck_assert_int_eq(game_field[1][13], 1);
  ck_assert_int_eq(game_field[1][14], 1);
  ck_assert_int_eq(game_field[2][11], 1);
  ck_assert_int_eq(game_field[2][12], 1);
  ck_assert_int_eq(game_field[2][13], 1);
  ck_assert_int_eq(game_field[2][14], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape2) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = WIDTH - 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][9], 1);
  ck_assert_int_eq(game_field[1][10], 1);
  ck_assert_int_eq(game_field[1][11], 1);
  ck_assert_int_eq(game_field[1][12], 1);
  ck_assert_int_eq(game_field[2][9], 1);
  ck_assert_int_eq(game_field[2][10], 1);
  ck_assert_int_eq(game_field[2][11], 1);
  ck_assert_int_eq(game_field[2][12], 1);

  clear_game_field();
  move_horizontal(Left);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][7], 1);
  ck_assert_int_eq(game_field[1][8], 1);
  ck_assert_int_eq(game_field[1][9], 1);
  ck_assert_int_eq(game_field[1][10], 1);
  ck_assert_int_eq(game_field[2][7], 1);
  ck_assert_int_eq(game_field[2][8], 1);
  ck_assert_int_eq(game_field[2][9], 1);
  ck_assert_int_eq(game_field[2][10], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape3) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  clear_game_field();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape4) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  move_horizontal(Left);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape5) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = WIDTH * 2 - 2;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][18], 1);
  ck_assert_int_eq(game_field[1][19], 1);
  ck_assert_int_eq(game_field[1][20], 1);
  ck_assert_int_eq(game_field[1][21], 1);
  ck_assert_int_eq(game_field[2][18], 1);
  ck_assert_int_eq(game_field[2][19], 1);
  ck_assert_int_eq(game_field[2][20], 1);
  ck_assert_int_eq(game_field[2][21], 1);

  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][18], 1);
  ck_assert_int_eq(game_field[1][19], 1);
  ck_assert_int_eq(game_field[1][20], 1);
  ck_assert_int_eq(game_field[1][21], 1);
  ck_assert_int_eq(game_field[2][18], 1);
  ck_assert_int_eq(game_field[2][19], 1);
  ck_assert_int_eq(game_field[2][20], 1);
  ck_assert_int_eq(game_field[2][21], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape6) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = WIDTH - 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][9], 1);
  ck_assert_int_eq(game_field[1][10], 1);
  ck_assert_int_eq(game_field[2][9], 1);
  ck_assert_int_eq(game_field[2][10], 1);
  ck_assert_int_eq(game_field[3][9], 1);
  ck_assert_int_eq(game_field[3][10], 1);
  ck_assert_int_eq(game_field[3][11], 1);
  ck_assert_int_eq(game_field[3][12], 1);

  clear_game_field();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][11], 1);
  ck_assert_int_eq(game_field[1][12], 1);
  ck_assert_int_eq(game_field[2][11], 1);
  ck_assert_int_eq(game_field[2][12], 1);
  ck_assert_int_eq(game_field[3][11], 1);
  ck_assert_int_eq(game_field[3][12], 1);
  ck_assert_int_eq(game_field[3][13], 1);
  ck_assert_int_eq(game_field[3][14], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape7) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = WIDTH - 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][9], 1);
  ck_assert_int_eq(game_field[1][10], 1);
  ck_assert_int_eq(game_field[2][9], 1);
  ck_assert_int_eq(game_field[2][10], 1);
  ck_assert_int_eq(game_field[3][9], 1);
  ck_assert_int_eq(game_field[3][10], 1);
  ck_assert_int_eq(game_field[3][11], 1);
  ck_assert_int_eq(game_field[3][12], 1);

  clear_game_field();
  move_horizontal(Left);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][7], 1);
  ck_assert_int_eq(game_field[1][8], 1);
  ck_assert_int_eq(game_field[2][7], 1);
  ck_assert_int_eq(game_field[2][8], 1);
  ck_assert_int_eq(game_field[3][7], 1);
  ck_assert_int_eq(game_field[3][8], 1);
  ck_assert_int_eq(game_field[3][9], 1);
  ck_assert_int_eq(game_field[3][10], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape8) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  clear_game_field();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape9) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  move_horizontal(Left);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape10) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = WIDTH * 2 - 2;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][18], 1);
  ck_assert_int_eq(game_field[1][19], 1);
  ck_assert_int_eq(game_field[2][18], 1);
  ck_assert_int_eq(game_field[2][19], 1);
  ck_assert_int_eq(game_field[3][18], 1);
  ck_assert_int_eq(game_field[3][19], 1);
  ck_assert_int_eq(game_field[3][20], 1);
  ck_assert_int_eq(game_field[3][21], 1);

  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][18], 1);
  ck_assert_int_eq(game_field[1][19], 1);
  ck_assert_int_eq(game_field[2][18], 1);
  ck_assert_int_eq(game_field[2][19], 1);
  ck_assert_int_eq(game_field[3][18], 1);
  ck_assert_int_eq(game_field[3][19], 1);
  ck_assert_int_eq(game_field[3][20], 1);
  ck_assert_int_eq(game_field[3][21], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape11) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = WIDTH - 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][11], 1);
  ck_assert_int_eq(game_field[1][12], 1);
  ck_assert_int_eq(game_field[2][11], 1);
  ck_assert_int_eq(game_field[2][12], 1);
  ck_assert_int_eq(game_field[3][11], 1);
  ck_assert_int_eq(game_field[3][12], 1);
  ck_assert_int_eq(game_field[4][11], 1);
  ck_assert_int_eq(game_field[4][12], 1);

  clear_game_field();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][13], 1);
  ck_assert_int_eq(game_field[1][14], 1);
  ck_assert_int_eq(game_field[2][13], 1);
  ck_assert_int_eq(game_field[2][14], 1);
  ck_assert_int_eq(game_field[3][13], 1);
  ck_assert_int_eq(game_field[3][14], 1);
  ck_assert_int_eq(game_field[4][13], 1);
  ck_assert_int_eq(game_field[4][14], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape12) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = WIDTH - 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][11], 1);
  ck_assert_int_eq(game_field[1][12], 1);
  ck_assert_int_eq(game_field[2][11], 1);
  ck_assert_int_eq(game_field[2][12], 1);
  ck_assert_int_eq(game_field[3][11], 1);
  ck_assert_int_eq(game_field[3][12], 1);
  ck_assert_int_eq(game_field[4][11], 1);
  ck_assert_int_eq(game_field[4][12], 1);

  clear_game_field();
  move_horizontal(Left);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][9], 1);
  ck_assert_int_eq(game_field[1][10], 1);
  ck_assert_int_eq(game_field[2][9], 1);
  ck_assert_int_eq(game_field[2][10], 1);
  ck_assert_int_eq(game_field[3][9], 1);
  ck_assert_int_eq(game_field[3][10], 1);
  ck_assert_int_eq(game_field[4][9], 1);
  ck_assert_int_eq(game_field[4][10], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape13) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  clear_game_field();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);
  ck_assert_int_eq(game_field[4][5], 1);
  ck_assert_int_eq(game_field[4][6], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape14) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  move_horizontal(Left);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape15) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = WIDTH * 2 - 2;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][20], 1);
  ck_assert_int_eq(game_field[1][21], 1);
  ck_assert_int_eq(game_field[2][20], 1);
  ck_assert_int_eq(game_field[2][21], 1);
  ck_assert_int_eq(game_field[3][20], 1);
  ck_assert_int_eq(game_field[3][21], 1);
  ck_assert_int_eq(game_field[4][20], 1);
  ck_assert_int_eq(game_field[4][21], 1);

  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][20], 1);
  ck_assert_int_eq(game_field[1][21], 1);
  ck_assert_int_eq(game_field[2][20], 1);
  ck_assert_int_eq(game_field[2][21], 1);
  ck_assert_int_eq(game_field[3][20], 1);
  ck_assert_int_eq(game_field[3][21], 1);
  ck_assert_int_eq(game_field[4][20], 1);
  ck_assert_int_eq(game_field[4][21], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape16) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = WIDTH * 2 - 2;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][20], 1);
  ck_assert_int_eq(game_field[1][21], 1);
  ck_assert_int_eq(game_field[2][20], 1);
  ck_assert_int_eq(game_field[2][21], 1);
  ck_assert_int_eq(game_field[3][20], 1);
  ck_assert_int_eq(game_field[3][21], 1);
  ck_assert_int_eq(game_field[4][20], 1);
  ck_assert_int_eq(game_field[4][21], 1);

  clear_game_field();
  move_vertical();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  move_horizontal(Right);
  ck_assert_int_eq(game_field[2][20], 1);
  ck_assert_int_eq(game_field[2][21], 1);
  ck_assert_int_eq(game_field[3][20], 1);
  ck_assert_int_eq(game_field[3][21], 1);
  ck_assert_int_eq(game_field[4][20], 1);
  ck_assert_int_eq(game_field[4][21], 1);
  ck_assert_int_eq(game_field[5][20], 1);
  ck_assert_int_eq(game_field[5][21], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_move_shape17) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  clear_game_field();
  move_vertical();
  move_horizontal(Right);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_attaching_shape1) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[19][1], 1);
  ck_assert_int_eq(game_field[19][2], 1);
  ck_assert_int_eq(game_field[19][3], 1);
  ck_assert_int_eq(game_field[19][4], 1);
  ck_assert_int_eq(game_field[20][1], 1);
  ck_assert_int_eq(game_field[20][2], 1);
  ck_assert_int_eq(game_field[20][3], 1);
  ck_assert_int_eq(game_field[20][4], 1);

  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][1], 1);
  ck_assert_int_eq(game_info.field[19][2], 1);
  ck_assert_int_eq(game_info.field[19][3], 1);
  ck_assert_int_eq(game_info.field[19][4], 1);
  ck_assert_int_eq(game_info.field[20][1], 1);
  ck_assert_int_eq(game_info.field[20][2], 1);
  ck_assert_int_eq(game_info.field[20][3], 1);
  ck_assert_int_eq(game_info.field[20][4], 1);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_attaching_shape2) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[19][1], 1);
  ck_assert_int_eq(game_field[19][2], 1);
  ck_assert_int_eq(game_field[19][3], 1);
  ck_assert_int_eq(game_field[19][4], 1);
  ck_assert_int_eq(game_field[20][1], 1);
  ck_assert_int_eq(game_field[20][2], 1);
  ck_assert_int_eq(game_field[20][3], 1);
  ck_assert_int_eq(game_field[20][4], 1);

  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][1], 1);
  ck_assert_int_eq(game_info.field[19][2], 1);
  ck_assert_int_eq(game_info.field[19][3], 1);
  ck_assert_int_eq(game_info.field[19][4], 1);
  ck_assert_int_eq(game_info.field[20][1], 1);
  ck_assert_int_eq(game_info.field[20][2], 1);
  ck_assert_int_eq(game_info.field[20][3], 1);
  ck_assert_int_eq(game_info.field[20][4], 1);

  shape_y = HEIGHT - 3;
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[17][1], 1);
  ck_assert_int_eq(game_field[17][2], 1);
  ck_assert_int_eq(game_field[17][3], 1);
  ck_assert_int_eq(game_field[17][4], 1);
  ck_assert_int_eq(game_field[18][1], 1);
  ck_assert_int_eq(game_field[18][2], 1);
  ck_assert_int_eq(game_field[18][3], 1);
  ck_assert_int_eq(game_field[18][4], 1);

  clear_game_field();
  move_vertical();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[17][1], 1);
  ck_assert_int_eq(game_field[17][2], 1);
  ck_assert_int_eq(game_field[17][3], 1);
  ck_assert_int_eq(game_field[17][4], 1);
  ck_assert_int_eq(game_field[18][1], 1);
  ck_assert_int_eq(game_field[18][2], 1);
  ck_assert_int_eq(game_field[18][3], 1);
  ck_assert_int_eq(game_field[18][4], 1);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape1) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape2) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape3) {
  current_shape = J_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape4) {
  current_shape = S_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape5) {
  current_shape = Z_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape6) {
  current_shape = T_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape7) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[2][7], 1);
  ck_assert_int_eq(game_field[2][8], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert1) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  int status_code = clear_game_field();
  ck_assert_int_eq(status_code, OK);
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert2) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert3) {
  current_shape = J_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert4) {
  current_shape = S_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert5) {
  current_shape = Z_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert6) {
  current_shape = T_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert7) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[2][7], 1);
  ck_assert_int_eq(game_field[2][8], 1);

  rotate_shape_revert(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert8) {
  current_shape = I_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[4][3], 1);
  ck_assert_int_eq(game_field[4][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert9) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  normolize_position_shape_in_right(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert10) {
  current_shape = J_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  normolize_position_shape_in_left(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert11) {
  current_shape = S_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  normolize_position_shape_in_right(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert12) {
  current_shape = Z_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  normolize_position_shape_in_right(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_rotate_shape_revert13) {
  current_shape = T_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  rotate_shape(&shapes[current_shape]);
  normolize_position_shape_in_right(&shapes[current_shape]);
  clear_game_field();
  set_shape(shape_y, shape_y, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_action_processing1) {
  current_shape = SQUARE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  action_processing(true);
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][3], 1);
  ck_assert_int_eq(game_field[2][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_action_processing2) {
  current_shape = L_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);

  action_processing(true);
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][1], 1);
  ck_assert_int_eq(game_field[1][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[1][3], 1);
  ck_assert_int_eq(game_field[1][4], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_action_processing3) {
  current_shape = J_SHAPE;
  shape_y = 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[1][5], 1);
  ck_assert_int_eq(game_field[1][6], 1);
  ck_assert_int_eq(game_field[2][5], 1);
  ck_assert_int_eq(game_field[2][6], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  action_processing(true);
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[2][1], 1);
  ck_assert_int_eq(game_field[2][2], 1);
  ck_assert_int_eq(game_field[3][1], 1);
  ck_assert_int_eq(game_field[3][2], 1);
  ck_assert_int_eq(game_field[3][3], 1);
  ck_assert_int_eq(game_field[3][4], 1);
  ck_assert_int_eq(game_field[3][5], 1);
  ck_assert_int_eq(game_field[3][6], 1);

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_check_compleate_lines1) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  ck_assert_int_eq(game_field[19][1], 1);
  ck_assert_int_eq(game_field[19][2], 1);
  ck_assert_int_eq(game_field[19][3], 1);
  ck_assert_int_eq(game_field[19][4], 1);
  ck_assert_int_eq(game_field[20][1], 1);
  ck_assert_int_eq(game_field[20][2], 1);
  ck_assert_int_eq(game_field[20][3], 1);
  ck_assert_int_eq(game_field[20][4], 1);

  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][1], 1);
  ck_assert_int_eq(game_info.field[19][2], 1);
  ck_assert_int_eq(game_info.field[19][3], 1);
  ck_assert_int_eq(game_info.field[19][4], 1);
  ck_assert_int_eq(game_info.field[20][1], 1);
  ck_assert_int_eq(game_info.field[20][2], 1);
  ck_assert_int_eq(game_info.field[20][3], 1);
  ck_assert_int_eq(game_info.field[20][4], 1);

  shape_x = 5;
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][5], 1);
  ck_assert_int_eq(game_info.field[19][6], 1);
  ck_assert_int_eq(game_info.field[19][7], 1);
  ck_assert_int_eq(game_info.field[19][8], 1);
  ck_assert_int_eq(game_info.field[20][5], 1);
  ck_assert_int_eq(game_info.field[20][6], 1);
  ck_assert_int_eq(game_info.field[20][7], 1);
  ck_assert_int_eq(game_info.field[20][8], 1);

  shape_x = 9;
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][9], 1);
  ck_assert_int_eq(game_info.field[19][10], 1);
  ck_assert_int_eq(game_info.field[19][11], 1);
  ck_assert_int_eq(game_info.field[19][12], 1);
  ck_assert_int_eq(game_info.field[20][9], 1);
  ck_assert_int_eq(game_info.field[20][10], 1);
  ck_assert_int_eq(game_info.field[20][11], 1);
  ck_assert_int_eq(game_info.field[20][12], 1);

  shape_x = 13;
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][13], 1);
  ck_assert_int_eq(game_info.field[19][14], 1);
  ck_assert_int_eq(game_info.field[19][15], 1);
  ck_assert_int_eq(game_info.field[19][16], 1);
  ck_assert_int_eq(game_info.field[20][13], 1);
  ck_assert_int_eq(game_info.field[20][14], 1);
  ck_assert_int_eq(game_info.field[20][15], 1);
  ck_assert_int_eq(game_info.field[20][16], 1);

  shape_x = 17;
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[19][17], 1);
  ck_assert_int_eq(game_info.field[19][18], 1);
  ck_assert_int_eq(game_info.field[19][19], 1);
  ck_assert_int_eq(game_info.field[19][20], 1);
  ck_assert_int_eq(game_info.field[20][17], 1);
  ck_assert_int_eq(game_info.field[20][18], 1);
  ck_assert_int_eq(game_info.field[20][19], 1);
  ck_assert_int_eq(game_info.field[20][20], 1);

  for (int x = 1; x < WIDTH * 2 + 1; x++) {
    ck_assert_int_eq(game_info.field[20][x], 1);
  }
  check_compleate_lines();
  for (int x = 1; x < WIDTH * 2 + 1; x++) {
    ck_assert_int_eq(game_info.field[20][x], 0);
  }

  default_rotation(&shapes[current_shape]);
  remove_game_field();
}
END_TEST

START_TEST(s21_test_check_compleate_lines2) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  ck_assert_int_eq(game_info.field[19][1], 1);
  ck_assert_int_eq(game_info.field[19][2], 1);
  ck_assert_int_eq(game_info.field[19][3], 1);
  ck_assert_int_eq(game_info.field[19][4], 1);
  ck_assert_int_eq(game_info.field[20][1], 1);
  ck_assert_int_eq(game_info.field[20][2], 1);
  ck_assert_int_eq(game_info.field[20][3], 1);
  ck_assert_int_eq(game_info.field[20][4], 1);

  current_shape = L_SHAPE;
  shape_y = HEIGHT - 2;
  shape_x = 5;
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  clear_game_field();
  ck_assert_int_eq(game_info.field[18][5], 1);
  ck_assert_int_eq(game_info.field[18][6], 1);
  ck_assert_int_eq(game_info.field[19][5], 1);
  ck_assert_int_eq(game_info.field[19][6], 1);
  ck_assert_int_eq(game_info.field[20][5], 1);
  ck_assert_int_eq(game_info.field[20][6], 1);
  ck_assert_int_eq(game_info.field[20][7], 1);
  ck_assert_int_eq(game_info.field[20][8], 1);

  current_shape = I_SHAPE;
  shape_y = HEIGHT - 1;
  shape_x = 5;
  clear_game_field();
  rotate_shape(&shapes[current_shape]);
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  ck_assert_int_eq(game_info.field[20][5], 1);
  ck_assert_int_eq(game_info.field[20][6], 1);
  ck_assert_int_eq(game_info.field[20][7], 1);
  ck_assert_int_eq(game_info.field[20][8], 1);
  ck_assert_int_eq(game_info.field[20][9], 1);
  ck_assert_int_eq(game_info.field[20][10], 1);
  ck_assert_int_eq(game_info.field[20][11], 1);
  ck_assert_int_eq(game_info.field[20][12], 1);

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();
  ck_assert_int_eq(game_info.field[20][13], 1);
  ck_assert_int_eq(game_info.field[20][14], 1);
  ck_assert_int_eq(game_info.field[20][15], 1);
  ck_assert_int_eq(game_info.field[20][16], 1);
  ck_assert_int_eq(game_info.field[20][17], 1);
  ck_assert_int_eq(game_info.field[20][18], 1);
  ck_assert_int_eq(game_info.field[20][19], 1);
  ck_assert_int_eq(game_info.field[20][20], 1);

  check_compleate_lines();
  ck_assert_int_eq(game_info.field[20][1], 1);
  ck_assert_int_eq(game_info.field[20][2], 1);
  ck_assert_int_eq(game_info.field[20][3], 1);
  ck_assert_int_eq(game_info.field[20][4], 1);
  ck_assert_int_eq(game_info.field[20][5], 1);
  ck_assert_int_eq(game_info.field[20][6], 1);
  ck_assert_int_eq(game_info.field[20][7], 0);
  ck_assert_int_eq(game_info.field[20][8], 0);
  ck_assert_int_eq(game_info.field[20][9], 0);
  ck_assert_int_eq(game_info.field[20][10], 0);
  ck_assert_int_eq(game_info.field[20][11], 0);
  ck_assert_int_eq(game_info.field[20][12], 0);
  ck_assert_int_eq(game_info.field[20][13], 0);
  ck_assert_int_eq(game_info.field[20][14], 0);
  ck_assert_int_eq(game_info.field[20][15], 0);
  ck_assert_int_eq(game_info.field[20][16], 0);
  ck_assert_int_eq(game_info.field[20][17], 0);
  ck_assert_int_eq(game_info.field[20][18], 0);
  ck_assert_int_eq(game_info.field[20][19], 0);
  ck_assert_int_eq(game_info.field[20][20], 0);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_update_game_score1) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 5;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 9;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  current_shape = L_SHAPE;
  shape_x = 17;
  shape_y = 18;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  for (int x = 1; x < WIDTH * 2 + 1; x++) {
    ck_assert_int_eq(game_info.field[20][x], 1);
  }

  game_score = 0;
  check_compleate_lines();
  ck_assert_int_eq(game_score, 100);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_update_game_score2) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 5;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 9;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 17;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  for (int y = 19; y < HEIGHT + 1; y++) {
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      ck_assert_int_eq(game_info.field[y][x], 1);
    }
  }

  game_score = 0;
  check_compleate_lines();
  ck_assert_int_eq(game_score, 300);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_update_game_score3) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 5;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 9;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 17;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_y = HEIGHT - 3;
  shape_x = 1;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 5;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 9;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  current_shape = L_SHAPE;
  shape_x = 17;
  shape_y = HEIGHT - 4;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  for (int y = 18; y < HEIGHT + 1; y++) {
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      ck_assert_int_eq(game_info.field[y][x], 1);
    }
  }

  game_score = 0;
  check_compleate_lines();
  ck_assert_int_eq(game_score, 700);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_update_game_score4) {
  current_shape = SQUARE;
  shape_y = HEIGHT - 1;
  shape_x = 1;
  init_game_field();
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 5;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 9;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 17;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_y = HEIGHT - 3;
  shape_x = 1;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 5;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 9;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 13;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  shape_x = 17;
  clear_game_field();
  set_shape(shape_y, shape_x, shapes[current_shape]);
  attaching_shape();

  for (int y = 17; y < HEIGHT + 1; y++) {
    for (int x = 1; x < WIDTH * 2 + 1; x++) {
      ck_assert_int_eq(game_info.field[y][x], 1);
    }
  }

  game_score = 0;
  check_compleate_lines();
  ck_assert_int_eq(game_score, 1500);

  remove_game_field();
}
END_TEST

START_TEST(s21_test_update_game_level1) {
  game_score_for_next_level = 0;
  game_level = 1;
  update_game_level();
  ck_assert_int_eq(game_level, 1);
}
END_TEST

START_TEST(s21_test_update_game_level2) {
  game_score_for_next_level += 600;
  update_game_level();
  ck_assert_int_eq(game_level, 2);
}
END_TEST

START_TEST(s21_test_update_game_level3) {
  game_score_for_next_level += 600;
  game_level = 2;
  update_game_level();
  ck_assert_int_eq(game_level, 3);
}
END_TEST

START_TEST(s21_test_update_game_level4) {
  game_score_for_next_level += 600;
  game_level = 3;
  update_game_level();
  ck_assert_int_eq(game_level, 4);
}
END_TEST

START_TEST(s21_test_update_game_level5) {
  game_score_for_next_level += 1200;
  game_level = 4;
  update_game_level();
  ck_assert_int_eq(game_level, 6);
}
END_TEST

START_TEST(s21_test_update_game_level6) {
  game_score_for_next_level += 1200;
  game_level = 6;
  update_game_level();
  ck_assert_int_eq(game_level, 8);
}
END_TEST

START_TEST(s21_test_update_game_level7) {
  game_score_for_next_level = 600;
  game_level = 8;
  update_game_level();
  ck_assert_int_eq(game_level, 9);
}
END_TEST

START_TEST(s21_test_update_game_level8) {
  game_score_for_next_level = 600;
  game_level = 10;
  update_game_level();
  ck_assert_int_eq(game_level, 10);
}
END_TEST

START_TEST(s21_test_update_game_level9) {
  game_level = 9;
  game_score_for_next_level = 1200;
  update_game_level();
  ck_assert_int_eq(game_level, 10);
}
END_TEST

START_TEST(s21_test_update_game_level10) {
  game_level = 10;
  game_score_for_next_level = 1200;
  update_game_level();
  ck_assert_int_eq(game_level, 10);
}
END_TEST

START_TEST(s21_test_update_game_speed1) {
  game_level = 1;
  update_game_speed(true);
  ck_assert_int_eq(game_speed, 0);
  game_speed = 0;
}
END_TEST

START_TEST(s21_test_update_game_speed2) {
  game_level = 1;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 1);
  game_speed = 0;
}

START_TEST(s21_test_update_game_speed3) {
  game_level = 12;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 0);
}

START_TEST(s21_test_update_game_speed4) {
  game_level = 5;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 5);
  game_speed = 0;
}
END_TEST

START_TEST(s21_test_update_game_speed5) {
  game_level = 9;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 9);
  game_speed = 0;
}

START_TEST(s21_test_update_game_speed6) {
  game_level = 10;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 10);
}

START_TEST(s21_test_update_game_speed7) {
  game_level = 2;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 2);
  game_speed = 0;
}
END_TEST

START_TEST(s21_test_update_game_speed8) {
  game_level = 3;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 3);
  game_speed = 0;
}

START_TEST(s21_test_update_game_speed9) {
  game_level = 4;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 4);
}

START_TEST(s21_test_update_game_speed10) {
  game_level = 6;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 6);
  game_speed = 0;
}
END_TEST

START_TEST(s21_test_update_game_speed11) {
  game_level = 7;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 7);
  game_speed = 0;
}

START_TEST(s21_test_update_game_speed12) {
  game_level = 8;
  update_game_speed(false);
  ck_assert_int_eq(game_speed, 8);
}

START_TEST(s21_test_init_game_info1) {
  GameInfo_t *info = NULL;
  int status_code = init_game_info(info);
  ck_assert_int_eq(status_code, ERROR);
}
END_TEST

START_TEST(s21_test_init_game_info2) {
  GameInfo_t info;
  int status_code = init_game_info(&info);
  ck_assert_int_eq(status_code, OK);
}
END_TEST

START_TEST(s21_test_init_game_info3) {
  GameInfo_t info;
  info.level = 2;
  info.pause = 1;
  info.speed = 2;
  info.score = 650;
  int status_code = init_game_info(&info);
  ck_assert_int_eq(info.level, 0);
  ck_assert_int_eq(info.pause, 0);
  ck_assert_int_eq(info.speed, 0);
  ck_assert_int_eq(info.score, 0);
  ck_assert_int_eq(status_code, OK);
}
END_TEST

Suite *s21_tetris_suite(void) {
  Suite *suite;
  TCase *tc_init_game_field, *tc_init_next_field, *tc_clear_game_field1,
      *tc_clear_game_field2, *tc_clear_game_field3, *tc_clear_draw_shape1,
      *tc_clear_draw_shape2, *tc_clear_draw_shape3, *tc_clear_draw_shape4,
      *tc_clear_draw_shape5, *tc_clear_draw_shape6, *tc_clear_draw_shape7,
      *tc_clear_draw_shape8, *tc_clear_draw_shape9, *tc_clear_draw_shape10,
      *tc_clear_draw_shape11, *tc_clear_draw_shape12, *tc_clear_draw_shape13,
      *tc_clear_draw_shape14, *tc_clear_next_field1, *tc_clear_next_field2,
      *tc_clear_game_field4, *tc_clear_game_field5, *tc_move_shape1,
      *tc_move_shape2, *tc_move_shape3, *tc_move_shape4, *tc_move_shape5,
      *tc_move_shape6, *tc_move_shape7, *tc_move_shape8, *tc_move_shape9,
      *tc_move_shape10, *tc_move_shape11, *tc_move_shape12, *tc_move_shape13,
      *tc_move_shape14, *tc_move_shape15, *tc_move_shape16, *tc_move_shape17,
      *tc_attaching_shape1, *tc_attaching_shape2, *tc_rotate_shape1,
      *tc_rotate_shape2, *tc_rotate_shape3, *tc_rotate_shape4,
      *tc_rotate_shape5, *tc_rotate_shape6, *tc_rotate_shape7,
      *tc_rotate_shape_revert1, *tc_rotate_shape_revert2,
      *tc_rotate_shape_revert3, *tc_rotate_shape_revert4,
      *tc_rotate_shape_revert5, *tc_rotate_shape_revert6,
      *tc_rotate_shape_revert7, *tc_rotate_shape_revert8,
      *tc_rotate_shape_revert9, *tc_rotate_shape_revert10,
      *tc_rotate_shape_revert11, *tc_rotate_shape_revert12,
      *tc_rotate_shape_revert13, *tc_action_processing1, *tc_action_processing2,
      *tc_action_processing3, *tc_check_compleate_lines1,
      *tc_check_compleate_lines2, *tc_update_game_score1,
      *tc_update_game_score2, *tc_update_game_score3, *tc_update_game_score4,
      *tc_update_game_level1, *tc_update_game_level2, *tc_update_game_level3,
      *tc_update_game_level4, *tc_update_game_level5, *tc_update_game_level6,
      *tc_update_game_level7, *tc_update_game_level8, *tc_update_game_level9,
      *tc_update_game_level10, *tc_update_game_speed1, *tc_update_game_speed2,
      *tc_update_game_speed3, *tc_update_game_speed4, *tc_update_game_speed5,
      *tc_update_game_speed6, *tc_update_game_speed7, *tc_update_game_speed8,
      *tc_update_game_speed9, *tc_update_game_speed10, *tc_update_game_speed11,
      *tc_update_game_speed12, *tc_test_init_game_info1,
      *tc_test_init_game_info2, *tc_test_init_game_info3;

  suite = suite_create("tetris_suite");

  tc_init_game_field = tcase_create("s21_test_init_game_field");
  tcase_add_test(tc_init_game_field, s21_test_init_game_field);
  suite_add_tcase(suite, tc_init_game_field);

  tc_init_next_field = tcase_create("s21_test_next_field");
  tcase_add_test(tc_init_next_field, s21_test_init_next_field);
  suite_add_tcase(suite, tc_init_next_field);

  tc_clear_game_field1 = tcase_create("s21_test_clear_game_field1");
  tcase_add_test(tc_clear_game_field1, s21_test_clear_game_field1);
  suite_add_tcase(suite, tc_clear_game_field1);

  tc_clear_game_field2 = tcase_create("s21_test_clear_game_field2");
  tcase_add_test(tc_clear_game_field2, s21_test_clear_game_field2);
  suite_add_tcase(suite, tc_clear_game_field2);

  tc_clear_game_field3 = tcase_create("s21_test_clear_game_field3");
  tcase_add_test(tc_clear_game_field3, s21_test_clear_game_field3);
  suite_add_tcase(suite, tc_clear_game_field3);

  tc_clear_draw_shape1 = tcase_create("s21_test_draw_shape1");
  tcase_add_test(tc_clear_draw_shape1, s21_test_draw_shape1);
  suite_add_tcase(suite, tc_clear_draw_shape1);

  tc_clear_draw_shape2 = tcase_create("s21_test_draw_shape2");
  tcase_add_test(tc_clear_draw_shape2, s21_test_draw_shape2);
  suite_add_tcase(suite, tc_clear_draw_shape2);

  tc_clear_draw_shape3 = tcase_create("s21_test_draw_shape3");
  tcase_add_test(tc_clear_draw_shape3, s21_test_draw_shape3);
  suite_add_tcase(suite, tc_clear_draw_shape3);

  tc_clear_draw_shape4 = tcase_create("s21_test_draw_shape4");
  tcase_add_test(tc_clear_draw_shape4, s21_test_draw_shape4);
  suite_add_tcase(suite, tc_clear_draw_shape4);

  tc_clear_draw_shape5 = tcase_create("s21_test_draw_shape5");
  tcase_add_test(tc_clear_draw_shape5, s21_test_draw_shape5);
  suite_add_tcase(suite, tc_clear_draw_shape5);

  tc_clear_draw_shape6 = tcase_create("s21_test_draw_shape6");
  tcase_add_test(tc_clear_draw_shape6, s21_test_draw_shape6);
  suite_add_tcase(suite, tc_clear_draw_shape6);

  tc_clear_draw_shape7 = tcase_create("s21_test_draw_shape7");
  tcase_add_test(tc_clear_draw_shape7, s21_test_draw_shape7);
  suite_add_tcase(suite, tc_clear_draw_shape7);

  tc_clear_draw_shape8 = tcase_create("s21_test_draw_shape8");
  tcase_add_test(tc_clear_draw_shape8, s21_test_draw_shape8);
  suite_add_tcase(suite, tc_clear_draw_shape8);

  tc_clear_draw_shape9 = tcase_create("s21_test_draw_shape9");
  tcase_add_test(tc_clear_draw_shape9, s21_test_draw_shape9);
  suite_add_tcase(suite, tc_clear_draw_shape9);

  tc_clear_draw_shape10 = tcase_create("s21_test_draw_shape10");
  tcase_add_test(tc_clear_draw_shape10, s21_test_draw_shape10);
  suite_add_tcase(suite, tc_clear_draw_shape10);

  tc_clear_draw_shape11 = tcase_create("s21_test_draw_shape11");
  tcase_add_test(tc_clear_draw_shape11, s21_test_draw_shape11);
  suite_add_tcase(suite, tc_clear_draw_shape11);

  tc_clear_draw_shape12 = tcase_create("s21_test_draw_shape12");
  tcase_add_test(tc_clear_draw_shape12, s21_test_draw_shape12);
  suite_add_tcase(suite, tc_clear_draw_shape12);

  tc_clear_draw_shape13 = tcase_create("s21_test_draw_shape13");
  tcase_add_test(tc_clear_draw_shape13, s21_test_draw_shape13);
  suite_add_tcase(suite, tc_clear_draw_shape13);

  tc_clear_draw_shape14 = tcase_create("s21_test_draw_shape14");
  tcase_add_test(tc_clear_draw_shape14, s21_test_draw_shape14);
  suite_add_tcase(suite, tc_clear_draw_shape14);

  tc_clear_next_field1 = tcase_create("s21_test_clear_next_field1");
  tcase_add_test(tc_clear_next_field1, s21_test_clear_next_field1);
  suite_add_tcase(suite, tc_clear_next_field1);

  tc_clear_next_field2 = tcase_create("s21_test_clear_next_field2");
  tcase_add_test(tc_clear_next_field2, s21_test_clear_next_field2);
  suite_add_tcase(suite, tc_clear_next_field2);

  tc_clear_game_field4 = tcase_create("s21_test_clear_game_field4");
  tcase_add_test(tc_clear_game_field4, s21_test_clear_game_field4);
  suite_add_tcase(suite, tc_clear_game_field4);

  tc_clear_game_field5 = tcase_create("s21_test_clear_game_field5");
  tcase_add_test(tc_clear_game_field5, s21_test_clear_game_field5);
  suite_add_tcase(suite, tc_clear_game_field5);

  tc_move_shape1 = tcase_create("s21_test_move_shape1");
  tcase_add_test(tc_move_shape1, s21_test_move_shape1);
  suite_add_tcase(suite, tc_move_shape1);

  tc_move_shape2 = tcase_create("s21_test_move_shape2");
  tcase_add_test(tc_move_shape2, s21_test_move_shape2);
  suite_add_tcase(suite, tc_move_shape2);

  tc_move_shape3 = tcase_create("s21_test_move_shape3");
  tcase_add_test(tc_move_shape3, s21_test_move_shape3);
  suite_add_tcase(suite, tc_move_shape3);

  tc_move_shape4 = tcase_create("s21_test_move_shape4");
  tcase_add_test(tc_move_shape4, s21_test_move_shape4);
  suite_add_tcase(suite, tc_move_shape4);

  tc_move_shape5 = tcase_create("s21_test_move_shape5");
  tcase_add_test(tc_move_shape5, s21_test_move_shape5);
  suite_add_tcase(suite, tc_move_shape5);

  tc_move_shape6 = tcase_create("s21_test_move_shape6");
  tcase_add_test(tc_move_shape6, s21_test_move_shape6);
  suite_add_tcase(suite, tc_move_shape6);

  tc_move_shape7 = tcase_create("s21_test_move_shape7");
  tcase_add_test(tc_move_shape7, s21_test_move_shape7);
  suite_add_tcase(suite, tc_move_shape7);

  tc_move_shape8 = tcase_create("s21_test_move_shape8");
  tcase_add_test(tc_move_shape8, s21_test_move_shape8);
  suite_add_tcase(suite, tc_move_shape8);

  tc_move_shape9 = tcase_create("s21_test_move_shape9");
  tcase_add_test(tc_move_shape9, s21_test_move_shape9);
  suite_add_tcase(suite, tc_move_shape9);

  tc_move_shape10 = tcase_create("s21_test_move_shape10");
  tcase_add_test(tc_move_shape10, s21_test_move_shape10);
  suite_add_tcase(suite, tc_move_shape10);

  tc_move_shape11 = tcase_create("s21_test_move_shape11");
  tcase_add_test(tc_move_shape11, s21_test_move_shape11);
  suite_add_tcase(suite, tc_move_shape11);

  tc_move_shape12 = tcase_create("s21_test_move_shape12");
  tcase_add_test(tc_move_shape12, s21_test_move_shape12);
  suite_add_tcase(suite, tc_move_shape12);

  tc_move_shape13 = tcase_create("s21_test_move_shape13");
  tcase_add_test(tc_move_shape13, s21_test_move_shape13);
  suite_add_tcase(suite, tc_move_shape13);

  tc_move_shape14 = tcase_create("s21_test_move_shape14");
  tcase_add_test(tc_move_shape14, s21_test_move_shape14);
  suite_add_tcase(suite, tc_move_shape14);

  tc_move_shape15 = tcase_create("s21_test_move_shape15");
  tcase_add_test(tc_move_shape15, s21_test_move_shape15);
  suite_add_tcase(suite, tc_move_shape15);

  tc_move_shape16 = tcase_create("s21_test_move_shape16");
  tcase_add_test(tc_move_shape16, s21_test_move_shape16);
  suite_add_tcase(suite, tc_move_shape16);

  tc_move_shape17 = tcase_create("s21_test_move_shape17");
  tcase_add_test(tc_move_shape17, s21_test_move_shape17);
  suite_add_tcase(suite, tc_move_shape17);

  tc_attaching_shape1 = tcase_create("s21_test_attaching_shape1");
  tcase_add_test(tc_attaching_shape1, s21_test_attaching_shape1);
  suite_add_tcase(suite, tc_attaching_shape1);

  tc_attaching_shape2 = tcase_create("s21_test_attaching_shape2");
  tcase_add_test(tc_attaching_shape2, s21_test_attaching_shape2);
  suite_add_tcase(suite, tc_attaching_shape2);

  tc_rotate_shape1 = tcase_create("s21_test_rotate_shape1");
  tcase_add_test(tc_rotate_shape1, s21_test_rotate_shape1);
  suite_add_tcase(suite, tc_rotate_shape1);

  tc_rotate_shape2 = tcase_create("s21_test_rotate_shape2");
  tcase_add_test(tc_rotate_shape2, s21_test_rotate_shape2);
  suite_add_tcase(suite, tc_rotate_shape2);

  tc_rotate_shape3 = tcase_create("s21_test_rotate_shape3");
  tcase_add_test(tc_rotate_shape3, s21_test_rotate_shape3);
  suite_add_tcase(suite, tc_rotate_shape3);

  tc_rotate_shape4 = tcase_create("s21_test_rotate_shape4");
  tcase_add_test(tc_rotate_shape4, s21_test_rotate_shape4);
  suite_add_tcase(suite, tc_rotate_shape4);

  tc_rotate_shape5 = tcase_create("s21_test_rotate_shape5");
  tcase_add_test(tc_rotate_shape5, s21_test_rotate_shape5);
  suite_add_tcase(suite, tc_rotate_shape5);

  tc_rotate_shape6 = tcase_create("s21_test_rotate_shape6");
  tcase_add_test(tc_rotate_shape6, s21_test_rotate_shape6);
  suite_add_tcase(suite, tc_rotate_shape6);

  tc_rotate_shape7 = tcase_create("s21_test_rotate_shape7");
  tcase_add_test(tc_rotate_shape7, s21_test_rotate_shape7);
  suite_add_tcase(suite, tc_rotate_shape7);

  tc_rotate_shape_revert1 = tcase_create("s21_test_rotate_shape_revert1");
  tcase_add_test(tc_rotate_shape_revert1, s21_test_rotate_shape_revert1);
  suite_add_tcase(suite, tc_rotate_shape_revert1);

  tc_rotate_shape_revert2 = tcase_create("s21_test_rotate_shape_revert2");
  tcase_add_test(tc_rotate_shape_revert2, s21_test_rotate_shape_revert2);
  suite_add_tcase(suite, tc_rotate_shape_revert2);

  tc_rotate_shape_revert3 = tcase_create("s21_test_rotate_shape_revert3");
  tcase_add_test(tc_rotate_shape_revert3, s21_test_rotate_shape_revert3);
  suite_add_tcase(suite, tc_rotate_shape_revert3);

  tc_rotate_shape_revert4 = tcase_create("s21_test_rotate_shape_revert4");
  tcase_add_test(tc_rotate_shape_revert4, s21_test_rotate_shape_revert4);
  suite_add_tcase(suite, tc_rotate_shape_revert4);

  tc_rotate_shape_revert5 = tcase_create("s21_test_rotate_shape_revert5");
  tcase_add_test(tc_rotate_shape_revert5, s21_test_rotate_shape_revert5);
  suite_add_tcase(suite, tc_rotate_shape_revert5);

  tc_rotate_shape_revert6 = tcase_create("s21_test_rotate_shape_revert6");
  tcase_add_test(tc_rotate_shape_revert6, s21_test_rotate_shape_revert6);
  suite_add_tcase(suite, tc_rotate_shape_revert6);

  tc_rotate_shape_revert7 = tcase_create("s21_test_rotate_shape_revert7");
  tcase_add_test(tc_rotate_shape_revert7, s21_test_rotate_shape_revert7);
  suite_add_tcase(suite, tc_rotate_shape_revert7);

  tc_rotate_shape_revert8 = tcase_create("s21_test_rotate_shape_revert8");
  tcase_add_test(tc_rotate_shape_revert8, s21_test_rotate_shape_revert8);
  suite_add_tcase(suite, tc_rotate_shape_revert8);

  tc_rotate_shape_revert9 = tcase_create("s21_test_rotate_shape_revert9");
  tcase_add_test(tc_rotate_shape_revert9, s21_test_rotate_shape_revert9);
  suite_add_tcase(suite, tc_rotate_shape_revert9);

  tc_rotate_shape_revert10 = tcase_create("s21_test_rotate_shape_revert10");
  tcase_add_test(tc_rotate_shape_revert10, s21_test_rotate_shape_revert10);
  suite_add_tcase(suite, tc_rotate_shape_revert10);

  tc_rotate_shape_revert11 = tcase_create("s21_test_rotate_shape_revert11");
  tcase_add_test(tc_rotate_shape_revert11, s21_test_rotate_shape_revert11);
  suite_add_tcase(suite, tc_rotate_shape_revert11);

  tc_rotate_shape_revert12 = tcase_create("s21_test_rotate_shape_revert12");
  tcase_add_test(tc_rotate_shape_revert12, s21_test_rotate_shape_revert12);
  suite_add_tcase(suite, tc_rotate_shape_revert12);

  tc_rotate_shape_revert13 = tcase_create("s21_test_rotate_shape_revert13");
  tcase_add_test(tc_rotate_shape_revert13, s21_test_rotate_shape_revert13);
  suite_add_tcase(suite, tc_rotate_shape_revert13);

  tc_action_processing1 = tcase_create("s21_test_action_processing1");
  tcase_add_test(tc_action_processing1, s21_test_action_processing1);
  suite_add_tcase(suite, tc_action_processing1);

  tc_action_processing2 = tcase_create("s21_test_action_processing2");
  tcase_add_test(tc_action_processing2, s21_test_action_processing2);
  suite_add_tcase(suite, tc_action_processing2);

  tc_action_processing3 = tcase_create("s21_test_action_processing3");
  tcase_add_test(tc_action_processing3, s21_test_action_processing3);
  suite_add_tcase(suite, tc_action_processing3);

  tc_check_compleate_lines1 = tcase_create("s21_test_check_compleate_lines1");
  tcase_add_test(tc_check_compleate_lines1, s21_test_check_compleate_lines1);
  suite_add_tcase(suite, tc_check_compleate_lines1);

  tc_check_compleate_lines2 = tcase_create("s21_test_check_compleate_lines2");
  tcase_add_test(tc_check_compleate_lines2, s21_test_check_compleate_lines2);
  suite_add_tcase(suite, tc_check_compleate_lines2);

  tc_update_game_score1 = tcase_create("s21_test_update_game_score1");
  tcase_add_test(tc_update_game_score1, s21_test_update_game_score1);
  suite_add_tcase(suite, tc_update_game_score1);

  tc_update_game_score2 = tcase_create("s21_test_update_game_score2");
  tcase_add_test(tc_update_game_score2, s21_test_update_game_score2);
  suite_add_tcase(suite, tc_update_game_score2);

  tc_update_game_score3 = tcase_create("s21_test_update_game_score3");
  tcase_add_test(tc_update_game_score3, s21_test_update_game_score3);
  suite_add_tcase(suite, tc_update_game_score3);

  tc_update_game_score4 = tcase_create("s21_test_update_game_score4");
  tcase_add_test(tc_update_game_score4, s21_test_update_game_score4);
  suite_add_tcase(suite, tc_update_game_score4);

  tc_update_game_level1 = tcase_create("s21_test_update_game_level1");
  tcase_add_test(tc_update_game_level1, s21_test_update_game_level1);
  suite_add_tcase(suite, tc_update_game_level1);

  tc_update_game_level2 = tcase_create("s21_test_update_game_level2");
  tcase_add_test(tc_update_game_level2, s21_test_update_game_level2);
  suite_add_tcase(suite, tc_update_game_level2);

  tc_update_game_level3 = tcase_create("s21_test_update_game_level3");
  tcase_add_test(tc_update_game_level3, s21_test_update_game_level3);
  suite_add_tcase(suite, tc_update_game_level3);

  tc_update_game_level4 = tcase_create("s21_test_update_game_level4");
  tcase_add_test(tc_update_game_level4, s21_test_update_game_level4);
  suite_add_tcase(suite, tc_update_game_level4);

  tc_update_game_level5 = tcase_create("s21_test_update_game_level5");
  tcase_add_test(tc_update_game_level5, s21_test_update_game_level5);
  suite_add_tcase(suite, tc_update_game_level5);

  tc_update_game_level6 = tcase_create("s21_test_update_game_level6");
  tcase_add_test(tc_update_game_level6, s21_test_update_game_level6);
  suite_add_tcase(suite, tc_update_game_level6);

  tc_update_game_level7 = tcase_create("s21_test_update_game_level7");
  tcase_add_test(tc_update_game_level7, s21_test_update_game_level7);
  suite_add_tcase(suite, tc_update_game_level7);

  tc_update_game_level8 = tcase_create("s21_test_update_game_level8");
  tcase_add_test(tc_update_game_level8, s21_test_update_game_level8);
  suite_add_tcase(suite, tc_update_game_level8);

  tc_update_game_level9 = tcase_create("s21_test_update_game_level9");
  tcase_add_test(tc_update_game_level9, s21_test_update_game_level9);
  suite_add_tcase(suite, tc_update_game_level9);

  tc_update_game_level10 = tcase_create("s21_test_update_game_level10");
  tcase_add_test(tc_update_game_level10, s21_test_update_game_level10);
  suite_add_tcase(suite, tc_update_game_level10);

  tc_update_game_speed1 = tcase_create("s21_test_update_game_speed1");
  tcase_add_test(tc_update_game_speed1, s21_test_update_game_speed1);
  suite_add_tcase(suite, tc_update_game_speed1);

  tc_update_game_speed2 = tcase_create("s21_test_update_game_speed2");
  tcase_add_test(tc_update_game_speed2, s21_test_update_game_speed2);
  suite_add_tcase(suite, tc_update_game_speed2);

  tc_update_game_speed3 = tcase_create("s21_test_update_game_speed3");
  tcase_add_test(tc_update_game_speed3, s21_test_update_game_speed3);
  suite_add_tcase(suite, tc_update_game_speed3);

  tc_update_game_speed4 = tcase_create("s21_test_update_game_speed4");
  tcase_add_test(tc_update_game_speed4, s21_test_update_game_speed4);
  suite_add_tcase(suite, tc_update_game_speed4);

  tc_update_game_speed5 = tcase_create("s21_test_update_game_speed5");
  tcase_add_test(tc_update_game_speed5, s21_test_update_game_speed5);
  suite_add_tcase(suite, tc_update_game_speed5);

  tc_update_game_speed6 = tcase_create("s21_test_update_game_speed6");
  tcase_add_test(tc_update_game_speed6, s21_test_update_game_speed6);
  suite_add_tcase(suite, tc_update_game_speed6);

  tc_update_game_speed7 = tcase_create("s21_test_update_game_speed7");
  tcase_add_test(tc_update_game_speed7, s21_test_update_game_speed7);
  suite_add_tcase(suite, tc_update_game_speed7);

  tc_update_game_speed8 = tcase_create("s21_test_update_game_speed8");
  tcase_add_test(tc_update_game_speed8, s21_test_update_game_speed8);
  suite_add_tcase(suite, tc_update_game_speed8);

  tc_update_game_speed9 = tcase_create("s21_test_update_game_speed9");
  tcase_add_test(tc_update_game_speed9, s21_test_update_game_speed9);
  suite_add_tcase(suite, tc_update_game_speed9);

  tc_update_game_speed10 = tcase_create("s21_test_update_game_speed10");
  tcase_add_test(tc_update_game_speed10, s21_test_update_game_speed10);
  suite_add_tcase(suite, tc_update_game_speed10);

  tc_update_game_speed11 = tcase_create("s21_test_update_game_speed11");
  tcase_add_test(tc_update_game_speed11, s21_test_update_game_speed11);
  suite_add_tcase(suite, tc_update_game_speed11);

  tc_update_game_speed12 = tcase_create("s21_test_update_game_speed12");
  tcase_add_test(tc_update_game_speed12, s21_test_update_game_speed12);
  suite_add_tcase(suite, tc_update_game_speed12);

  tc_test_init_game_info1 = tcase_create("s21_test_init_game_info1");
  tcase_add_test(tc_test_init_game_info1, s21_test_init_game_info1);
  suite_add_tcase(suite, tc_test_init_game_info1);

  tc_test_init_game_info2 = tcase_create("s21_test_init_game_info2");
  tcase_add_test(tc_test_init_game_info2, s21_test_init_game_info2);
  suite_add_tcase(suite, tc_test_init_game_info2);

  tc_test_init_game_info3 = tcase_create("s21_test_init_game_info3");
  tcase_add_test(tc_test_init_game_info3, s21_test_init_game_info3);
  suite_add_tcase(suite, tc_test_init_game_info3);

  return suite;
}

void test_fail(Suite *s, int *fail) {
  SRunner *runner = srunner_create(s);
  srunner_run_all(runner, CK_NORMAL);
  *fail = srunner_ntests_failed(runner);
  srunner_free(runner);
}

int main() {
  int fail = 0;
  test_fail(s21_tetris_suite(), &fail);
  return 0;
}