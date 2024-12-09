#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	size_t len;
	printf("Upisite velicinu polja m > ");
	scanf("%zu", &len);

	int polje[len];

	printf("Upisite %zu clanova polja m > ", len);
	for (size_t i = 0; i < len; i++) {
		scanf("%d", &polje[i]);
	}

	int max_sum = INT_MIN;
	size_t max_start = 0;
	size_t max_end = 0;

	for (size_t start = 0; start < len; start++) {
		for (size_t end = 0; end < len; end++) {
			int curr_sum = 0;
			for (size_t i = start; i <= end; i++) { curr_sum += polje[i]; }

			if (curr_sum > max_sum) {
				max_sum = curr_sum;
				max_start = start;
				max_end = end;
			}
		}
	}


	printf("Pronadjeno pod-polje:");
	for (size_t i = max_start; i <= max_end; i++) {
		printf(" %d", polje[i]);
	}
	printf("\n");

	printf("Najveca suma kontinuiranog pod-polja je: %d", max_sum);

	return EXIT_SUCCESS;
}
