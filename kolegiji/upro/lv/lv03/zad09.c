#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_CHARS 256

int main(void) {
	char ulaz[51] = {0};
	printf("Unesite niz > ");
	fgets(ulaz, 50, stdin);


	// Lista broja ponavljanja za svaki znak po njegovom ASCII kodu
	char num_reps[NUM_CHARS] = {0};

	for (size_t i = 0; i < strlen(ulaz); i++) {
		char c = ulaz[i];

		if (c == '\n') continue;

		num_reps[(size_t)c]++;
	}

	size_t max_reps = 0;
	size_t num_rep_chars = 0;
	char first_rep_char_id = 0;

	// Traženje najvećeg broja ponavljanja i broj znakova koji imaju isti broj ponavljanja
	for (size_t i = 0; i < NUM_CHARS; i++) {
		if (num_reps[i] > max_reps) {
			max_reps = num_reps[i];
			num_rep_chars = 1;
			first_rep_char_id = i;
		} else if (num_reps[i] == max_reps) {
			num_rep_chars++;
		}
	}

	// Ispis rezultata
	if (num_rep_chars == 1) {
		printf("Znak \"%c\" se ponavlja %zu puta.\n", first_rep_char_id, max_reps);
	} else {
		printf("Znakovi \"%c\"", first_rep_char_id);
		for (size_t i = first_rep_char_id + 1; i < NUM_CHARS; i++) {
			if (num_reps[i] == max_reps) printf(", \"%c\"", (char)i);
		}
		printf(" se ponavljaju %zu puta.\n", max_reps);
	}


	return EXIT_SUCCESS;
}
