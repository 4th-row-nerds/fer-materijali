#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesite broj dana > ");

	int br_dana = 0;
	scanf("%d", &br_dana);

	int godina = br_dana / 365;
	int tjedana = br_dana % 365 / 7;
	int dana = br_dana % 365 % 7;

	printf("Unos odgovara razdoblju od %d godina %d tjedana i %d dana\n", godina, tjedana, dana);

	return EXIT_SUCCESS;
}
