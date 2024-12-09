#include <stdio.h>
#include <stdlib.h>

void pad(int n, char a) {
	for (size_t j = 0; j < n; j++) putchar(a);

	return;
}

int main() {
	printf("Unesite broj > ");

	int br = 0;
	scanf("%d", &br);

	if (br % 2 == 0) {
		printf("Neispravan unos!");
		return EXIT_FAILURE;
	}



	for (int i = 0; i < br/2; i++) {
		pad(br/2 - i, ' ');
		pad(2*i + 1, '*');
		putchar('\n');
	}
	for (int i = br/2; i >= 0; i--) {
		pad(br/2 - i, ' ');
		pad(2*i + 1, '*');
		putchar('\n');
	}
	return EXIT_SUCCESS;
}
