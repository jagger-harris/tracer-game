#include "file.h"

#include <stdio.h>
#include <string.h>

#define ARRAY_LENGTH 4

File *file_create(char *name, bool is_directory) {
  File *file;
  File_Data *data;
  void **children;
  size_t *allocated_children;
  size_t *num_of_children;

  file = malloc(sizeof(*file));
  data = malloc(sizeof(*data));
  children = malloc(sizeof(File) * ARRAY_LENGTH);

  if (data) {
    strncpy(data->name, name, MAX_NAME_SIZE);
    data->name[MAX_NAME_SIZE - 1] = '\0';
    data->is_directory = is_directory;
  }

  if (file) {
    file->data = data;

    if (children) {
      file->children = children;
    }

    file->allocated_children = ARRAY_LENGTH;
    file->num_of_children = 0;
  }

  return file;
}

void file_destroy(File *file) {
  size_t i;

  if (file) {
    if (file->num_of_children) {
      for (i = 0; i < file->num_of_children; i++) {
        file_destroy(file->children[i]);
      }
    }

    free(file->data);
    free((File*)file->children);
    free(file);
  }
}

File* find(File *parent, const char *file_name) {
  File* found_file;
  size_t i;

  for (i = 0; i < parent->num_of_children; i++) {
    size_t next_num = i;
    File* file = parent->children[i];

    if (!strcmp(((File*)parent->children[i])->data->name, file_name)) {
      return parent->children[i];
    }
  }

  return NULL;
}

void push(File *parent, File *file) {
  if (parent->num_of_children == parent->allocated_children) {
    parent->allocated_children *= 2;
    parent->children = realloc(parent->children, sizeof(File) * parent->allocated_children);
  }
  
  parent->children[parent->num_of_children] = file;
  parent->num_of_children++;
}

void pop(File *parent, const char *file_name) {
  File* found_file;
  size_t i;
  bool found = 0;

  for (i = 0; i < parent->num_of_children; i++) {
    size_t next_num = i;
    File* file = parent->children[i];

    if (!strcmp(((File*)parent->children[i])->data->name, file_name)) {
      found_file = parent->children[i];
      found = 1;
    }

    if (found) {
      next_num++;
      parent->children[i] = parent->children[next_num];
    }
  }

  if (found) {
    parent->num_of_children--;
    file_destroy(found_file);
  }
}


void file_print(File *file) {
  size_t i;

  if (file) {
    if (file->num_of_children) {
      for (i = 0; i < file->num_of_children; i++) {
        file_print(file->children[i]);
      }
    }

    printf("%s\n", file->data->name);
  }
}
