#include "world/organization.h"
#include "util/util.h"
#include "world/organization.h"

#include <stdio.h>
#include <ctype.h>

int main(int argc, char **argv) {
  uint64_t seed = 777;
  Random random = random_seed(seed);
  Organization organization;
  uint32_t i;

  for (i = 0; i < 100; i++) {
    organization = organization_generate(bank, &random);
    organization.prefix_name[0] = toupper(organization.prefix_name[0]);
    organization.suffix_name[0] = toupper(organization.suffix_name[0]);
    printf("%s %s\n", organization.prefix_name, organization.suffix_name);
  }

  return 0;
}
