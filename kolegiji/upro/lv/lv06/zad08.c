#include <stdlib.h>
#include <string.h>

void duplicirajSamoglasnike(char *ulaz, char *izlaz) {

   int offset = 0;
   for (size_t i = 0; i < strlen(ulaz); i++) {
      izlaz[i + offset] = ulaz[i];

      char c = ulaz[i] & ~32; // Prebacivanje slova u veliko

      if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
          offset++;
          izlaz[i + offset] = ulaz[i];
      }
   }
}
