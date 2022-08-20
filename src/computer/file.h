#ifndef FILE_H
#define FILE_H

#define MAX_NAME_SIZE 256

#include "../util/util.h"

#include <stdlib.h>

typedef struct {
  char name[MAX_NAME_SIZE];
  bool is_directory;
} File_Data;

typedef struct {
  File_Data *data;
  void **children;
  size_t allocated_children;
  size_t num_of_children;
} File;

File *file_create(char *name, bool is_directory);
void file_destroy(File *file);
File *find(File *parent, const char *file_name);
void push(File *parent, File *file);
void pop(File *parent, const char *file_name);
void file_print(File *file);

#endif /* FILE_H */
