#ifndef NAMES_H
#define NAMES_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 32

typedef struct {
  size_t size;
  char **names;
} NameArray;

NameArray names_get(const char *file_path);
void names_destroy(char **names);

#endif /* NAMES_H */
