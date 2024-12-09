#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Upisite broj clanova polja:");

	int arr_len = 0;
	scanf("%d", &arr_len);

	int arr[arr_len];

	printf("Upisite clanove polja (%d):\n", arr_len);
	for (int i = 0; i < arr_len; i++) {
		scanf("%d", &arr[i]);
	}


	printf("Unesite vrijednost novog clana te indeks:\n");

	int novi_el = 0, el_index = 0;
	scanf("%d %d", &novi_el, &el_index);


	// Ispis polja prije promijene
	printf("Pocetno polje\n");
	for (int i = 0; i < arr_len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	if (el_index < 0 || el_index >= arr_len) {
		printf("Indeks izvan granica polja!\n");
		return EXIT_FAILURE;
	}

	for (int i = arr_len - 1; i > el_index; i--) {
		arr[i] = arr[i - 1];
	}
	arr[el_index] = novi_el;


	// Ispis polja nakon promijene
	printf("Novodobiveno polje\n");
	for (int i = 0; i < arr_len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return EXIT_SUCCESS;
}
