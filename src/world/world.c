#include "world.h"
#include "../util/util.h"

World *create_world() {
  World *world;
  Random random;
  uint64_t seed;

  random = random_random();
  seed = random_uint64_t(&random);
  world = create_world_with_seed(seed);

  return world;
}

World *create_world_with_seed(uint64_t seed) {
  World *world;

  world->seed = seed;

  return world;
}

World *load_world() {
  World *world;

  return world;
}

void *save_world(World *world) {

}
