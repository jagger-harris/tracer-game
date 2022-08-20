#include "mac.h"

#include <stdio.h>

MAC mac_generate(Random *random) {
  MAC mac;
  uint8_t reserved_first_bits[] = {0, 10, 127};

  uint8_t first_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t second_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t third_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t fourth_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t fifth_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t sixth_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;

  mac.first_octet = first_octet;
  mac.second_octet = second_octet;
  mac.third_octet = third_octet;
  mac.fourth_octet = fourth_octet;
  mac.fifth_octet = fifth_octet;
  mac.sixth_octet = sixth_octet;

  return mac;
}

void mac_print(MAC mac) {
  printf("%x:%x:%x:%x:%x:%x\n", mac.first_octet, mac.second_octet, mac.third_octet, mac.fourth_octet, mac.fifth_octet, mac.sixth_octet);
}
