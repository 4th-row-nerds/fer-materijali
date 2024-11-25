[← Natrag na početnu](../../README.md#uvod-u-programiranje)

# Funkcije

## Definicija

Za pravilnu definiciju potrebno je definirati:
 - Tip rezultata funkcije
 - naziv funkcije
 - (opcionalno) lista parametara funkcije, za svaki parametar: tip i naziv
 - tijelo funkcije: definicije i deklaracije, naredbe koje se obavljaju kad se funkcija pozove
 - (opcionalno) naredba za povratak rezultata i programskog slijeda


Opći oblik:
```c
tip_rezultata naziv_funkcije(lista_parametara) {
  // definicije, deklaracije i naredbe;

  return rezultat;
}
```

### Tip rezultata
Tip mora biti naveden čak i kada funkcija ništa ne vraća (onda se koristi poseban tip `void`)

### Povratak rezultata
 - povratak rezultata pozivatelju
 - funkcija može vratiti samo jednu vrijednost
 - u funkciji koja ne vraća rezultat naredba `return` može se:
   - izostaviti
   - ili koristiti bez navođenja izraza koji predstavlja rezultat
 - naredba se može navesti više puta unutar iste funkcije
   - Provjere na početku koje nisu zadovoljene mogu odma vratiti rezultat pozivatelju bez izvršavanja ostatka koda (engl. guard clause)

### Poziv funkcije
 - argumenti se navode pri pozivu funkcije u redosljedu kako su definiranu unutar okruglih zagrada odvojedni zarerima.
 - ako funkcija nema parametara ne piše se void već samo prazne zagrade

## Primjer: definicije funkcije

```c
double eksp(float x, int n) {
  int i;
  double rez = 1.;
  for (i = 0; i < n; ++i) rez *= x;

  return rez;
}
```


## Primjer: pozivanja funkcije

```c
#include <stdio.h> // za printf u funkciji main

double eksp(float x, int n) {
...
  return rez;
}
...
int main(void) {
...
  double y = eksp(3.f, 4);
  printf("Tri na cetvrtu je %lf", y);
  printf("Dva na petu je %lf", eksp(2.f, 5));
  eksp(3.f, 2);                          // ispravno, ali beskorisno
  y = eksp(3.5f, 2) + 2 * eksp(2.1f, 3); // 3.5^2 + 2 ∙ 2.1^3
  y = eksp(eksp(2 * 3.f, 2), 4);         // (6^2)^4
...
}
```


## Primjer funkcije koja ne vraća rezultat
```c
void ispisXY(float x, float y) {
  printf("(%.4f, %.4f)", x, y);
  return; može se izostaviti
}

int main(void) {
  float x = 3.25f, y = -12.f;

  printf("Koordinate: ");
  ispisXY(x, y);

  // Ispis programa: "Koordinate: (3.2500, -12.0000)"
  return 0;
}
```

> [!note] Implicitne konverzije
> Argumenti funkcije implicitno se pretvaraju u odgovarajući tip kada je to moguće. npr. `int` $\Rightarrow$ `float` kada je funkcija specificira da prima `float`, a mi joj predamo `int` konstantu.
> ```c
> double exsp(float x, int n) {
>   ...
>   return rez;
> }
>
> int main(void) {
>     // 2 (int) -> 2 (float)
>     printf("%ld", exsp(2, 2));
> }
> ```


# Stack

Stog (engl. stack) osnovna je struktura tipa LIFO (Last In First Out).

Sve^[Sve varijable deklarirane prije pozivanja programa, one za koje se memorija alocira dinamički idu na heap] varijable unutar funkcije se spremaju na stog, kada se funkcija vrati pozivatelju sa stoga se skinu te varijable.

Stog je vrlo brz, ali ograničene veličine.


# Demo zadatak

Napraviti [Kaprkar's routine](https://en.wikipedia.org/wiki/Kaprekar's_routine) za unesen broj.


# Rekurzivne funkcije
Funkcija koja poziva samu sebe.

```c
void ispis(int n) {
  printf("%d\n", n);
  ispis(n - 1);

  return;
}
```
Ispisivat će
```c
n
n-1
n-2
```


## Računanje faktorijela

```c
size_t fact(size_t n) {
  if (n <= 1) return 1;

  return n*fact(n-1);
}
```

za `fact(5)` program će računati `5*fact(4)` pa onda `5*4*fact(3)` pa onda `5*4*3*fact(2)` i na kraju `5*4*3*2*1`


