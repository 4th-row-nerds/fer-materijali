#include <stdio.h>
#include <stdlib.h>

#define LEN(p) sizeof(p)/sizeof(p[0])

int main() {
	printf("Unesite broj > ");

	float br = 0;
	scanf("%f", &br);

	if (br != (int)br || br <= 0) {
		printf("Unesen je pogresan broj!");
		return EXIT_FAILURE;
	}

	int brojevi[] = {2, 3, 5, 7};
	int count = 0;

	for (int i = 0; i < LEN(brojevi); i++) {
		if ((int)br % brojevi[i] == 0) {
			printf("Broj je djeljiv s brojem %d.\n", brojevi[i]);
			count++;
		}
	}

	if (count == 0) printf("Broj nije djeljiv s brojevima 2, 3, 5, 7.");


	return EXIT_SUCCESS;
}
