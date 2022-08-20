#include "computer/computer.h"
#include "world/company.h"
#include "util/util.h"
#include "world/company.h"

#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {
  uint64_t seed = 777;
  Random random = random_seed(seed);
  Computer *computer = computer_create(&random);
  Company company;
  uint32_t i;

  for (i = 0; i < 100; i++) {
    company = company_generate(&random);
    company.prefix_name[0] = toupper(company.prefix_name[0]);
    company.suffix_name[0] = toupper(company.suffix_name[0]);
    printf("%s %s\n", company.prefix_name, company.suffix_name);
  }

  computer_destroy(computer);

  return 0;
}
