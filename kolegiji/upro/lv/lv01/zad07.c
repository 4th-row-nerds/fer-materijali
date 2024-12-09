#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesite broj rijeci brojalice > ");

	float br = 0;
	scanf("%f", &br);

	if (br != (int)br || br <= 0) {
		printf("KRIVI UNOS");
		return EXIT_FAILURE;
	}

	char *brojevi[5] = {"eci", "peci", "pec"};

	for (int i = 0; i < br; i++) {
		printf("%s ", brojevi[i%3]);
	}

	return EXIT_SUCCESS;
}
