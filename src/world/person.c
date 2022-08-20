#include "person.h"
#include "../util/names.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tm *random_date(Random *random) {
  uint32_t random_seconds = random_uint64_t(random) % MAX_SECONDS;
  int seconds = (int32_t)TWENTY_TWENTY_TWO - (int32_t)(MIN_SECONDS
                                                        + random_seconds);
  time_t random_time = (time_t)seconds;

  return localtime(&random_time);
}

Person person_generate(Random *random) {
  Person person;
  NameArray first_names;
  NameArray last_names;

  first_names = names_get("data/assets/names/first_names.txt");
  last_names = names_get("data/assets/names/last_names.txt");

  strcpy(person.first_name, first_names.names[random_uint64_t(random)
                                              % first_names.size]);
  strcpy(person.last_name, last_names.names[random_uint64_t(random)
                                              % last_names.size]);
  person.middle_initial = 'A' + (random_uint64_t(random) % NUM_OF_LETTERS);
  person.age = random_date(random);

  names_destroy(first_names.names);
  names_destroy(last_names.names);

  return person;
}
