#include <stdlib.h>

void getMinMax(int *polje, size_t len, int *min, int *max) {
   *min = polje[0];
   *max = polje[0];
   for (size_t i = 0; i < len; i++) {
      if (polje[i] > *max) *max = polje[i];
      if (polje[i] < *min) *min = polje[i];
   }
}
