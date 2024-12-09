[← Natrag na početnu](../../README.md#uvod-u-programiranje)

# Definicija tipa podatka

Kreiranje zamjenskog tipa ili imena (sinonim) za postojeći podatak.

Opći oblik naredbe:
```c
typedef nazivPostojecegTipa noviNazivTipa;
```

Primjer:
```c
typedef struct {
  int mbr;
  char ocjena;
  char *ime;
} student_t;

int main(void) {
  student_t neki_student = {0};
  /* */
  return 0;
}
```

## ugrađene definicije tipova

- stdlib.h

|tip|velicina|
|-|-|
|size_t|veličine kao int, unsigned|


- stdint.h

|tip|velicina|
|-|-|
|uint8_t|8 bita, unsigned|
|int8_t|8 bita, signed|
|uint16_t|16 bita, unsigned|
|int16_t|16 bita, signed|
|uint32_t|32 bita, unsigned|
|int32_t|32 bita, signed|
|uint64_t|64 bita, unsigned|
|int64_t|64 bita, signed|


# Demo zadatak
Napišite program koji će učitati ključ (pomak, shift) i:
 - Šifrirati znakovni niz "Hello world!" Cezarovom šifrom
 - Potom dešifrirati šifrirani niz.

> Više info na [wikipediji](https://en.wikipedia.org/wiki/Caesar_cipher)

> [!tip]
> Za pomak sa slova `'Z'` na slovo `'A'` koristiti operator `%`

<details>
  <summary>Rješenje zadatka</summary>

  ```c
  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prvi i zadnji printable char
#define FIRST_PC ' '
#define LAST_PC  '~'

int main() {
    char text[50] = "Hello, Wordl!";
    int offset = 0;
    printf("Upisi kljuc (offset): ");
    scanf("%d", &offset);

    size_t PRINTS_LEN = FIRST_PC - LAST_PC + 1;

    char cypher[100] = {0};
    for (size_t i = 0; i < strlen(text); i++) {
        cypher[i] = FIRST_PC + ((text[i] - FIRST_PC) + offset) % PRINTS_LEN;
    }

    printf("Coded: %s\n", cypher);

    char decoded[100] = {0};
    offset *= -1;
    for (size_t i = 0; i < strlen(cypher); i++) {
        decoded[i] = FIRST_PC + ((cypher[i] - FIRST_PC) + offset + PRINTS_LEN) % PRINTS_LEN;
    }

    printf("Decoded: %s\n", decoded);

    return 0;
}
  ```

</details>

> [!caution]
> Napisati programski kod zadatka

# Pretvorbe podataka


## Implicitne pretvorbe podataka

1. ako je jedan od operanda `long double`, preostali se pretvaraju u njega
1. ako je jedan od operanda `double`, preostali se pretvaraju u njega
1. ako je jedan od operanda `float`, preostali se pretvaraju u njega
1. ako je jedan od operanda `long long`, preostali se pretvaraju u njega
1. ako je jedan od operanda `long`, preostali se pretvaraju u njega
1. ako je jedan od operanda `_Bool`, `short` ili `char`, preostali se pretvaraju u `int`

> Todo: dodati primjer promoviranja iz prezentacije

## Eksplicitne pretvorbe podataka (casting)

Opći oblik eksplicitne pretvorbe je
```c
(tip_podatka) izraz
```

