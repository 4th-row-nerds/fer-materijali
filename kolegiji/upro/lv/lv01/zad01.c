#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Upisite iznos u kn > ");

	int iznos = 0;
	scanf("%d", &iznos);

	int kn5 = iznos / 5;
	int kn2 = iznos % 5 / 2;
	int kn1 = iznos % 5 % 2;

	printf("Kovanice:\n");

	if (kn5) printf("%d x 5 kn\n", kn5);
	if (kn2) printf("%d x 2 kn\n", kn2);
	if (kn1) printf("%d x 1 kn\n", kn1);

	return EXIT_SUCCESS;
}
