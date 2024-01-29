#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "format.h"

/*
 * Convert an IPv4 represented as an integer to a properly
 * formatted decimal IPv4 address.
*/
void integer_to_string(unsigned int ip_addr, char* ip_addr_as_str) {
  // Note: this is done manually to show a way of converting
  // a string to an ipv4 address. Please use the inet library
  // for any real life use cases.
  //
  // Unsigned ints for each part of the address
  unsigned int p1, p2, p3, p4;

  p1 = (ip_addr >> (24)) & 0xFF;
  p2 = (ip_addr >> (16)) & 0xFF;
  p3 = (ip_addr >> (8)) & 0xFF;
  p4 = ip_addr & 0xFF;

  sprintf(ip_addr_as_str, "%u.%u.%u.%u", p1, p2, p3, p4);
}

/*
 * Return an unsigned int corresponding to the value of the
 * provided IPv4 address.
 *
 * Note: This function isn't safe. It assumes a valid IPv4
 * address.
*/
unsigned int string_to_integer(char ip_addr[]) {

  // Remove the subnet identifier from the stringchar *ptr;
  char *ptr;
  ptr = strchr(ip_addr, '/');
  if (ptr != NULL) {
      *ptr = '\0';
  }

  unsigned long int addr_as_int = 0;

  char *token;

  unsigned int shift = 3;
  // Split the string on each "."
  token = strtok(ip_addr, ".");
  while(token != NULL) {
    // Reading parts of the ip addr from left to right.
    // This means the first part needs to be multiplied by
    // 256^3, the second one by 256^2, the third one by
    // 256^1, and the last one by 256^0
    unsigned long int current_part = strtoul(token, NULL, 0);
    current_part = current_part<<(shift * 8);
    addr_as_int += current_part;
    token = strtok(NULL, ".");

    shift--;
  }

  return addr_as_int;
}

unsigned int get_subnet_mask_len(char ip_addr[]){
  // Get the value associated with the subnet mask

  char *token;
  token = strtok(ip_addr, "/");
  token = strtok(NULL, "/");
  if (token == NULL) {
    printf("Adresse IP invalide: subnet mask manquant.");
    exit(1);
  }

  unsigned int subnet_mask_len = strtoul(token, NULL, 0);

  return subnet_mask_len;
}

void get_broadcast_addr(char addr[], char *broadcast_addr) {
  // Votre code ici!
}
