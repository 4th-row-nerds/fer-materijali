[← Natrag](..)

>###### Demo zadatak
>Upiši broj i ispitaj ako je palindrom.
>> TODO: riješiti kasnije

# Selection sort

```c
for(size_t i = 0; i < n - 1; i++) {
  for(size_t j = i + 2; j < n; j++) {
    if (polje[i] < polje[j]) {
      //zamjena
    }
  }
}
```

# Transponiranje matrice

```c
for(i = 0 i < n - 1 i++) {
  for(j = i + 1; j < n; j++) {
    mat[i][j] <=> mat[j][i]
  }
}
```

# Demo zadatak
Upisati broj i ispisati matricu s uzorkom mete.
<br>
Za 5:
```
11111
1   1
1 1 1
1   1
11111
```

Za 10:
```
1111111111
1        1
1 111111 1
1 1    1 1
1 1 11 1 1
1 1 11 1 1
1 1    1 1
1 111111 1
1        1
1111111111
```

Rješenje:
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_RED 100

int main() {
	int mat[MAX_RED][MAX_RED] = {0};
	int red = 0;

	printf("Unesi red kvadratne matrice (< 100): ");
	scanf("%d", &red);

	printf("\n");

	for (int j = 0; j <= red/2; j+=2) {
		for (int i = j; i < red-j; i++) {
			// Retci
			mat[j][i] = 1;
			mat[red - j - 1][i] = 1;

			// Stupci
			mat[i][j] = 1;
			mat[i][red - j - 1] = 1;
		}
	}

	// Ispis
	for (int i = 0; i < red; i++) {
		for (int j = 0; j < red; j++) {
			if (mat[i][j] == 1) printf("1");
			else printf(" ");
		}
		printf("\n");
	}

	return EXIT_SUCCESS
}
```


# Demo zadatak
Programski zadatak
- s tipkovnice učitati cijeli broj n koji predstavlja broj studenata na predmetu Uvod u programiranje. Za svakog studenta učitati matični broj (int), broj bodova na međuispitu (float), broj bodova na završnom ispitu (float) i broj bodova za svaku od osam laboratorijskih vježbi (float). Evidentirati sumu bodova na svim provjerama znanja za svakog studenta (ukupni broj bodova).
- Sortirati studente prema ukupnom broju bodova, u poretku od većih prema manjim. Poredak studenata koji imaju međusobno jednak broj bodova nije važan.
- Sortirane podatke ispisati u obliku tablice
> [!note]
> Zadatak se nalazi u prezentaciji predavanja "[Agregatni tipovi podataka](https://www.fer.unizg.hr/_download/repository/07-AgregatniTipoviPodataka.pdf)", ovo je moje rješenje

Rješenje zadatka:
```c
#include <stdio.h>
#include <stdlib.h>

#define NUM_LV 8

typedef struct {
	int maticni_br;

	// Broj bodova na međuispitu
	float rez_mi;

	// Broj bodova na završnom ispitu
	float rez_zi;

	// Broj bodova na svakom od 8 labosa
	float rez_lv[NUM_LV];
	float sum_lv;

	float sum_bodova;
} student_t;


int main() {
	int br_st;
	printf("Unesi broj studenata: ");
	scanf("%d", &br_st);

	if (br_st < 1) {
		printf("Broj studenata mora biti pozitivan!\n");
		return EXIT_FAILURE;
	}

	student_t studenti[br_st];

	// Unos i izračun bodova za sve studente
	printf("Unos podataka: <maticni_broj> <broj_bodova_MI> <broj_bodova_ZI> "
	       "<LV01> <LV02> <LV03> <LV04> <LV05> <LV06> <LV07> <LV08>\n\n");
	for (int i = 0; i < br_st; i++) {
		printf("Unesi podatke za %d studenta: ", i + 1);
		scanf("%d", &studenti[i].maticni_br);
		scanf("%f %f", &studenti[i].rez_mi, &studenti[i].rez_zi);

		studenti[i].sum_bodova = 0;

		for (int j = 0; j < NUM_LV; j++) {
			scanf("%f", &studenti[i].rez_lv[j]);
			studenti[i].sum_lv += studenti[i].rez_lv[j];
		}

		studenti[i].sum_bodova += studenti[i].rez_mi;
		studenti[i].sum_bodova += studenti[i].rez_zi;
		studenti[i].sum_bodova += studenti[i].sum_lv;
	}

	// Sortiranje po broju bodova
	for (int i = 0; i < br_st - 1; i++) {
		for (int j = i + 1; j < br_st; j++) {
			if (studenti[i].sum_bodova < studenti[j].sum_bodova) {
				student_t temp = studenti[i];
				studenti[i] = studenti[j];
				studenti[j] = temp;
			}
		}
	}

	// Ispis rang liste
	printf("Rang lista\n");
	printf("Rbr.  Mat. broj    MI   ZI   LAB  Ukupno\n");
	printf("========================================\n");
	for (int i = 0; i < br_st; i++) {
		printf("%4d. %09d  %4.1f  %4.1f  %4.1f  %6.1f\n",
		    i + 1, studenti[i].maticni_br, studenti[i].rez_mi,
		    studenti[i].rez_zi, studenti[i].sum_lv, studenti[i].sum_bodova);
	}

	return EXIT_SUCCESS;
}
```
