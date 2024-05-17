#include "../../tetris.h"

int write_buffer_from_file(char *buffer, FILE *file, int *index);
void write_high_score_from_buffer(char *find_eq, char *buffer);

void file_read() {
  FILE *file = fopen(FILE_NAME, MODES_READ);
  if (file != NULL) {
    char *buffer = (char *)calloc(256, sizeof(char));
    if (buffer != NULL) {
      int index = 0;
      int status = write_buffer_from_file(buffer, file, &index);
      if (status == OK && index > 0) {
        char *find_eq = strchr(buffer, '=');
        write_high_score_from_buffer(find_eq, buffer);
      } else {
        fprintf(stderr, SCORE_NULL_MESSAGE);
      }
      free(buffer);
    } else {
      fclose(file);
      fprintf(stderr, MEMORY_ALLOCATING_MESSAGE);
    }
  } else {
    fprintf(stderr, FILE_OPEN_MESSAGE);
  }
}

int write_buffer_from_file(char *buffer, FILE *file, int *index) {
  int code_result = OK;
  if (buffer && file && index) {
    int ch;
    while ((ch = fgetc(file)) != EOF && *index < 255) {
      if (!isspace(ch)) {
        buffer[(*index)++] = ch;
      }
    }
    buffer[*index] = '\0';
    fclose(file);
  } else {
    code_result = ERROR;
  }
  return code_result;
}

void write_high_score_from_buffer(char *find_eq, char *buffer) {
  if (find_eq && buffer) {
    char *endptr;
    long num = strtol(++find_eq, &endptr, 10);
    if (num > 0 && *endptr == '\0') {
      game_high_score = num;
    }
  } else {
    char *endptr;
    long num = strtol(buffer, &endptr, 10);
    if (num > 0 && *endptr == '\0') {
      game_high_score = num;
    }
  }
}
