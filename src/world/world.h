#ifndef WORLD_H
#define WORLD_H

#include "company.h"
#include "person.h"
#include "network.h"

#include <stdint.h>

typedef struct {
  uint64_t seed;
  Company **companies;
  Person **people;
  Network **networks;
} World;

World *create_world();
World *create_world_with_seed(uint64_t seed);
World *load_world();
void *save_world(World *world);

#endif /* WORLD_H */
