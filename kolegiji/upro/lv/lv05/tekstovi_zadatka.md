[← Natrag](../..)

# UPRO priprema za LV05

[Rješenja Zadataka](.)

# Zadatak 01
Napisati **funkciju** naziva `sumaPotencija`, tipa `void`, koja kao parametre prima **redom**:

- tri parametra tipa `int` (parametri `a`, `b` i `c`)
- jedan parametar tipa `int` (parametar `n`)
- jedan pokazivač na objekt tipa `int` (parametar `rez1`)
- jedan pokazivač na objekt tipa `int` (parametar `rez2`)

Funkcija treba:

- izračunati **sumu `n`-tih potencija** vrijednosti parametara `a`, `b` i `c` te rezultat vratiti preko pokazivača `rez1`
- izračunati **`n`-tu potenciju sume** vrijednosti parametara `a`, `b` i `c` te rezultat vratiti preko pokazivača `rez2`

Funkcija ne smije ništa ispisivati. Pretpostavite da parametar n nikada neće biti manji od nule i da će parametri a, b, c uvijek biti pozitivni brojevi.

**Primjer 1**: Za `a` = 1, `b` = 2, `c` = 3, `n` = 2 u trenutku izlaska iz funkcije, `rez1` treba pokazivati na objekt čija je vrijednost 14, a `rez2` treba pokazivati na objekt čija je vrijednost 36.

**Primjer 2**: Za `a` = 2, `b` = 4, `c` = 1, `n` = 3 u trenutku izlaska iz funkcije, `rez1` treba pokazivati na objekt čija je vrijednost 73, a `rez2` treba pokazivati na objekt čija je vrijednost 343.

<details>
<summary>Rješenje zadatka</summary>

```c
#include <math.h>

void sumaPotencija(int a, int b, int c, int n, int *rez1, int *rez2) {

   *rez1 = pow(a, n) + pow(b, n) + pow(c, n);
   *rez2 = pow(a + b + c, n);
}
```

</details>


# Zadatak 02
Napisati funkciju **BrojSlovaZnamenaka** (tipa `void`) koja kao parametre prima:

- niz znakova (string) imena `niz` maksimalne duljine od 100 znakova
- jedan **pokazivač** tipa `int` (parametar `brojSlova`) s vrijednosti `0`
- jedan **pokazivač** tipa `int` (parametar `brojZnamenaka`) s vrijednosti `0`

Funkcija treba:

- odrediti koliko ima slova u nizu znakova niz te vratiti rješenje koristeći **pokazivač** brojSlova
- odrediti koliko ima znamenaka u nizu znakova niz te vratiti rješenje koristeći **pokazivač** brojZnamenaka

Funkcija ne smije ništa ispisivati.

Primjeri pomoću kojih možete testirati funkciju:

```c
Unesite·niz·znakova·>·abcdef123↵
6·3
```

```c
Unesite·niz·znakova·>·ab1↵
2·1
```

```c
Unesite·niz·znakova·>·OvoJeUlazniNizS15Slova↵
20·2
```

> Napomena: Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>

void BrojSlovaZnamenaka(char *niz, int *brojSlova, int *brojZnamenaka) {

    *brojZnamenaka = 0;
    *brojSlova = 0;
    for(int i = 0; *(niz + i) != '\0'; i++) {
        if(*(niz + i) >= 'a' && *(niz + i) <= 'z') {
            *brojSlova += 1;
        }
        else if(*(niz + i) >= 'A' && *(niz + i) <= 'Z') {
            *brojSlova += 1;
        }
        else if(*(niz + i) >= '0' && *(niz + i) <= '9') {
            *brojZnamenaka += 1;
        }
    }

    return;
}
```

</details>


# Zadatak 03
Napisati funkciju **getMinMax** tipa `void` koja prima:

- pokazivač na jednodimenzionalno polje cjelobrojnih elemenata
- veličinu cjelobrojnog polja
- dva pokazivača na objekte tipa `int` (pokazivač na minimalnu vrijednost i pokazivač na maksimalnu vrijednost jednodimenzionalnog polja).

Funkcija treba naći najmanjeg i najvećeg člana ulaznog polja. Polje neće biti veće od 100 članova. Ne treba provjeravati ispravnost unosa. Funkcija ne smije ništa ispisvati. Pogledajte primjere za dodatna pojašnjenja.

Primjeri pomoću kojih možete testirati funkcije:

```c
Unesite·velicinu·polja:·10↵
Unesite·10·elemenata·u·polju:·-1·0·100·4·9·18·94·-35·10·20↵
Najmanji·element·u·polju:·-35↵
Najveci·element·u·polju:·100↵
```

```c
Unesite·velicinu·polja:·5↵
Unesite·5·elemenata·u·polju:·-5·255·98·32·0↵
Najmanji·element·u·polju:·-5↵
Najveci·element·u·polju:·255↵
```

```c
Unesite·velicinu·polja:·8↵
Unesite·8·elemenata·u·polju:·1·2·3·4·5·6·7·8↵
Najmanji·element·u·polju:·1↵
Najveci·element·u·polju:·8↵
```

> Napomena: potrebno je napisati samo traženu funkciju, main() funkciju nije potrebno pisati

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>

void getMinMax(int *polje, size_t len, int *min, int *max) {

   *min = polje[0];
   *max = polje[0];
   for (size_t i = 0; i < len; i++) {
      if (polje[i] > *max) *max = polje[i];
      if (polje[i] < *min) *min = polje[i];
   }
}
```

</details>


# Zadatak 04
Napisati funkciju za uvećanje osnovne plaće za iznos bonusa te istu konvertira u EUR sukladno fiksnom tečaju **7.53450**. Program se treba koristiti funkcijom **PovecajKonvertiraj** (tipa `int`) koja kao parametre prima:

- **pokazivač** na iznos osnovne plaće (u kunama) tipa `float` koji se koristi za izračun i vraćanje vrijednosti uvećane i konvertirane (u EUR) plaće,
- iznos bonusa (u kunama) tipa `int` za koji se osnovna plaća uvećava,
- **pokazivač** na postotak uvećanja plaće

Funkcija vraća vrijednost 1 ukoliko je povećanje značajno (veće ili jednako 10%) te prikazuje poruku: `OBAVIJESTITI POREZNU!`. U protivnom funkcija vraća vrijednost 0.

Funkcija ne smije ništa ispisivati. Ne treba provjeravati ispravnost unosa.

Primjeri za testiranje funkcije:

```c
Unesite·iznos·place:10000.00↵
Unesite·iznos·bonusa:555↵
Uvecana·placa:·1400.89·EUR·te·je·uvecanje·5.55·%↵
```

```c
Unesite·iznos·place:10000.00↵
Unesite·iznos·bonusa:1000↵
Uvecana·placa:·1459.95·EUR·te·je·uvecanje·10.00·%↵
OBAVIJESTITI·POREZNU!↵
```

```c
Unesite·iznos·place:8896.56↵
Unesite·iznos·bonusa:8896.56↵
Uvecana·placa:·2361.48·EUR·te·je·uvecanje·99.99%↵
OBAVIJESTITI·POREZNU!↵
```

> Napomena: potrebno je napisati samo traženu funkciju. main() funkciju nije potrebno pisati

<details>
<summary>Rješenje zadatka</summary>

```c
int PovecajKonvertiraj(float *placa, const float bonus, float *postotak) {

   float kn = *placa;
   *placa += bonus;
   *placa /= 7.5345f;

   *postotak = (bonus / kn)*100;

   if (*postotak >= 10) {
      return 1;
   }

   return 0;
}
```

</details>


# Zadatak 05 (nedovrsen)


1. Napisati funkciju `ProvjeriPravokutnik` tipa `int` koja će provjeriti jesu li nasuprotni vrhovi pravokutnika valjani (jesu li duljine stranica pravokutnika `> 0`).

1. Napisati funkciju `IzracunajDuljinuStranice` tipa `int` koja treba izračunati duljinu stranice koristeći dvije točke na jednoj osi.

1. Napisati funkciju `IzracunajOpseg` tipa `int` koja treba izračunati opseg pravokutnika.

1. Napisati funkciju `IzracunajPovrsinu` tipa `int` koja treba izračunati površinu pravokutnika.

1. Napisati funkciju `IzracunajOpsegPovrsinu` tipa `void` čiji su parametri:

    - pokazivač tipa `int` (parametar `opseg`)

    - pokazivač tipa `int` (parametar `povrsina`)

Funkcija treba:

- učitati dva nasuprotna vrha s tipkovnice (pogledajte u primjerima način učitavanja)
  - prije učitavanja prve točke potrebno je ispisati: `Unesite·koordinate·za·tocku·1·>·`
  - prije učitavanja druge točke potrebno je ispisati: `Unesite·koordinate·za·tocku·2·>·`

- koristeći funkciju `ProvjeriPravokutnik` provjeriti valjanost pravokutnika s obzirom na zadane nasuprotne vrhove
  - ukoliko pravokutnik nije valjan, koristeći pokazivače `opseg` i `povrsina`, vratiti vrijednosti `-1` (pogledajte u primjerima)

- koristeći funkciju `IzracunajDuljinuStranice` izračunati duljinu stranica `a` i `b`

- koristeći funkciju `IzracunajOpseg` izračunati opseg pravokutnika

- koristeći funkciju `IzracunajPovrsinu` izračunati površinu pravokutnika

- koristeći pokazivač `opseg` potrebno je vratiti izračunatu vrijednost za opseg pravokutnika

- koristeći pokazivač `površina` potrebno je vratiti izračunatu vrijednost za površinu pravokutnika

Primjeri pomoću kojih možete testirati funkciju:

```c
Unesite·koordinate·za·tocku·1·>·0·0↵
Unesite·koordinate·za·tocku·2·>·2·2↵
8·4
```

```c
Unesite·koordinate·za·tocku·1·>·0·0↵
Unesite·koordinate·za·tocku·2·>·0·0↵
-1·-1
```

```c
Unesite·koordinate·za·tocku·1·>·1·3↵
Unesite·koordinate·za·tocku·2·>·2·9↵
14·6
```

> Napomena: Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).

<details>
<summary>Rješenje zadatka</summary>

```c
// TODO: napraviti zadatak
```

</details>


# Zadatak 06
Napisati funkciju naziva **PomicniProsjek** tipa `void` koja kao parametre prima:

- pokazivač na niz tipa `double` (parametar `ulaz`) koji predstavlja ulazni niz,
- pokazivač na niz tipa `double` (parametar `izlaz`) u kojem se spremaju rezultati filtriranja,
- pokazivač na `int` (parametar `n`) koji označava broj elemenata ulaznog niza,
- pokazivač na `int` (parametar `prozor`) koji označava veličinu prozora filtra.

Pomični prosjek se računa prema formuli:

$$SMA_k=\frac{1}{k}\sum_{i=n-k+1}^{n}p_i\quad$$

Napisati glavni program koji:

- Učitava ulazni niz i veličinu prozora k od korisnika.
- Poziva funkciju PomicniProsjek za izračun pomičnog prosjeka.
- Ispisuje ulazni niz i filtrirani niz s točno dvije decimale.

Primjeri izrvšavanja programa:

```c
Unesite·broj·elemenata·ulaznog·niza:·4↵
Unesite·elemente·ulaznog·niza:↵
1·2·3·4↵
Unesite·velicinu·prozora:·4↵
Ulazni·niz:·1.00·2.00·3.00·4.00↵
Filtrirani·niz:·1.00·1.50·2.00·2.50↵
```

```c
Unesite·broj·elemenata·ulaznog·niza:·6↵
Unesite·elemente·ulaznog·niza:↵
10·20·30·40·50·60↵
Unesite·velicinu·prozora:·3↵
Ulazni·niz:·10.00·20.00·30.00·40.00·50.00·60.00↵
Filtrirani·niz:·10.00·15.00·20.00·30.00·40.00·50.00↵
```

```c
Unesite·broj·elemenata·ulaznog·niza:·5↵
Unesite·elemente·ulaznog·niza:↵
5·10·15·20·25↵
Unesite·velicinu·prozora:·2↵
Ulazni·niz:·5.00·10.00·15.00·20.00·25.00↵
Filtrirani·niz:·5.00·7.50·12.50·17.50·22.50↵
```

> Napomena: Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).


<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>

void PomicniProsjek(double const *ulaz, double *izlaz, const size_t len, int prozor) {

    for (size_t i = 0; i < len; i++) {
        double sum = 0;
        size_t koristen_prozor = 0;
        for (size_t j = 0; j < prozor; j++) {
            if (i >= j) {
                sum += ulaz[i - j];
                koristen_prozor++;
            }
        }
        double SMAk = sum / (double)koristen_prozor;
        izlaz[i] = SMAk;
    }
}

int main(void) {

    printf("Unesite broj elemenata ulaznog niza: \n");
    size_t len;
    scanf("%zu", &len);

    double ulaz[len];
    double izlaz[len];
    printf("Unesite elemente ulaznog niza:\n");
    for (size_t i = 0; i < len; i++) {
        scanf("%lf", &ulaz[i]);
    }

    printf("Unesite velicinu prozora: \n");
    int k;
    scanf("%d", &k);

    PomicniProsjek(ulaz, izlaz, len, k);

    printf("Ulazni niz:");
    for (size_t i = 0; i < len; i++) {
        printf(" %.2lf", ulaz[i]);
    }
    printf("\nFiltrirani niz:");
    for (size_t i = 0; i < len; i++) {
        printf(" %.2lf", izlaz[i]);
    }
    printf("\n");

    return 0;
}
```

</details>


# Zadatak 07
Napisati funkciju naziva **ProvjeriLozinku** tipa `int` koja kao parametre prima:

- parametar tipa `char` (parametar `password`)
- tri pokazivača tipa `int` (parametri `brVelikih`, `brBrojeva`, `brSpec`) Funkcija prebrojava koliko u upisanoj lozinci ima velikih slova, brojeva te specijalnih znakova. Radi jednostavnosti pretpostavite da se od specijalnih znakova mogu pojaviti samo **!?\*\#**. Funkcija preko vrijednosti treba vratiti broj znakova u zadanoj lozinci.

Napisati glavni program koji s tipkovnice učitava lozinku (maksimalne duljine 10 znakova), te ispisuje je li lozinka ispravna. Lozinka je ispravna ukoliko:

- sadrži točno 10 znakova
- sadrži barem 2 velika slova
- sadrži barem 2 broja
- sadrži barem 1 specijalni znak

Ukoliko lozinka nije ispravna, ispisuje koji zahtjev nije zadovoljen.
 - Ukoliko sadrži manje od 10 znakova potrebno je ispisati `Lozinka·je·prekratka!↵`
 - Ukoliko nije prekratka, potrebno je ispisati sve što nedostaje redosljedom: velika slova, brojevi, specijalni znakovi.

Primjeri izvršavanja programa:

```c
Upisite·lozinku·>·1LozinkA9?↵
Lozinka·je·ispravna!↵
```

```c
Upisite·lozinku·>·Lozinka↵
Lozinka·je·prekratka!↵
```

```c
Upisite·lozinku·>·#Dobarpass↵
Nema·dovoljno·velikih·slova!↵
Nema·dovoljno·brojeva!↵
```

```c
Upisite·lozinku·>·ovolospass↵
Nema·dovoljno·velikih·slova!↵
Nema·dovoljno·brojeva!↵
Nema·dovoljno·specijalnih·znakova!↵
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

size_t provjeri_lozinku(char *pass, int *brVelikih, int *brBrojeva, int *brSpec) {

   size_t len = strlen(pass);

   *brVelikih = 0;
   *brBrojeva = 0;
   *brSpec = 0;

    for (size_t i = 0; i < len; i++) {
        if (pass[i] >= 'A' && pass[i] <= 'Z') {
            *brVelikih += 1;
        } else if (pass[i] >= '0' && pass[i] <= '9') {
            *brBrojeva += 1;
        } else if (pass[i] == '!' || pass[i] == '?'
                || pass [i] == '*' || pass[i] == '#') {
            *brSpec += 1;
      }
    }

   return len;
}

int main(void) {

   printf("Upisite lozinku > \n");
   char pass[21] = {0};
   fgets(pass, 20, stdin);

   int brVelikih, brBrojeva, brSpec;
   size_t len = provjeri_lozinku(pass, &brVelikih, &brBrojeva, &brSpec);

   if (len == 10 && brVelikih >= 2 && brBrojeva >= 2 && brSpec >= 1) {
   	printf("Lozinka je ispravna!");
   }

   if(len != 10) {
      printf("Lozinka je prekratka!");
   } else {
      if (brVelikih < 2) printf("Nema dovoljno velikih slova!\n");
      if (brBrojeva < 2) printf("Nema dovoljno brojeva!\n");
      if (brSpec < 1) printf("Nema dovoljno specijalnih znakova!\n");
   }

   return 0;
}
```

</details>


# Zadatak 08
Napisati funkciju naziva **najmanjiElement** tipa `int` koja kao parametre prima:

- niz tipa `int`
- broj elemenata niza tipa `int` (parametar `n`)
- pokazivač na objekt tipa `int` (parametar `koliko`), broj najmanjih elemenata niza

Funkcija računa najmanji element niza te broj njegovih ponavljanja u nizu. Funkcija preko povratne vrijednosti treba vratiti vrijednost najmanjeg elementa niza, a preko ulaznog parametra `koliko` broj njegovih ponavljanja.

Napisati glavni program koji s tipkovnice učitava broj elemenata niza te potom i elemente niza te poziva funkciju **najmanjiElement** i ispisuje njezine rezultate prema predlošku niže.

**Funkcija ne smije ništa ispisivati.**

Primjeri izvršavanja programa:

```c
Unesi·velicinu·niza·>·3↵
Unesi·elemente·niza·>·5·-1·2↵
Najmanji·element·-1·s·1·ponavljanja.
```

```c
Unesi·velicinu·niza·>·4↵
Unesi·elemente·niza·>·1·5·2·1↵
Najmanji·element·1·s·2·ponavljanja.
```

```c
Unesi·velicinu·niza·>·5↵
Unesi·elemente·niza·>·0·8·1·0·13↵
Najmanji·element·0·s·2·ponavljanja.
```

> Napomena: Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdlib.h>
#include <stdio.h>

int najmanjiElement(int *polje, size_t len, size_t *koliko) {

    int min = polje[0];
    *koliko = 0;

    for (size_t i = 0; i < len; i++) {
        if (min > polje[i]) {
            min = polje[i];
            *koliko = 1;
        } else if (min == polje[i]) {
            *koliko += 1;
        }
    }

   return min;
}

int main(void) {

    printf("Unesi velicinu niza > \n");
    size_t len;
    scanf("%zu", &len);

    int polje[len];
    printf("Unesi elemente niza > \n");
    for (size_t i = 0; i < len; i++) {
        scanf("%d", &polje[i]);
    }

    size_t koliko;
    int el = najmanjiElement(polje, len, &koliko);
    printf("Najmanji element %d s %zu ponavljanja.", el, koliko);
    return 0;
}
```

</details>


# Zadatak 09
Napisati funkciju naziva **IzracunajRezultantu** tipa `void`, koja kao parametre prima:

- dva pokazivača tipa `float`, (parametri `sila1` i `sila2`), koji predstavljaju veličine dviju sila u Newtonima,
- jedan pokazivač tipa `float` (parametar `kut`), koji predstavlja kut između sila u stupnjevima,
- jedan pokazivač tipa `float` (parametar `rezultanta`), koji će spremiti izračunatu rezultantnu silu.

Funkcija računa rezultantnu silu prema formuli:

$$F_R=\sqrt{F_1^2+F_2^2+2 \cdot F_1 \cdot F_2 \cdot \cos(\theta)}$$

> [!npr] Tip
> $\cos(\phi)$ u `math.h` uzima ulazni kut $\phi$ u radijanima

Napisati glavni program koji:

- s tipkovnice učitava veličine sila te kut između njih
- poziva funkciju `IzracunajRezultantu`
- ispisuje izračunatu rezultantnu silu za unesene vrijednosti s točno dvije decimale.

Primjeri izrvšavanja programa:

```c
Unesite·prvu·silu·(u·Newtonima):·10↵
Unesite·drugu·silu·(u·Newtonima):·15↵
Unesite·kut·između·sila·(u·stupnjevima):·90↵
Rezultanta·sila·iznosi:·18.03·N↵
```

```c
Unesite·prvu·silu·(u·Newtonima):·25↵
Unesite·drugu·silu·(u·Newtonima):·25↵
Unesite·kut·između·sila·(u·stupnjevima):·0↵
Rezultanta·sila·iznosi:·50.00·N↵
```

```c
Unesite·prvu·silu·(u·Newtonima):·40↵
Unesite·drugu·silu·(u·Newtonima):·10↵
Unesite·kut·između·sila·(u·stupnjevima):·180↵
Rezultanta·sila·iznosi:·30.00·N↵
```

> Napomena: Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).

<details>
<summary>Rješenje zadatka</summary>

```c
#include <math.h>
#include <stdio.h>

#define PI 3.1415926

void IzracunajRezultantu(const float *sila1, const float *sila2, const float *kut_deg, float *rez) {

    const float kud_rad = *kut_deg / 180 * PI;
    const float f1 = *sila1, f2 = *sila2;

    *rez = sqrt(f1*f1 + f2*f2 + 2*f1*f2*cos(kud_rad));
}

int main(void) {

    printf("Unesite prvu silu (u Newtonima): \n");
    float f1;
    scanf("%f", &f1);

    printf("Unesite drugu silu (u Newtonima): \n");
    float f2;
    scanf("%f", &f2);

    printf("Unesite kut između sila (u stupnjevima): \n");
    float kut_deg;
    scanf("%f", &kut_deg);

    float rez;
    IzracunajRezultantu(&f1, &f2, &kut_deg, &rez);
    printf("Rezultanta sila iznosi: %.2f N\n", rez);
}
```

</details>


# Zadatak 10
Napisati funkciju naziva **Ekstrem** tipa `_Bool`, koja učitava koeficijente kvadratne funkcije (počevši od najveće potencije). Funkcija treba odrediti koordinate (x,y) ekstrema kvadratne funkcije preko pokazivača. Funkcija prima:

- dva pokazivača na objekt tipa `float` (parametar `x` i parametar `y`)

Funkcija preko vrijednosti treba vratiti:

- `1` - ukoliko je ekstrem minimum funkcije
- `0` - ukoliko je ekstrem maksimum funkcije

Napisati glavni program koji ispisuje vrstu ekstrema te određene koordinate. Primjeri izvršavanja programa:

```c
Upisite·koeficijente·kvadratne·funkcije·>·1·-5·6↵
Funkcija·ima·minimum·u·(2.50,·-0.25)↵
```

```c
Upisite·koeficijente·kvadratne·funkcije·>·-1·0·0↵
Funkcija·ima·maksimum·u·(0.00,·0.00)↵
```

```c
Upisite·koeficijente·kvadratne·funkcije·>·-1·5·-6↵
Funkcija·ima·maksimum·u·(2.50,·0.25)
```

> Napomena: Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).


<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    EXTREM_MAX = false,
    EXTREM_MIN = true,
} ekstrem_type_t;

bool Ekstrem(float a, float b, float c, float *x, float *y) {

    *x = -b / (2*a); // x koordinata tjemena parabole
    *y = (4*a*c - b*b) / (4*a); // y koordinata tjemena parabole

    if (b == 0) *x = 0; // pobrine se da ne ostane -0.000 u x
    if (c == 0 && b == 0) *y = 0; // pobrine se da ne ostane -0.000 u y

    if (a > 0) { // Odredi ima li funkcija minimum ili maksimum s obzirom na a
        return EXTREM_MIN;
    } else {
        return EXTREM_MAX;
    }
}

int main(void) {

    printf("Upisite koeficijente kvadratne funkcije > \n");
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);

    float x, y;
    if (Ekstrem(a, b, c, &x, &y) == EXTREM_MIN) {
        printf("Funkcija ima minimum u (%.2f, %.2f)", x, y);
    } else {
        printf("Funkcija ima maksimum u (%.2f, %.2f)", x, y);
    }

    return 0;
}
```

</details>


# Zadatak 11
Napisati funkciju naziva **anagram** tipa `_Bool` koja kao parametre prima:

- dva parametra tipa niz znakova (string) (parametri `s1` i `s2`), dvije ulazne riječi
- pokazivač na objekt tipa `int` (parametar `isti`), brojač podudarajućih znakova

Funkcija provjerava jesu li dvije zadane riječi anagrami. Anagram je lingvistička igra ili fenomen u kojem se preuređivanjem slova jedne riječi ili fraze dobiva nova riječ ili fraza, pri čemu se koriste sva originalna slova bez dodavanja ili izostavljanja (npr. trava-vrata-vatra).

Funkcija preko vrijednosti treba vratiti:

- `1` - ukoliko su ulazne riječi anagrami
- `0` - ukoliko ulazne riječi nisu anagrami

Funkcija također preko ulaznog parametra `isti` vraća broj znakova u kojima se dvije riječi podudaraju.

Napisati glavni program koji s tipkovnice učitava dvije riječi (svaka maksimalne duljine 20 znakova), te ispisuje jesu li riječi anagrami te u koliko se znakova podudaraju. Funkcija treba biti case-sensitive (znakovi 'a' i 'A' nisu podudarajući znakovi).

**Funkcija ne smije ništa ispisivati.**

Primjeri izvršavanja programa:

```c
Unesi·dvije·rijeci·>·trava·vatra↵
Anagrami.↵
Broj·podudaranja:·5
```

```c
Unesi·dvije·rijeci·>·cat·Act↵
Nisu·anagrami.↵
Broj·podudaranja:·2
```

```c
Unesi·dvije·rijeci·>·peach·cheap↵
Anagrami.↵
Broj·podudaranja:·5
```

<details>
<summary>Rješenje zadatka</summary>

```c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FREQ_LEN 256
#define min(x, y) ((x) < (y) ? (x) : (y))

bool anagram(char *s1, char *s2, size_t *istih_ch) {

    // Broj pojavljivanja slova u nizovima s1 i s2 za svako slovo u ASCII-u
    size_t f_s1[FREQ_LEN] = {0};
    size_t f_s2[FREQ_LEN] = {0};

    // Prebrojavanje znakova za s1
    for (size_t i = 0; i < strlen(s1); i++) {
        // Element s indeksom istim kao i trenutni znak povecavamo, time prebrojavamo pojavljivanje tog znaka
        f_s1[(size_t)s1[i]] += 1;
    }

    // Prebrojavanje znakova za s2
    for (size_t i = 0; i < strlen(s2); i++) {
        // Element s indeksom istim kao i trenutni znak povecavamo, time prebrojavamo pojavljivanje tog znaka
        f_s2[(size_t)s2[i]] += 1;
    }

    *istih_ch = 0;
    for (size_t i = 0; i < FREQ_LEN; i++) {
        // Ima onoliko istih znakova koliko ima znakova u onom nizu koji ih ima manje
        *istih_ch += min(f_s1[i], f_s2[i]);
    }

    if (*istih_ch == strlen(s1)) return true;
    else return false;
}

int main(void) {

    printf("Unesi dvije rijeci > \n");
    char s1[24], s2[24];
    scanf("%s %s", s1, s2);

    size_t istih_ch;
    if (anagram(s1, s2, &istih_ch)) {
        printf("Anagrami.\n");
    } else {
        printf("Nisu anagrami.\n");
    }
    printf("Broj podudaranja: %zu", istih_ch);
    return 0;
}
```

</details>
