#include "organization.h"
#include "../util/names.h"

Organization organization_generate(Type type, Random *random) {
  Organization organization;
  NameArray prefix_names;
  NameArray suffix_names;

  switch (type) {
    case technology:
      prefix_names = names_get(
                      "data/assets/names/organizations/tech_business_prefixes.txt");
      suffix_names = names_get(
                      "data/assets/names/organizations/tech_business_suffixes.txt");
      break;
    case bank:
      prefix_names = names_get(
                      "data/assets/names/organizations/bank_prefixes.txt");
      suffix_names = names_get(
                      "data/assets/names/organizations/bank_suffixes.txt");
      break;
    default:
      break;
  }

  strcpy(organization.prefix_name, prefix_names.names[random_uint64_t(random)
                                                  % prefix_names.size]);
  strcpy(organization.suffix_name, suffix_names.names[random_uint64_t(random)
                                                  % suffix_names.size]);

  names_destroy(prefix_names.names);
  names_destroy(suffix_names.names);

  organization.type = type;

  return organization;
}
