#ifndef HARDWARE_H
#define HARDWARE_H

#include "../util/util.h"
#include "../util/names.h"
#include "mac.h"

#include <stdlib.h>

typedef struct {
  char name[MAX_NAME_LENGTH];
  size_t num_of_cores;
  float clock;
} CPU;

typedef struct {
  char name[MAX_NAME_LENGTH];
  size_t amount;
  float clock;
} RAM;

typedef struct {
  char name[MAX_NAME_LENGTH];
  size_t ram_slots;
} MB;

typedef struct {
  char name[MAX_NAME_LENGTH];
  float size;
} HDD;

typedef struct {
  char name[MAX_NAME_LENGTH];
} NIC;

CPU cpu_generate(Random *random);
RAM ram_generate(Random *random);
MB mb_generate(Random *random);
HDD hdd_generate(Random *random);
NIC nic_generate(Random *random);

#endif /* HARDWARE_H */
