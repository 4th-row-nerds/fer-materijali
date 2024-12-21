#include <stdlib.h>

// Vektori a i b s n elemenata
int dot_produkt(int *a, int *b, int n) {

   int rez = 0;
   for (size_t i = 0; i < n; i++) {
      rez += a[i] * b[i];
   }

   return rez;
}

// X matrica množi vektor a i rezultat sprema u rez
void mat_vec_produkt(int *X, int *a, int n, int *ret) {

   for (size_t i = 0; i < n; i++) {
      // Retci u X množe stupce (jedan stupac) u a
      ret[i] = dot_produkt(&X[n*i], a, n);
   }
}
