#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Upisite dva prirodna broja iz intervala [1, 1000] > ");

	int a = 0, b = 0;
	scanf("%d %d", &a, &b);

	if (a < 1 || a > 1000 || b < 1 || b > 1000) {
		printf("Brojevi moraju biti u intervalu [1, 1000].");
		return EXIT_FAILURE;
	}

	if (a > b) {
		printf("Prvi broj mora biti manji od drugog broja.");
		return EXIT_FAILURE;
	}

	size_t sum = 0;

	for (size_t i = a+2; i <= b; i+=3) {
		sum += i;
	}


	printf("Zbroj svakog treceg broja iznosi: %zu", sum);



	return EXIT_SUCCESS;
}
