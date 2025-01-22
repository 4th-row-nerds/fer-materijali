[← Natrag](../..)

# UPRO priprema za LV06

[Rješenja Zadataka](.)

**Važna napomena**: Kao rješenje zadatka **predaje se samo implementirana funkcija** koja ne smije sadržavati naredbe za ispis na standardni izlaz ili unos sa standardnog ulaza. Funkcija `main` i zaglavlja se **ne predaju**. Za razliku od ove pripreme, na stvarnoj laboratorijskoj vježbi nećete dobiti funkciju `main`.

# Zadatak 01
1. Potrebno je napisati funkciju **stddev** prototipa `void stddev(float *polje, int len, float *std_dev)` čiji je parametar `*polje` pokazivač na prvi član polja, `len` duljina jednodimenzijskog polja te `*std_dev` pokazivač na objekt u kojeg će biti upisan rezultat - standardna devijacij članova polja.

Funkcija treba za jednodimenzijsko polje, zadanog broja članova izračunati standardnu devijaciju te preko pokazivača vratiti njenu vrijednost.

2. Potrebno je napisati funkciju **IndexOfMaxdev** prototipa `int IndexOfMaxdev(float *polje, int row, int col)` čiji je parametar `*polje` pokazivač na prvi član matrice, `row` broj redaka matrice te `col` broj stupaca matrice. Funkcija treba uz korištenje prethodno navedene funkcije **stddev** vratiti indeks onog retka čiji članovi imaju najveću standardnu devijaciju. Ako više redaka ima jednaku vrijednost standardne devijacije, onda treba vratiti redak s manjim indeksom.

**Napomena** formula za standardnu devijaciju glasi:

$$\sigma = \sqrt{\frac{\sum_{i=1}^{n}(x_i - mean)^2}{n}}$$

U pozivajućoj razini je osigurana memorija za sva korištena polja.

Primjer pomoću kojeg možete testirati funkcije:

```c
    1  1   1
M = 2  3   4
    1 457 123

index = 2
```

```c
    1  1
M = 2  3
    3  2

index = 1
```

<details>
<summary><b>Glavni program možete preuzeti ovdje</b></summary>

```c
int main(void){
   float M[64];
   int m;
   int n;
   int index;
   scanf("%d", &n);
   scanf("%d", &m);
   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
         scanf("%f", M+i*m+j);
      }
   }


   index = IndexOfMaxdev(M, n, m);
   printf("%d", index);

}
```

</details>

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <math.h>

void stddev(float *polje, int len, float *std_dev) {

   // mean == aritmeticka sredina svih clanova polja
   float mean = 0;
   for (size_t i = 0; i < len; i++) {
      mean += polje[i];
   }
   mean /= (float)len;


   float suma_kvadrata = 0;
   for (size_t i = 0; i < len; i++) {
      suma_kvadrata += pow(polje[i] - mean, 2);
   }

   *std_dev = sqrt(suma_kvadrata/len);

   return;
}

int IndexOfMaxdev(float *polje, int row, int col) {

   float max_dev;
   int max_row = 0;
   stddev(polje, col, &max_dev);

   for (size_t i = 1; i < row; i++) {
      float curr_dev;
      stddev(&polje[i*col], col, &curr_dev);
      if (curr_dev > max_dev) {
      	max_row = i;
         max_dev = curr_dev;
      }
   }
   return max_row;
}
```

</details>


# Zadatak 02
Potrebno je napisati funkciju **transponiraj** prototipa `void transponiraj(int* src, int* dst, int n, int m)` čija su oba parametra pokazivači na prve članove polja objekata tipa `int`.

Funkcija treba članove polja na koje pokazuje prvi parametar premjestiti u polje na čiji prvi član pokazuje drugi parametar takvim redoslijedom da se na kraju dobije transponirana matrica.

U pozivajućoj razini je osigurana memorija za oba polja.

Primjeri pomoću kojih možete testirati funkcije:

```c
     1 2 3
 A = 4 5 6
     7 8 9

      1 4 7
A^T = 2 5 8
      3 6 9
```

```c
      2 3
 A =  5 6
      8 9

      2 5 8
A^T = 3 6 9
```

<details>
<summary><b>Glavni program možete preuzeti ovdje</b></summary>

```c
int main(void) {
   int a[64];
   int b[64];
   int n;
   int m;


   scanf("%d", &n);
   scanf("%d", &m);

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
         scanf("%d", a+i*m+j);
      }
   }
   transponiraj(a, b, n, m);

   for (int i = 0; i < n; i++) {
       for (int j = 0; j < m; j++) {
         printf("%d ", a[i*m+j]);
      }
      printf("\n");
   }
   printf("\n\n");
   for (int i = 0; i < m; i++) {
       for (int j = 0; j < n; j++) {
         printf("%d ", b[i*n+j]);
      }
      printf("\n");
   }
}
```

</details>

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>

void transponiraj(int* src, int* dst, int row, int col) {
   for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
         dst[j*col + i] = src[i*col + j];
      }
   }
}
```

</details>


# Zadatak 03
Potrebno je napisati funkciju **obrni** prototipa `void obrni (char *src, char *dst)` čija su oba parametara pokazivači na prvi član polja objekata tipa `char`.

Funkcija treba članove iz polja na koje pokazuje prvi parametar `obrnutim redoslijedom` premjestiti u polje na čiji prvi član pokazuje drugi parametar funkcije. \
U pozivajućoj razini je osigurana memorija za oba polja.

Primjeri pomoću kojih možete testirati funkcije:

```c
src = "a1c2e3g4"
dst = ""
// poziv funkcije obrni(src, dst);
src = "a1c2e3g4"
dst = "4g3e2c1a"
```

```c
src = "123"
dst = ""
// poziv funkcije obrni(src, dst);
src = "123"
dst = "321"
```


<details>
<summary><b>Glavni program možete preuzeti ovdje</b></summary>

```c
int main (void){
   char src[32], dst[32];

   scanf("%s", src);

   obrni(src, dst);

   printf("%s", dst);

   return 0;
}
```

</details>

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <string.h>

void obrni(char *src, char *dst) {
   for (size_t i = 0; i < strlen(src); i++) {
      // -1 je zbog \0 na kraju src niza
      dst[i] = src[strlen(src) - i - 1];
   }
   dst[strlen(src)] = '\0';
}
```

</details>


# Zadatak 04
Deklarirana je struktura

```c
struct person_s {
  int code;
  char name[128];
  float salary;
}
```

Napisati funkciju s prototipom

```c
void delCharFromName(struct person_s *s, char c);
```

koja iz polja name u strukturi na koju pokazuje s izbacuje sve pojave znaka `c`.

Primjeri izvršavanja:

Niz "mali Perica" uz znak 'a' mijenja se u "mli Peric".

Niz "ccc" uz znak 'c' mijenja se u "" (prazan niz).

Niz "FER" uz znak 'e' ostaje nepromijenjen.

<details>
<summary><b>Glavni program možete preuzeti ovdje</b></summary>

```c
#include <stdio.h>
// definicija funkcije delCharFromName
int main(void) {
    struct person_s s;
    char c;
    printf("Unesite niz > ");
    fgets(s.name, 128, stdin);
    printf("Unesite znak > ");
    scanf("%c", &c);
    // ovdje ugraditi poziv funkcije
    printf("%s", s.name);
    return 0;
}
```

</details>

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <string.h>

void delCharFromName(struct person_s *p, char c) {
   for (size_t i = 0; i < strlen(p->name); i++) {
      if (p->name[i] != c) continue;

      // Kopiraj sve znakove za jedno mjesto ulijevo pocevsi od tog c znaka
      for (size_t j = i - 1; i < strlen(p->name); j++) {
         p->name[j - 1] = p->name[j];
      }
   }
}
```

</details>


# Zadatak 05
Potrebno je napisati

1. funkciju **dot_produkt** prototipa `int dot_produkt (int *a, int *b, int n)` čiji su parametri `*a` i `*b` pokazivači na prve članove polja objekata tipa `int`, a parametar `n` broj članova u tim poljima. \
Funkcija treba preko imena vratiti skalarni produkt vektora `a` i `b`.

> Primjetite kako je ovo samo matrično množenje dva vektora

2. funkciju **mat_vec_produkt** prototipa `void mat_vec_produkt(int *X, int *a, int n, int *ret)` čiji su parametri
- `*X` pokazivač na prvi član kvadratne matrice `X`,
- `*a` pokazivač na vektor `a`,
- `n` broj stupaca i redaka matrice `X` odnosno broj elemenata vektora `a`,
- `*ret` pokazivač na polje pomoću kojeg funkcija vraća rezultat.

> Primjetite kako je ovo samo matrično množenje matrice `X` s vektorom `a`.

Polje `ret` nakon izvršavanja funkcije treba sadržavati rezultat množenja matrice `X` s vektorom `a`. Pri množenju je potrebno koristiti funkciju **dot_produkt**.

U pozivajućoj razini je osigurana memorija za sva korištena polja.

Primjer pomoću kojeg možete testirati funkcije:

```c
  X    *  a  = ret
1 2 3     2     5
4 5 6  *  0  =  14
7 8 9     1     23
```

```c
    X      *  a  = ret
0 0 0 0 1     5     1
0 0 0 1 0     4     2
0 0 1 0 0  *  3  =  3
0 1 0 0 0     2     4
1 0 0 0 0     1     5
```

<details>
<summary><b>Glavni program možete preuzeti ovdje</b></summary>

```c
#define MAX_DIM 32

int main (void){
    int X[MAX_DIM*MAX_DIM], a[MAX_DIM], n, rez[MAX_DIM], i;

   scanf("%d", &n);

   for(i=0; i < n*n; i++)
      scanf("%d", &X[i]);

   for(i=0; i < n; i++)
      scanf("%d", &a[i]);

   mat_vec_produkt(X, a, n, rez);

   for(i = 0; i < n; i++)
      printf("%d ", rez[i]);

   return 0;
}
```

</details>

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>

// Vektori a i b s n elemenata
int dot_produkt(int *a, int *b, int n) {

   int rez = 0;
   for (size_t i = 0; i < n; i++) {
      rez += a[i] * b[i];
   }

   return rez;
}

// X matrica množi vektor a i rezultat sprema u rez
void mat_vec_produkt(int *X, int *a, int n, int *ret) {

   for (size_t i = 0; i < n; i++) {
      // Retci u X množe stupce (jedan stupac) u a
      ret[i] = dot_produkt(&X[n*i], a, n);
   }
}
```

</details>


# Zadatak 06
Zadano je cjelobrojno dvodimenzijsko polje (matrica) dimenzija `rows` x `cols` gdje je `rows` broj redaka, a `cols` broj stupaca.

Potrebno je:

1. Napisati funkciju `zajednickiDjelitelj` prototipa `int zajednickiDjelitelj(int *matrica, int rows, int cols)` koja pronalazi element u dvodimenzijskom polju (matrici) s kojim su djeljivi svi elementi matrice. Ako takav element postoji onda funkcija **preko imena** vraća njegovu vrijednost, a ako ne postoji onda vraća `1`.
Funkcija **zajednickiDjelitelj** kao parametre prima redom:

- pokazivač na prvi član dvodimenzijskog polja (matrice),
- broj redaka `rows`,
- broj stupaca `cols`.

2. Napisati funkciju podijeli prototipa `void podijeli(int *matrica, int rows, int cols, int *rezultat)` koja u zadano odredišno dvodimenzijsko polje upisuje članove **izvorišnog** dvodimenzijskog polja podijeljene s vrijednosti funkcije **zajednickiDjelitelj** pozvane nad **izvorišnim** poljem.
Funkcija **podijeli** kao parametre prima redom:

- pokazivač na prvi član **izvorišnog** dvodimenzijskog polja (matrice),
- broj redaka `rows`,
- broj stupaca `cols`,
- pokazivač na prvi član **odredišnog** dvodimenzijskog polja (matrice).

**Napomena**: Funkcija **ne smije** izmijeniti ulaznu matricu.

Primjeri izvršavanja:

```c
Unesite·rows·i·cols·>·3·3↵
Unesite·clanove·matrice·>·1·2·3·4·5·6·7·8·9↵
Zajednicki·djelitelj:·1↵
Rezultat·funkcije·podijeli:↵
1·2·3↵
4·5·6↵
7·8·9↵
```

```c
Unesite·rows·i·cols·>·2·3↵
Unesite·clanove·matrice·>·10·4·6·2·16·10↵
Zajednicki·djelitelj:·2↵
Rezultat·funkcije·podijeli:↵
5·2·3↵
1·8·5↵
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <stdbool.h>

int zajednickiDjelitelj(int *matrica, int rows, int cols) {

   int max_djelj = 1;

   // Prolazimo kroz sve elemente matrice
   for (size_t i = 0; i < rows*cols; i++) {

      /* Ako je trenutni broj manji od već provjerenog maksimalnog djelitelja,
       * nema smilsa provjeravati ako je djelitelj jer neće biti veći od posojećeg.
       */
      if (matrica[i] < max_djelj) continue;

      // Provjeravamo ako je zajednicki djelitelj sa svim ostalim elementima
      // Pretpostavljamo da je djelitelj svih
      bool is_djelitelj = true;
      for (size_t j = 0; j < rows*cols; j++) {
         if (matrica[j] % matrica[i] != 0) {
            is_djelitelj = false;
            break;
         }
      }

      if (is_djelitelj && matrica[i] > max_djelj) {
         max_djelj = matrica[i];
      }
   }

   return max_djelj;
}


void podijeli(int *mat, int rows, int cols, int *rez) {
   int max_djelj = zajednickiDjelitelj(mat, rows, cols);
   for (size_t i = 0; i < rows*cols; i++) {
      rez[i] = mat[i] / max_djelj;
   }
}
```

</details>


# Zadatak 07
Napisati funkciju `prebrojiPojave` tipa `void` koja kao parametre prima:

- pokazivač na objekt tipa `char` koji pokazuje na početak znakovnog niza
- objekt tipa `char`
- pokazivač na objekt tipa `int` u koji je potrebno upisati rezultat funkcije

Funkcija treba odrediti broj pojava slova, brojke ili drugog znaka (npr. `!` ili `#`) primljenih preko drugog parametra (tipa `char`) u nizu na čiji početak pokazuje pokazivač primljen preko prvog parametra. Pritom je funkcija **case-insensitive** - pri brojanju se **velika i mala slova tretiraju isto**. Rezultat treba vratiti u glavni program preko pokazivača na objekt tipa `int` primljenog preko trećeg parametra.

Ispravnost argumenata ne treba provjeravati, tj. pretpostavite da će uvijek biti zadani valjani pokazivači na traženi tip te ispravni znakovi (`char`).

Primjeri izvršavanja:

```c
Ucitaj·znakovni·niz·>·Doobar·Dan↵
Ucitaj·trazeni·znak·>·o↵
Broj·pojavljivanja·>·2 ↵
```

```c
Ucitaj·znakovni·niz·>·AnaVoliMilovana↵
Ucitaj·trazeni·znak·>·a↵
Broj·pojavljivanja·>·4↵
```

```c
Ucitaj·znakovni·niz·>·AnaVoliMilovana↵
Ucitaj·trazeni·znak·>·A↵
Broj·pojavljivanja·>·4↵
```

```c
Ucitaj·znakovni·niz·>·p·e·r·o...123↵
Ucitaj·trazeni·znak·>·2↵
Broj·pojavljivanja·>·1↵
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void prebrojiPojave(char *niz, char objekt, int *rezultat) {

   objekt = toupper(objekt); // Pretvara malo slovo u veliko

   *rezultat = 0;
   for (size_t i = 0; i < strlen(niz); i++) {
      niz[i] = toupper(niz[i]);
      if (niz[i] == objekt) *rezultat += 1;
   }
}
```

</details>

# Zadatak 08
Napisati funkciju `duplicirajSamoglasnike` prototipa: `void duplicirajSamoglasnike(char *ulaz, char *izlaz)`

Funkcija treba duplicirati svako pojavljivanje samoglasnika u nizu znakova na čiji prvi član pokazuje prvi parametar funkcije (parametar ulaz) te taj niz s dupliciranim samoglasnicima zapisati u znakovni niz na čiji prvi član pokazuje drugi parametar funkcije (parametar izlaz).

Primjeri izvršavanja:

```c
Upisite·niz·>·abc↵
Rezultat:·aabc
```

```c
Upisite·niz·>·Ananas↵
Rezultat:·AAnaanaas
```

```c
Upisite·niz·>·primjer123↵
Rezultat:·priimjeer123
```
<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <string.h>

void duplicirajSamoglasnike(char *ulaz, char *izlaz) {

   int offset = 0;
   for (size_t i = 0; i < strlen(ulaz); i++) {
      izlaz[i + offset] = ulaz[i];

      char c = ulaz[i] & ~32; // Prebacivanje slova u veliko

      if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
          offset++;
          izlaz[i + offset] = ulaz[i];
      }
   }
}
```

</details>
