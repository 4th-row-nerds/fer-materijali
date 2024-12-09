[← Natrag](..)

# Operatori
Za neke operacije se koristi isti simbol.
Tada se koristi kontekst:
```c
 int a = 3, b, c;
 b = a - 5;
 c = -a;
```
Unarni i binarni minus rade različite operacije, a kompajler ih
razlikuje po kontekstu (broju operatora, prefix, sufix, ...)

## Bitovni operatori
Pristupamo do pojedinog bita ili grupe bitova
 - Koristi se za programiranje na niskoj razini

npr. kako pohraniti 32 logičke vrijednosti uz najmanji mogući trošak prostora?

```c
bool podaci[32];
podaci[0] = true;
podaci[1] = false;
...
```
Ovo rješenje troši 32 bita za svaki podatak.


Drugo rješenje je:

```c
char podaci[32];
podaci[0] = 1;
podaci[1] = 0;
...
```
Ovo rješenje troši 8 bita za svaki podatak, ali zbog načina na koji procesor sprema vrijednosti uglavnom će to i dalje biti 32bita.


Najbolje rješenje je:

```c
unsigned int podaci = 0xA0532468;
...
```
Ovo rješenje troši 1 bit za svaki podatak.

Problem je njima sada pristupiti. $\Rightarrow$ bitovni operatori


### AND
```c
int a = 3, b = 7, c;
c = a && b; // c = 3
...
```

### OR
```c
int a = 3, b = 7, c;
c = a || b; // c = 7
...
```

### XOR
```c
int a = 3, b = 7, c;
c = a ^ b; // c = 4
...
```

### NOT
```c
int a = 2, c;
c = ~a; // c = 5
...
```

## Pomak bitova (bit shift)
Pomiče bitove varijable u lijevo ili desno za dani broj bitova.
```c
int a = 0b0001, c; // a = 1
c = a << 1; // c = 2 tj. 0b0010
```

```c
unsigned int a = 0b0100, c; // a = 4
c = a >> 1; // c = 2 tj. 0b0010
```

Ako se bitovi pomaknu van duljine tipa podatka, oni se brišu.

## Postavljanje pojedinačnog bita

Postavljanje bita `br_bita` u jedinicu:
```c
a = a | (0x1 << br_bita);
```

Postavljanje bita `br_bita` u nulu:
```c
a = a & ~(0x1 << br_bita);
```

## Postavljanje pojedinačnog bita

Čitanje bita `br_bita`:
```c
printf("%d", a >> br_bita & 0x1);
```

<br>

## Operatori uvećanja i umanjena za 1
 - Ovi operatori imaju posljedice

### Prefiksni
 - ++a $\Rightarrow$ uvećava varijablu za 1 i onda koristi tu vrijednost u izrazu
 - --a $\Rightarrow$ umanjuje varijablu za 1 i onda koristi tu vrijednost u izrazu

```c
int a = 5, b = 10, c;
c = ++a * b; // c = 60, a = 6
```

### Postfiksni
 - a++ $\Rightarrow$ koristi njenu vrijednost u izrazu i onda uvećava varijablu za 1
 - a-- $\Rightarrow$ koristi njenu vrijednost u izrazu i onda umanjuje varijablu za 1

```c
int a = 5, b = 10, c;
c = a++ * b; // c = 50, a = 6
```

## Ternarni operator
```c
rezultat = izraz ? ako_true : ako_false;
```
`rezultat` će biti vrijednost `ako_true` samo kada je izraz istinit, a inače će biti `ako_false`.

Kod:
```c
if (x >= 0) {
  rezultat = 14;
} else {
  rezultat = 7;
}
```

zapisan pomoću ternarnog operatora je:
```c
rezultat = (x >= 0) ? 14 : 7;
```

# Demo zadatak

Kako bi smo poslali sliku s 4b bojama preko nekog "skupog" komunikacijskog kanala?
 - Jedna boja (pixel) je "pola bajta"
 - U int od 4B onda stane 8 boja!

Napiši program koji:
 - Učitava 8 boja (int),
 - Sprema ih u jedan int,
 - raspakira ih natrag u 8 int varijable

```c
// Rješenje zadatka
```

> [!caution]
> Napisati programski kod zadatka


## Skraćena evaluacija
```c
if (true || ...)
```
Uvijek će se biti istina te se ostali izrazi (...) neće testirati.

```c
if (false && ...)
```
Uvijek će se biti laž te se ostali izrazi (...) neće testirati.

## Složeni izrazi
```c
izraz1 = izraz1 + izraz2;
```

ekvivalentno je:
```c
izraz1 += izraz2;
```

Ovo vrijedi za sve binarne operatore.


## sizeof(x)
vraća zauzeće memorije varijable x u bajtovima.

## Operator zarez

Opći oblik:
```c
rj = izraz1, izraz2;
```
`izraz1` i `izraz2` je evaluiraju, ali samo se `izraz2` sprema u varijablu
