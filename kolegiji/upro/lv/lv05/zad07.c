#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

size_t provjeri_lozinku(char *pass, int *brVelikih, int *brBrojeva, int *brSpec) {

   size_t len = strlen(pass);

   *brVelikih = 0;
   *brBrojeva = 0;
   *brSpec = 0;

    for (size_t i = 0; i < len; i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') {
            *brVelikih += 1;
        } else if (pass[i] >= '0' && pass[i] <= '9') {
            *brBrojeva += 1;
        } else if (pass[i] == '!' || pass[i] == '?'
                || pass [i] == '*' || pass[i] == '#') {
            *brSpec += 1;
      }
    }

   return len;
}

int main(void) {

   printf("Upisite lozinku > \n");
   char pass[21] = {0};
   fgets(pass, 20, stdin);

   int brVelikih, brBrojeva, brSpec;
   size_t len = provjeri_lozinku(pass, &brVelikih, &brBrojeva, &brSpec);

   if (len == 10 && brVelikih >= 2 && brBrojeva >= 2 && brSpec >= 1) {
   	printf("Lozinka je ispravna!");
   }

   if(len != 10) {
      printf("Lozinka je prekratka!");
   } else {
      if (brVelikih < 2) printf("Nema dovoljno velikih slova!\n");
      if (brBrojeva < 2) printf("Nema dovoljno brojeva!\n");
      if (brSpec < 1) printf("Nema dovoljno specijalnih znakova!");
   }

   return 0;
}
