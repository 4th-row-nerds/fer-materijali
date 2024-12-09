#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Unesite cetveroznamenkasti broj > ");

	int br = 0;
	scanf("%d", &br);

	int tis = br / 1000;
	int sto = br % 1000 / 100;
	int des = br % 1000 % 100 / 10;
	int jed = br % 1000 % 100 % 10;

	if (tis + des == sto + jed) {
		printf("Provjera je uspjesna!\n");
	} else {
		printf("Apsolutna razlika suma je %d\n",abs(tis+des-sto-jed));
	}

	return EXIT_SUCCESS;
}
