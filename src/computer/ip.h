#ifndef IP_H
#define IP_H

#include <stdint.h>
#include <stdlib.h>

#include "../util/util.h"

#define MAX_OCTET_SIZE 256

typedef struct {
  uint8_t first_octet;
  uint8_t second_octet;
  uint8_t third_octet;
  uint8_t fourth_octet;
} IP;

IP ip_generate(Random *random);
int check_reserved_bits_all(uint8_t octet, uint8_t arr[], size_t arr_size);
int check_reserved_bits_range(uint8_t octet, size_t start, size_t finish);
void ip_print(IP ip);

#endif /* IP_H */
