#include <stdlib.h>
#include <string.h>

struct person_s{
   int code;
   char name[128];
   float salary;
};

void delCharFromName(struct person_s *p, char c) {
   for (size_t i = 0; i < strlen(p->name); i++) {
      if (p->name[i] != c) continue;

      // Kopiraj sve znakove za jedno mjesto ulijevo pocevsi od tog c znaka
      for (size_t j = i - 1; i < strlen(p->name); j++) {
         p->name[j - 1] = p->name[j];
      }
   }
}
