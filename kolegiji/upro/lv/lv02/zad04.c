#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesite dimenzije polja: ");

	int n = 0;
	scanf("%d", &n);

	int mat[n][n];

	printf("Unesite elemente polja:\n");
	for (int i = 0; i < n*n; i++) {
		scanf("%d", &mat[i/n][i%n]);
	}

	// Rotiranje matrice za 90° u smjeru kazaljke na satu
	// * ekvivalentno transponiranju pa horizontalnom zrcaljenju

	// Transponiranje
	// * ekvivalentno zrcaljenju s obzirom na glavnu diagonalu
	for (int j = 0; j < n; j++) {
		for (int i = j; i < n; i++) {
			int tmp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = tmp;
		}
	}

	// Horizontalno zrcaljenje
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n/2; j++) {
			int tmp = mat[i][j];
			mat[i][j] = mat[i][(n - 1) - j];
			mat[i][(n - 1) - j] = tmp;
		}
	}


	// Ispis rotirane matrice
	printf("Izracunato polje: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}
