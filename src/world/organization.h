#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "../util/names.h"
#include "person.h"

typedef enum {
  technology,
  bank
} Type;

typedef struct {
  Type type;
  char prefix_name[MAX_NAME_LENGTH];
  char suffix_name[MAX_NAME_LENGTH];
  float worth;
  float value;
  Person *CEO;
  Person *CFO;
  Person *CTO;
  Person *CIO;
  Person **Employees;
} Organization;

Organization organization_generate(Type type, Random *random);

#endif /* ORGANIZATION_H */
