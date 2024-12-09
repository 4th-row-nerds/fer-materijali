[← Natrag na početnu](../../README.md#uvod-u-programiranje)

# Sintaksa C-a

> ligatures - (<= $\Rightarrow \space \leq$) izgleda kao jedan znak

## Prioritet aritmetičkih operatora

a + b * c $\equiv$ a + (b * c)
<br>
b * c + a $\equiv$ (b * c) + a


## Bitno razlikovati dodjeljivanje od uspoređivanja

```c
if (x = 0)
```
- uvijek false jer dodjeljuje 0 varijabli x

## Upisivanje brojeva

```c
#include <stdio.h>

int main() {
  int n1, n2, n3, n4, n5;
  scanf("%d %d", n1, n2);
  scanf("%d%d", n3, n4);
  scanf("%d", n5);
}
```

Neovisno o načinu formatiranja upisuje svih 5 brojeva kad ih odvojimo razmacima.

## Postupci izrade manjih programa
1. razvoj algoritma
1. implementacija algoritma u prog jeziku
1. Prevođenje programa u objektni kod
1. Ispravljanje formalnih grešaka (syntax errors)
1. povezivanje programa (linker errors)
1. izvršavanje (run-time errors)
1. rezultati (semantic errors


## Demo zadatak 1
Napiši program koji prepoznaje ako je godina prijestupna.
> Godina je prijestupna ako je djeljiva s 400 ili je djeljiva s 4 i nije djeljiva s 100.

Primjeri unosa:
```c
Upiši godinu: 2000
Godina 2000. je prijestupna!
```
```c
Upiši godinu: 2024
Godina 2024. je prijestupna!
```
```c
Upiši godinu: 1900
Godina 1900. nije prijestupna!
```

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int godina = 0;
	printf("Upiši godinu: ");
	scanf("%d", &godina);

	if (godina % 400 == 0
	    || godina % 4 == 0 && godina % 100 != 0) {
		printf("Godina %d. je prijestupna!", godina);
	} else {
		printf("Godina %d. nije prijestupna!", godina);
	}
	return EXIT_SUCCESS;
}
```

## Demo zadatak 2
Napisati program koji će za točku u ravnini napisati u
kojem kvadrantu zadanog pravokutnika se nalazi.
<br>
Potrebno je učitati:
- koordinate donjeg lijevog i gornjeg desnog ugla pravokutnika
- koordinate točke koja se ispituje
- Ovisno o tome gdje se točka nalazi ispisati:
- Točka (…, …) se ne nalazi u pravokutniku
- Točka (…, …) se nalazi u kvadrantu {A|B|C|D}
- Pretpostaviti da će koordinate pravokutnika biti ispravno zadane
- U slučaju da točka dodiruje više kvadranata (na granici je) ispisati bilo kojeg od njih

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	printf("Upiši koordinate doljnjeg kuta (x1 y1): ");
	float x1, y1;
	scanf("%f %f", &x1, &y1);

	printf("Upiši koordinate gornjeg kuta (x2 y2): ");
	float x2, y2;
	scanf("%f %f", &x2, &y2);

	printf("Upiši koordinate točke (x y): ");
	float x, y;
	scanf("%f %f", &x, &y);

	// -1 ispod polovice, 1 iznad polovice
	int vertikalna_polovica = 0;

	int horizontalna_polovice = 0;

	if (x > x2 || x < x1 || y > y2 || y < y1) {
		printf("Točka nije unutar kvadrata!\n");
		return EXIT_SUCCESS;
	}

	if (x > (x2 - x1) / 2) vertikalna_polovica = 1;
	else vertikalna_polovica = -1;

	if (y > (y2 - y1) / 2) horizontalna_polovice = 1;
	else horizontalna_polovice = -1;

	char kvadrant;

	kvadrant = 'A';
	if (vertikalna_polovica == 1 && horizontalna_polovice == 1) kvadrant = 'B';
	if (vertikalna_polovica == 0 && horizontalna_polovice == 0) kvadrant = 'C';
	if (vertikalna_polovica == 0 && horizontalna_polovice == 1) kvadrant = 'D';

	printf("U kvadrantu %c\n", kvadrant);

	return EXIT_SUCCESS;
}
```
