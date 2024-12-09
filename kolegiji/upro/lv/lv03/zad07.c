#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

	char string[151] = {0};
	printf("Upisite znakovni niz > ");
	fgets(string, 150, stdin);

	// i prolazi kroz sve znakove ulaza, p pokazuje na trenutni znak u stringu koji je dio engleske abecede
	size_t p = 0;
	for (size_t i = 0; i < strlen(string); i++) {
		if ((string[i] <= 'z' && string[i] >= 'a')
	         || (string[i] <= 'Z' && string[i] >= 'A')) {
			string[p++] = string[i];
		}
	}
	string[p] = '\0';

	printf("Izlazni znakovni niz je: ");
	if (p == 0) printf("prazan string\n");
	else printf("%s\n", string);

	return EXIT_SUCCESS;
}

