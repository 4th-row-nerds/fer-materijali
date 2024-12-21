#include <stdlib.h>
#include <math.h>

void stddev(float *polje, int len, float *std_dev) {

   // mean == aritmeticka sredina svih clanova polja
   float mean = 0;
   for (size_t i = 0; i < len; i++) {
      mean += polje[i];
   }
   mean /= (float)len;


   float suma_kvadrata = 0;
   for (size_t i = 0; i < len; i++) {
      suma_kvadrata += pow(polje[i] - mean, 2);
   }

   *std_dev = sqrt(suma_kvadrata/len);

	return;
}

int IndexOfMaxdev(float *polje, int row, int col) {

   float max_dev;
   int max_row = 0;
   stddev(polje, col, &max_dev);

   for (size_t i = 1; i < row; i++) {
      float curr_dev;
      stddev(&polje[i*col], col, &curr_dev);
      if (curr_dev > max_dev) {
      	max_row = i;
         max_dev = curr_dev;
      }
   }
   return max_row;
}
