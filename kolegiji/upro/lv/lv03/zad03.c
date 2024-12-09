#include <stdio.h>
#include <stdlib.h>

int main(void) {

	size_t N;
	printf("Unesite n > ");
	scanf("%zu", &N);

	int mat[N][N];

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	// Sume svih stupaca
	int sum_stupca[N];

	// Zbrajanje svih elemenata u stupcu i te spremanje u novo polje
	for (size_t i = 0; i < N; i++) {
		sum_stupca[i] = 0;
		for (size_t j = 0; j < N; j++) {
			sum_stupca[i] += mat[j][i];
		}
	}


	// Ispisivanje razlika stupaca
	printf("Rezultat >");
	for (size_t i = 0; i < N; i++) {
		printf(" %d", sum_stupca[i] - sum_stupca[(i+1)%N]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}
