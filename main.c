#include <stdio.h>
#include "format.h"

int main() {
  printf("Entrez une adresse IPv4 sous la forme x.x.x.x/x:\n");
  char line[256];
  char address[256];
  if (fgets(line, sizeof(line), stdin)) {
      if (1 == sscanf(line, "%s", address)) {
        char broadcast_addr[256];
        get_broadcast_addr(address, broadcast_addr);
        printf("Broadcast address is %s\n", broadcast_addr);
      }
  }
  return 0;
}
