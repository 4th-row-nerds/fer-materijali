#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesite pH vrijednost otopine > ");

	int pH = 0;
	scanf("%d", &pH);

	if (pH < 0 || pH > 14) {
		printf("KRIVI UNOS");
		return EXIT_FAILURE;
	}


	printf("Otopina je ");
	if (pH == 7) printf("neutralna.");
	else if (pH < 7) printf("kisela.");
	else printf("luznata.");

	return EXIT_SUCCESS;
}
