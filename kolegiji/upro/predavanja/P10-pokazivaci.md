[← Natrag](..)

# Pokazivači

## Definicija
Varijabla koja pokazuje na mjesto u memoriji gdje se nalaze vrijednosti koje nam trebaju.

tj. pokazivač je referenca na varijablu

## Deklaracija
Pokazivač se može deklarirati od bilokojeg osnovnog tipa podatka dodavanjem zvjezdice nakon imena varijable.

Za deklariranje pokazivaca `int` tipa:
```c
int *pokazivac;
```
<br>

Za deklariranje pokazivaca `char` tipa:
```c
char *pokazivac;
```


## Korištenje

## Operator dereferenciranja
- Prefiksnim operatorom `*`, program će koristiti vrijednost varijable na adresi pokazivača umjesto adrese pokazivača.
- Time možemo dodjeliti vrijednosti i čitati iz varijable na koju pokazivač pokazuje
Kreiranje varijable `a` i kreiranje reference na tu varijablu.


```c
int a = 4;
int *ap; // Deklariranje pokazivača int tipa
ap = &a; // Inicijalizacija pokazivača na adresu varijable a

*ap = 5; // Mijenjanje varijable a preko reference (engl. dereferencing)
```

## Korištenje pokazivača za vraćanje višestrukih vrijednosti iz funkcije

```c
void funk(int *ap) {
  *ap = 4;

  return;
}

int main(void) {
  int a = 1;
  funk(&a);

  printf("a = %d", a); // Ispisuje a = 4 (, a ne 1)
  return 0;
}
```

### Primjer vraćanja vrijednosti varijeble pomnožene s 2 i podjeljene s 2
```c
void mul_div(int a, int *a2, int *ap) {
  *a2 = a*2;
  *ap = a/2;

  return;
}

int main(void) {
  int a = 4;
  int ap, a2;
  funk(a, &a2, &ap);

  printf("a = %d", a);
  printf("2*a = %d", a2);
  printf("a/2 = %d", ap);
  return 0;
}
```

# Demo Zadatak
Upotrijebimo void* da ispišemo bitove odnosno IEEE754 reprezentaciju float broja (binarnu i hex)

# Polja u funkcijama
Pokazivačem na 0. član polja funkciji možemo dati informaciju gdje tražiti polje i ako zna koliko ima elemenata može uzeti taj pokazivač i povećavati ga za svaki broj [0 ... n] kako bi dobila ostale elemente polja.
```c
void pomnozi_polje_s_2(int *polje, size_t velicina_polja) {
  for (size_t i = 0; i < velicina_polja; i++) {
    *(polje + i) = 2 * *(polje + i);
  }

  return;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};
  pomnozi_polje_s_2(a, 5); // predavanje polja a je ekvivalentno predavanju pokazivača na prvi element polja

  // a je sada {2, 4, 6, 8, 10};
}
```

Primjeti kako smo funkciji predali `a`, a ne `&a[0]`. To je zato što C, kako bi nam olakšao, pokazivač na prvi element polja dozvoljava prikazati s imenom polja.

U C-u također postoji "fancy" način za predavanje polja u funkciju:
```c
void pomnozi_polje_s_2(size_t velicina_polja, int polje[velicina_polja]) {
  for (size_t i = 0; i < velicina_polja; i++) {
    polje[i] = 2 * polje[i];
  }

  return;
}

int main(void) {
  int a[5] = {1, 2, 3, 4, 5};
  pomnozi_polje_s_2(5, a);

  // a je sada {2, 4, 6, 8, 10};
}
```

u ovom slučaju polje se u funkciji može koristiti isto kao i u pozivačkoj funkciji.
U pozadini C i dalje šalje element na prvi član, samo zato što kompajler razumije što želiš napravit, može ti pomoći i pojednostaviti sintaksu.


> [!caution]
> Napraviti zadatak

# Demo zadatak
- Napisati funkciju `najvacei_clan_1D` koja kao rezultat vraća najveću vrijednost u zadanom jednodimenzijskom cjelobrojnom polju
- Napisati glavni program koji će s tipkovnice učitati 10 članova cjelobrojnog polja, pomoć funkcije odrediti najveći član, te ga ispisati na zaslonu.

```c
#include <stdio.h>
#include <stdlib.h>

int najveci_clan_1D(size_t len, int polje[len]) {
  int najveci;
  for (size_t i = 0; i < len; i++) {
    if (i == 0 || polje[i] > najveci) {
      najveci = polje[i];
    }
  }

  return najveci;
}

#define DIMENZIJA 10

int main(void) {
  int polje[DIMENZIJA];

  /* Ovdje ide kod za učitavanje elemenata polja */

  printf("Najveci clan je %d.\n", najveci_clan_1D(DIMENZIJA, polje));
}

```

# Indeksiranje elementa 2D polja pokazivačima
```c
// ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
// │ p[0][0] │ p[0][1] │ p[0][2] │ p[1][0] │ p[1][1] │ p[1][2] │ p[2][0] │ p[2][1] │ p[2][2] │
// └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
//
// Element p[2][1] nalazi se 4 elementa od p[0][0], tj. nalazi se na udaljenosti od 2 retka i 1 elementa od p[0][0]
// tj. pokazivačem a na element p[0][0], do elementa p[2][1] dolazi se formulom:
// *(a + i*duljina_retka + j)
// = *(a + 2*3 + 1)
// = *(a + 7)
```
