#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesi dimenzije: ");

	int rows = 0, cols = 0;
	scanf("%d %d", &rows, &cols);

	int mat[rows][cols];

	if (rows != cols) {
		printf("Dimenzije ne odgovaraju kvadratnoj matrici!\n");
		return EXIT_SUCCESS;
	}

	printf("Unesi clanove polja:\n");
	for (int i = 0; i < rows*cols; i++) {
		scanf("%d", &mat[i/cols][i%cols]);
	}

	// Ispis upisane matrice
	printf("Odabrana je matrica: \n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf(" %d", mat[i][j]);
		}
		printf("\n");
	}

	// Zbroj kvadrata elemenata glavne i sporedne diagonale
	int gl_diag = 0, sp_diag = 0;
	for (int i = 0; i < rows; i++) {
		gl_diag += mat[i][i] * mat[i][i];
		sp_diag += mat[i][cols - i - 1] * mat[i][cols - i - 1];
	}

	// Ispis izračuna razlike kvadrata diagonala
	printf("Razlika zbrojeva je %d.\n", gl_diag - sp_diag);

	return EXIT_SUCCESS;
}
