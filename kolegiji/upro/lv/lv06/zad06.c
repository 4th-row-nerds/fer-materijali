#include <stdlib.h>
#include <stdbool.h>

int zajednickiDjelitelj(int *matrica, int rows, int cols) {

   int max_djelj = 1;

   // Prolazimo kroz sve elemente matrice
   for (size_t i = 0; i < rows*cols; i++) {

      /* Ako je trenutni broj manji od već provjerenog maksimalnog djelitelja,
       * nema smilsa provjeravati ako je djelitelj jer neće biti veći od posojećeg.
       */
      if (matrica[i] < max_djelj) continue;

      // Provjeravamo ako je zajednicki djelitelj sa svim ostalim elementima
      // Pretpostavljamo da je djelitelj svih
      bool is_djelitelj = true;
      for (size_t j = 0; j < rows*cols; j++) {
         if (matrica[j] % matrica[i] != 0) {
            is_djelitelj = false;
            break;
         }
      }

      if (is_djelitelj && matrica[i] > max_djelj) {
         max_djelj = matrica[i];
      }
   }

   return max_djelj;
}


void podijeli(int *mat, int rows, int cols, int *rez) {
   int max_djelj = zajednickiDjelitelj(mat, rows, cols);
   for (size_t i = 0; i < rows*cols; i++) {
      rez[i] = mat[i] / max_djelj;
   }
}
