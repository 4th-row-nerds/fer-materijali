#include <stdio.h>

void transponiraj(int* src, int* dst, int row, int col) {
   for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
         dst[i*col + j] = src[j*col + i];
      }
   }
}
