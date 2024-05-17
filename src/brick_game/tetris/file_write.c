#include "../../tetris.h"

void file_write() {
  if (game_score >= game_high_score) {
    char text[256];
    sprintf(text, "high score = %d", game_score);

    FILE *file = fopen(FILE_NAME, MODES_WRITE);
    if (file != NULL) {
      if (fprintf(file, "%s", text) >= 0) {
        fprintf(stderr, WRITE_SUCCES_MESSAGE);
      } else {
        fprintf(stderr, WRITE_FIALED_MESSAGE);
      }
      fclose(file);
    } else {
      fprintf(stderr, FILE_OPEN_MESSAGE);
    }
  }
}
