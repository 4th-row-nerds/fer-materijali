#include <stdlib.h>
#include <string.h>

void obrni(char *src, char *dst) {
   for (size_t i = 0; i < strlen(src); i++) {
      // -1 je zbog \0 na kraju src niza
      dst[i] = src[strlen(src) - i - 1];
   }
   dst[strlen(src)] = '\0';
}
