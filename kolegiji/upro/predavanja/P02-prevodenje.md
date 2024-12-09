[← Natrag na početnu](../../README.md#uvod-u-programiranje)

# Prevođenje C programa

### Faze
 - Pretproecesor
 - C prevodilac (compiler)
 - Assembler
 - Linker

### Libs
Djele se kao već kompajlirane datoteke koje se priključuju našim programima s Linkerom.

 - stdio - I/O operacije
 - math - sin(), cos()


### GCC

Preprocesor:
```bash
$ gcc -E main.c > main.i
```

Asember:
```bash
$ gcc -S main.c
```

Bytecode:
```bash
$ gcc -c main.c
```

## Struktura C programa

### Funkcije
Imenovani blokovi, ulazna točka programa.

```c
#include <stdio.h>

int main() {
  return 0;
}
```

### Ključne riječi C-a
C11 ima 44 ključne riječi.
- CaseSensitive

### Komentari

- jednolinijski
```c
// Komentar
```

- blokovi
```c
/*
 * Blok Komentara
 */
```

### Varijable

| Sintaksa | Tip Varijable |
|:--:|:--:|
|int| cijelobrojna varijabla |
|float| varijabla za realne brojeve |
|_Bool| istina ili laž |

Varijabla se može deklarirati s ključnom riječju `const` i tada se njen sadržaj neće moći mijenjati.

Imenovati varijable tako da se njena funkcija može naslutiti iz imena.


### Izrazi

- izraz pridruživanja
- aritmetički izraz
- relacijski izraz
- logički izraz

```c
256                   // Aritmetički izraz
a                     // Aritmetički izraz
a + 11                // Aritmetički izraz
(a + 1) * (b - 1)     // Aritmetički izraz
a = 2                 // Izraz za dodjeljivanje
b = a + 3             // Izraz za dodjeljivanje s aritmetičkim izrazom
a <= 10               // Relacijski izraz
(a <= 10) && (a >= 3) // Dva relacijska izraza unutar logičkog izraza
```

#### Pridruživanje

- simbol u pseudo-kodu  :=
- simbol u C-u          =

Primjer:
```c
  int k;    // Deklariranje
  k = 5;    // Inicijalizacija
  k = k + 1 // Korištenje
```

L-value -> locator value
 - objekt koji ima određenu adresu (varijabla)

R-value -> read value (value of expression)
 - nema adresu, to je konstanta (izlaz funkcije, upisani brojevi, ...)

Vrijednost pridruživanja je rezultat pridruživanja.
```c
a = b = c = 3 + 1;
// Sve 3 varijable su 4

// Ispiše se 14
printf("%d", a = 14);
```

### Djelovanje operatora na cijelobrojne operande
```c
int a = 11, b = 3;

a + b == 14
a - b == 8
a * b == 33
a / b == 3
a % b == 2
```

## Algoritam zamjene varijabli

```c
int a = 4, b = 14
int temp;

temp = a;
a = b;
b = temp;
```
