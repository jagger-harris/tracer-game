#ifndef COMPUTER_H
#define COMPUTER_H

#include "file.h"
#include "ip.h"
#include "../util/util.h"

typedef struct {
  File *files;
  IP ip;
} Computer;

Computer *computer_create(Random *random);
void computer_destroy(Computer *computer);
File *generate_default_unix_files(Computer *computer, Random *random);
void generate_random_home_dirs(Computer *computer, Random *random);

#endif /* COMPUTER_H */
