#include "random.h"

#include <stdlib.h>
#include <sys/time.h>

Random random_seed(uint64_t seed) {
  Random random;

  random.state = seed;

  return random;
}

Random random_random() {
  struct timeval tv;
  
  gettimeofday(&tv, NULL);

  return random_seed((uint64_t)tv.tv_usec);
}

void xorshift64star_next_state(Random* random) {
  random->state ^= random->state >> 12;
  random->state ^= random->state << 25;
  random->state ^= random->state >> 27;
}

uint64_t random_uint64_t(Random* random) {
  xorshift64star_next_state(random);

  return random->state * UINT64_C(2685821657736338717);
}
