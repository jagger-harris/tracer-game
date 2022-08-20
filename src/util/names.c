#include "names.h"

NameArray names_get(const char *file_path) {
  FILE *fp;
  NameArray name_array;
  size_t total_strings = 128;
  size_t num_of_names;
  char line[MAX_NAME_LENGTH];
  char name[MAX_NAME_LENGTH];
  char **names;
  
  names = calloc(total_strings, sizeof(char*));
  fp = fopen(file_path, "r");
  
  if (!names) {
    fprintf(stderr, "Out of memory!\n");
    exit(1);
  }

  if (!fp) {
    fprintf(stderr, "Cannot open %s!\n", file_path);
    exit(2);
  }

  num_of_names = 0;
  while (fgets(line, sizeof(line) - 1, fp)) {
    if (num_of_names >= total_strings) {
      total_strings *= 2;
      names = realloc(names, sizeof(*name) * total_strings);
    }

    names[num_of_names] = malloc(MAX_NAME_LENGTH + 1);
    name[0] = '\0';

    sscanf(line, " %s", name);
    strcpy(names[num_of_names], name);
    num_of_names++;
  }

  fclose(fp);

  name_array.names = names;
  name_array.size = num_of_names;

  return name_array;
}

void names_destroy(char **names) {
  size_t i = 0;

  while (names[i]) {
    free(names[i]);
    i++;
  }

  free(names);
}
