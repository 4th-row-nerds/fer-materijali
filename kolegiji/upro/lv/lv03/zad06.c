#include <stdio.h>
#include <stdlib.h>

int main(void) {

	size_t N, M, idxi, idxj;
	printf("Upisite brojeve N, M, idxi i idxj > ");
	scanf("%zu %zu %zu %zu", &N, &M, &idxi, &idxj);

	int polje[N][M];

	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			polje[i][j] = 0;
		}
	}

	int i_smjer = 1;
	int j_smjer = 1;

	size_t ukupan_broj_koraka = 0;

	// Petlja se mora ponavljati sve dok trenutan element nije 1
	while (polje[idxi][idxj] != 1) {
		ukupan_broj_koraka++;

		polje[idxi][idxj] = 1;

		idxi += i_smjer;
		idxj += j_smjer;

		// "Odbijanje" od zida
		if (idxi == 0 || idxi == N - 1) i_smjer *= -1;
		if (idxj == 0 || idxj == M - 1) j_smjer *= -1;
	}

	// Ispisivanje polja
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++) {
			printf("%d ", polje[i][j]);
		}
		printf("\n");
	}

	// Ispisivanje ukupno prijeđenog puta
	printf("Duljina: %zu\n", ukupan_broj_koraka);

	return EXIT_SUCCESS;
}

