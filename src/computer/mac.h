#ifndef MAC_H
#define MAC_H

#include "../util/util.h"

#define MAX_OCTET_SIZE 256

typedef struct {
  uint8_t first_octet;
  uint8_t second_octet;
  uint8_t third_octet;
  uint8_t fourth_octet;
  uint8_t fifth_octet;
  uint8_t sixth_octet;
} MAC;

MAC mac_generate(Random *random);
void mac_print(MAC mac);

#endif /* MAC_H */
