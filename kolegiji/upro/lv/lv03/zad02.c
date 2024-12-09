#include <stdio.h>
#include <stdlib.h>

int main(void) {

	size_t N;
	printf("Upisite broj redaka/stupaca matrice > ");
	scanf("%zu", &N);

	int mat[N][N];

	printf("Upisite %zux%zu clanova > \n", N, N);
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N; j++) {
			scanf("%d", &mat[i][j]);
		}
	}

	size_t row;
	printf("Upisite redni broj retka > ");
	scanf("%zu", &row);

	size_t col;
	printf("Upisite redni broj stupca > ");
	scanf("%zu", &col);

	// Suma je incijalizirana s elementom sijecišta retka i stupca jer onda on kasnije može samo preskočiti
	int el_sum = mat[row][col];

	// Zbrajanje svih elemenata u retku row preskačući onaj u kojem se sjeku redak i stupac
	for (size_t i = 0; i < N; i++) {
		if (i == col) continue;
		el_sum += mat[row][i];
	}

	// Zbrajanje svih elemenata u stupcu col preskačući onaj u kojem se sjeku redak i stupac
	for (size_t i = 0; i < N; i++) {
		if (i == row) continue;
		el_sum += mat[i][col];
	}


	printf("Suma brojeva koji se nalaze u retku %zu i stupcu %zu je %d.", row, col, el_sum);

	return EXIT_SUCCESS;
}
