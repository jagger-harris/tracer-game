#ifndef RANDOM_H
#define RANDOM_H

#include <stdint.h>

typedef struct {
  uint64_t state;
} Random;

Random random_seed(uint64_t seed);

Random random_random();

void xorshift64star_next_state(Random *random);

uint64_t random_uint64_t(Random *random);


#endif /* RANDOM_H */
