#include "company.h"
#include "../util/names.h"

Company company_generate(Random *random) {
  Company company;
  NameArray prefix_names;
  NameArray suffix_names;

  prefix_names = names_get("data/assets/names/tech_business_prefixes.txt");
  suffix_names = names_get("data/assets/names/tech_business_suffixes.txt");

  strcpy(company.prefix_name, prefix_names.names[random_uint64_t(random)
                                                  % prefix_names.size]);
  strcpy(company.suffix_name, suffix_names.names[random_uint64_t(random)
                                                  % suffix_names.size]);

  names_destroy(prefix_names.names);
  names_destroy(suffix_names.names);

  return company;
}
