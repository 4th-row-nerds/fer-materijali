#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Upisite troznamenkasti prirodni broj > ");

	int br = 0;
	scanf("%d", &br);

	int tis = br / 1000;
	int sto = br % 1000 / 100;
	int des = br % 1000 % 100 / 10;
	int jed = br % 1000 % 100 % 10;

	int par = 0, nepar = 0;
	if (tis % 2 == 0) par += tis;
	else nepar += tis;

	if (sto % 2 == 0) par += sto;
	else nepar += sto;

	if (des % 2 == 0) par += des;
	else nepar += des;

	if (jed % 2 == 0) par += jed;
	else nepar += jed;

	printf("Rezultat: %d\n",par - nepar);

	return EXIT_SUCCESS;
}
