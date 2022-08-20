#include "computer.h"

#include <stdio.h>

Computer *computer_create(Random *random) {
  Computer *computer;
  
  computer = malloc(sizeof(*computer));
  
  if (computer) {
    computer->files = generate_default_unix_files(computer, random);
    computer->ip = ip_generate(random);
  }

  return computer;
}

void computer_destroy(Computer *computer) {
  if (computer) {
    if (computer->files) {
      file_destroy(computer->files);
    }

    free(computer);
  }
}

File *generate_default_unix_files(Computer *computer, Random *random) {
  char *default_file_names[] = {"bin", "boot", "dev", "etc", "home", "lib",
                                "media", "mnt", "opt", "proc", "root", "run",
                                "sbin", "srv", "sys", "tmp", "usr", "var"};
  File *unix_root = file_create("/", 1);
  uint32_t i;

  for(i = 0; i < sizeof(default_file_names) / sizeof(char*); i++) {
    File *new_file = file_create(default_file_names[i], 1);
    push(unix_root, new_file);
  }

  generate_random_home_dirs(computer, random);

  return unix_root;
}

void generate_random_home_dirs(Computer *computer, Random *random) {
  
}
