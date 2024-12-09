[← Natrag](..)

# Vjezba za međuispit

[PDF - Zadatci](https://www.fer.unizg.hr/_download/repository/14-Vje%C5%BEbaPrijeMI.pdf)

## Zadatak 01
Napišite program koji učitava prirodni broj n za koji je potrebno osigurati da ne bude veći od 100. Potom učitati n točaka u 2D prostoru (n parova realnih brojeva). Izračunati centar mase tih točaka, te ispisati točke uzlazno poredane po udaljenosti od centra mase…

```c
Upisati n > 10
Upisati clanove > 1 2 1 3 1 4 2 1 2 2 2 3 3
1 3 2 3.5 4.5 3.14 3.14
Centar mase: (2.16, 2.56)
Tocke: (2.00, 3.00)(2.00, 2.00)(3.00,
2.00)(3.14, 3.14)(1.00, 3.00)(1.00,
2.00)(2.00, 1.00)(3.00, 1.00)(1.00,
4.00)(3.50, 4.50)
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>
#include <math.h>

typedef struct {
	double x;
	double y;
} tocka_t;


double udaljenost(tocka_t t1, tocka_t t2) {
	double dx = t1.x - t2.x;
	double dy = t1.y - t2.y;

	return sqrt(dx*dx + dy*dy);
}

int main(void) {
	int n;

	do {
		printf("Upiši broj točaka <0, 100>:");
		scanf("%d", &n);
	} while (n <= 0 || n > 100);

	tocka_t tocke[n], centar_mase = {0};

	for (size_t i = 0; i < n; i++) {
		printf("Upiši točku: ");
		scanf("%lf %lf", &tocke[i].x, &tocke[i].y);
		centar_mase.x += tocke[i].x;
		centar_mase.y += tocke[i].y;
	}

	centar_mase.x /= n;
	centar_mase.y /= n;

	for (size_t i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (udaljenost(tocke[j], centar_mase) < udaljenost(tocke[i], centar_mase)) {
				tocka_t temp = tocke[i];
				tocke[i] = tocke[j];
				tocke[j] = temp;
			}
		}
	}

	for (size_t i = 0; i < n; i++) {
		printf("(%.2lf, %.2lf)", tocke[i].x, tocke[i].y);
	}
}
```

</details>


## Zadatak 02
S tipkovnice učitati dva niza znakova (string), nizA i nizB, pri čemu nizovi sigurno neće biti dulji od 40 znakova (uključujući eventualni znak za novi red).

U novi niz znakova (string) izlaz redom prepisati znakove niza nizA koji se tri ili više puta pojavljuju u nizu nizB. Na kraju, niz izlaz ispisati na zaslon s pomoću konverzijske specifikacije %s.
`
> Napomena: dopušteno je koristiti samo funkcije iz stdio.h, a agregatni tipovi podataka smiju se koristiti isključivo za pohranu nizova nizA, nizB i izlaz.

Primjeri izvršavanja programa:
```c
Upiši znakovni niz A: Prema Jupiteru, pitam!?
Upiši znakovni niz B: Peti Planet Jutros Pluta!!!
Izlaz > P t t!
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>
#include <string.h>

#define CAP 40

int main(void) {
	char nizA[CAP + 1];
	char nizB[CAP + 1];
	char nizOut[CAP + 1];

	printf("Upiši znakovni niz A: ");
	fgets(nizA, CAP, stdin);
	printf("Upiši znakovni niz B: ");
	fgets(nizB, CAP, stdin);

	// Broji ponavljanje znakova niza B
	int freq[256] = {0};
	for (size_t i = 0; i < strlen(nizB); i++) {
		freq[nizB[i]]++;
	}

	// trenutni znak izlaznog niza
	size_t p = 0;
	for (size_t i = 0; i < strlen(nizA); i++) {
		if (freq[nizA[i]] >= 3) {
			nizOut[p++] = nizA[i];
		}
	}
	nizOut[p] = '\0';

	printf("Izlaz > %s\n", nizOut);
}
```

</details>


# Zadatak 03
Napišite funkciju: `unsigned int ciklRshift(unsigned int br, int shift)` koja će vratiti broj koji se dobije ako ciklički pomaknemo zadani broj za zadani broj bitova udesno.

Na primjer, ako broj 7 pomaknemo ciklički za dva mjesta udesno, dobit ćemo:

```c
00000000000000000000000000000111 // 7

11000000000000000000000000000001 // ciklRshift(7, 2)
```

Potom napisati program koji učitava dva cijela broja bez predznaka i računa koliko bitova treba pomaknuti svaki od tih brojeva udesno kako bi se ostvarila maksimalna vrijednost XOR operacije između ta dva (pomaknuta) broja.

Primjeri izvršavanja programa:
```c
Upisi dva broja: 18 3
Maksimalni XOR je 4026531840
- pritom a treba pomaknuti za 5 udesno kako bi dobili: 2415919104
- pritom b treba pomaknuti za 3 udesno kako bi dobili: 1610612736
a >> 5 = 10010000000000000000000000000000
b >> 3 = 01100000000000000000000000000000
-------------------------------------------- ^
11110000000000000000000000000000
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>

size_t ciklRshift(size_t br, size_t shift) {
	shift %= 8*sizeof(br);
	size_t ostatak = br << (8*sizeof(br) - shift);
	size_t shifted = br >> (shift);

	return shifted || ostatak;
}

int main(void) {

	size_t br1, br2;
	printf("Upiši dva broja: ");
	scanf("%zu %zu", &br1, &br2);

	size_t max = 0;
	size_t max_i = 0;
	size_t max_j = 0;

	for (size_t i = 0; i < 8*sizeof(br1); i++) {
		size_t c1 = ciklRshift(br1, i);
		for (size_t j = 0; j < 8*sizeof(br2); j++) {
			size_t c2 = ciklRshift(br2, j);

			if ((c1 ^ c2) > max) {
				max = c1 ^ c2;
				max_i = i;
				max_j = j;
			}


		}
	}

	// printf("Izlaz > %s\n", );
}
```

</details>

> [!caution]
> Završiti zadatak
