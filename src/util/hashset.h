#ifndef HASHSET_H
#define HASHSET_H

#include <stdlib.h>

#define START_BUCKETS 16

typedef struct {

} Hashset;

Hashset *hashset_create();
void hashset_destroy();

#endif /* HASHSET_H */
