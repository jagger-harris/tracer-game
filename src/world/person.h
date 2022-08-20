#ifndef PERSON_H
#define PERSON_H

#include "../util/util.h"
#include "../util/names.h"

#include <stdint.h>
#include <time.h>

#define MIN_SECONDS (18 * 365 * 24 * 60 * 60)
#define MAX_SECONDS (60 * 365 * 24 * 60 * 60)
#define TWENTY_TWENTY_TWO 1641020400
#define NUM_OF_LETTERS 26

typedef struct {
  char first_name[MAX_NAME_LENGTH];
  char last_name[MAX_NAME_LENGTH];
  char middle_initial;
  struct tm *age;
} Person;

struct tm *random_date(Random *random);
Person person_generate(Random *random);

#endif /* PERSON_H */
