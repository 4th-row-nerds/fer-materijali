#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void prebrojiPojave(char *niz, char objekt, int *rezultat) {

   objekt = toupper(objekt); // Pretvara malo slovo u veliko

   *rezultat = 0;
   for (size_t i = 0; i < strlen(niz); i++) {
      niz[i] = toupper(niz[i]);
      if (niz[i] == objekt) *rezultat += 1;
   }
}
