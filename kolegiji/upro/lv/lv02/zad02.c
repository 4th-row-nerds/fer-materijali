#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesite duljinu polja:");

	int arr_len = 0;
	scanf("%d", &arr_len);

	int arr[arr_len];

	printf("Unesite elemente polja:\n");
	for (int i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}

	for (int j = 0; j < arr_len; j++) {
		for (int i = j; i < arr_len - 1; i++) {
			arr[j] += arr[i+1];
		}
	}


	// Ispis polja nakon izračuna
	printf("Izracunato polje\n");
	for (int i = 0; i < arr_len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}
