#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char ulaz[201] = {0};
	printf("Upisite znakovni niz > ");
	fgets(ulaz, 200, stdin);

	char izlaz[strlen(ulaz)+1];
	// Potrebno je pobrinuti se da je zadnji element '\0' za svaki slučaj
	izlaz[strlen(ulaz)] = '\0';

	// i prolazi kroz sve znakove ulaza i postavlja izlaz odozada
	for (size_t i = 0; i < strlen(ulaz); i++) {
		char z;

		// Ako je slovo malo pretvori ga u veliko
		if (ulaz[i] <= 'z' && ulaz[i] >= 'a') z = ulaz[i] - ('a' - 'A');
		else z = ulaz[i];

		izlaz[strlen(ulaz) - 1 - i] = z;
	}

	printf("Obrnuti niz: %s\n", izlaz);

	return EXIT_SUCCESS;
}
