#include "ip.h"

#include <stdio.h>

IP ip_generate(Random *random) {
  IP ip;
  uint8_t reserved_first_bits[] = {0, 10, 127};

  uint8_t first_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t second_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t third_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  uint8_t fourth_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;

  while (check_reserved_bits_all(first_octet, reserved_first_bits, sizeof(reserved_first_bits))) {
    first_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
    printf("%i\n", first_octet);
  }

  while(check_reserved_bits_range(first_octet, 224, 255)) {
    first_octet = (uint8_t)random_uint64_t(random) % MAX_OCTET_SIZE;
  }

  ip.first_octet = first_octet;
  ip.second_octet = second_octet;
  ip.third_octet = third_octet;
  ip.fourth_octet = fourth_octet;

  return ip;
}

int check_reserved_bits_all(uint8_t octet, uint8_t arr[], size_t arr_size) {
  uint32_t i;
  
  for (i = 0; i < arr_size / sizeof(octet); i++) {
    if (octet == arr[i]) {
      return 1;
    }
  }
  
  return 0;
}

int check_reserved_bits_range(uint8_t octet, size_t start, size_t finish) {
  uint32_t i;
  
  for (i = start; i <= finish; i++) {
    if (octet == i) {
      return 1;
    }
  }

  return 0;
}

void ip_print(IP ip) {
  printf("%u.%u.%u.%u\n", ip.first_octet, ip.second_octet, ip.third_octet, ip.fourth_octet);
}
