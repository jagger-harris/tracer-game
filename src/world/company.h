#ifndef COMPANY_H
#define COMPANY_H

#include "../util/names.h"
#include "person.h"

typedef struct {
  char prefix_name[MAX_NAME_LENGTH];
  char suffix_name[MAX_NAME_LENGTH];
  float worth;
  float value;
  Person *CEO;
  Person *CFO;
  Person *CTO;
  Person *CIO;
  Person **Employees;
} Company;

Company company_generate(Random *random);

#endif /* COMPANY_H */
