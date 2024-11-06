[← Natrag na početnu](../../README.md#uvod-u-programiranje)

# Tipovi podataka - char

## char
 - signed [-128, 127]
 - unsigned [0, 255]

## Upotreba char-a za prikaz znakova

 - Pohranjivanje znakova kao binarnih kodova
 - ASCII: sadrži 128 različitih simbola i upravljačkih znakova [0 do 127]
 - ISO-8859
   - proširenje ASCII-a sa 128 kodnih vrijednosti [128 do 255]
   - Znakovi koji su dodani ovise o kodnoj stranici
     - ISO 8859-1: dodani znakovi zapadnoeuropskih jezika
     - ISO 8859-2: dodani znakovi istočnoeuropskih jezika
       - npr. š = $185_{10}$, Č = $200_{10}$
 > na ovom predmetu koristi se kodna stranica ASCII

## ASCII kodovi
|Dec	|Hex	|Char|
|:-|:-:|:-:|
|0	|0	|NUL|
|1	|1	|SOH|
|2	|2	|STX|
|3	|3	|ETX|
|4	|4	|EOT|
|5	|5	|ENQ|
|6	|6	|ACK|
|7	|7	|BEL|
|8	|8	|BS|
|9	|9	|TAB|
|10	|A	|LF|
|11	|B	|VT|
|12	|C	|FF|
|13	|D	|CR|
|14	|E	|SO|
|15	|F	|SI|
|16	|10	|DLE|
|17	|11	|DC1|
|18	|12	|DC2|
|19	|13	|DC3|
|20	|14	|DC4|
|21	|15	|NAK|
|22	|16	|SYN|
|23	|17	|ETB|
|24	|18	|CAN|
|25	|19	|EM|
|26	|1A	|SUB|
|27	|1B	|ESC|
|28	|1C	|FS|
|29	|1D	|GS|
|30	|1E	|RS|
|31	|1F	|US|
|32	|20	|Space|
|33	|21	|!|
|34	|22	|\"|
|35	|23	|#|
|36	|24	|$|
|37	|25	|%|
|38	|26	|&|
|39	|27	|'|
|40	|28	|(|
|41	|29	|)|
|42	|2A	|*|
|43	|2B	|+|
|44	|2C	|,|
|45	|2D	|-|
|46	|2E	|.|
|47	|2F	|/|
|48	|30	|0|
|49	|31	|1|
|50	|32	|2|
|51	|33	|3|
|52	|34	|4|
|53	|35	|5|
|54	|36	|6|
|55	|37	|7|
|56	|38	|8|
|57	|39	|9|
|58	|3A	|:|
|59	|3B	|;|
|60	|3C	|<|
|61	|3D	|=|
|62	|3E	|>|
|63	|3F	|?|
|64	|40	|@|
|65	|41	|A|
|66	|42	|B|
|67	|43	|C|
|68	|44	|D|
|69	|45	|E|
|70	|46	|F|
|71	|47	|G|
|72	|48	|H|
|73	|49	|I|
|74	|4A	|J|
|75	|4B	|K|
|76	|4C	|L|
|77	|4D	|M|
|78	|4E	|N|
|79	|4F	|O|
|80	|50	|P|
|81	|51	|Q|
|82	|52	|R|
|83	|53	|S|
|84	|54	|T|
|85	|55	|U|
|86	|56	|V|
|87	|57	|W|
|88	|58	|X|
|89	|59	|Y|
|90	|5A	|Z|
|91	|5B	|[|
|92	|5C	|\|
|93	|5D	|]|
|94	|5E	|^|
|95	|5F	|_|
|96	|60	|`|
|97	|61	|a|
|98	|62	|b|
|99	|63	|c|
|100	|64	|d|
|101	|65	|e|
|102	|66	|f|
|103	|67	|g|
|104	|68	|h|
|105	|69	|i|
|106	|6A	|j|
|107	|6B	|k|
|108	|6C	|l|
|109	|6D	|m|
|110	|6E	|n|
|111	|6F	|o|
|112	|70	|p|
|113	|71	|q|
|114	|72	|r|
|115	|73	|s|
|116	|74	|t|
|117	|75	|u|
|118	|76	|v|
|119	|77	|w|
|120	|78	|x|
|121	|79	|y|
|122	|7A	|z|
|123	|7B	|{|
|124	|7C	|||
|125	|7D	|}|
|126	|7E	|~|
|127	|7F	|DEL|

## Unicode
Multibyte enkodiran znak.
Više standarda: UTF-8, UTF-16, ...

## Konverzijske specifikacije za prinft i scanf

|Tip |signed format|unsigned format|
|----|------------:|--------------:|
|char|         %hhd|           %hhu|

- d ili u se može zamijeniti s x, X, o za ispis u oktalnom ili heksadekadskom formatu.

- Za ispisivanje znaka potrebno je koristiti %c

## Konstante
 - Znak iz ASCII tablice može se napisati pod jednostrukim navodnicima (npr. `'A'`) te će se koristiti njegova vrijednost bez da se ona mora specificirati.

Definiranje slova 'A' korištenjem:
|vrijednosti za kod simbola|simbola u navodnicima|
|-|-|
|`char znak = 65;`|`char znak = 'A';`|

Radi pojednastovljenja, koristi se kolokvijalni izraz:
 - 'A' je znakovna konstanta
 - varijabla `znak` je znakovnog tipa
 - u varijablu `znak` upisan je znak A


# Nizovi znakova - string

 - U C-u ne postoji osnovni tip podataka koji podržava rad s nizovima znakova.
 - Za pohranu niza znakova koristi se jednodimenzijalno polje čiji su članovi tipa `char` i kraj se označava s nul-znakom '\0'

 Primjer korištenja:
```c
 char ime[5];
 ime[0] = 'I';
 ime[1] = 'v';
 ime[2] = 'a';
 ime[3] = 'n';
 ime[4] = '\0';

 printf("%s", ime);
```

## Jednostavniji način inicijalizacije

Umjesto
```c
char ime[5] = {'I', 'v', 'a', 'n', '\0'};
```
 - može se (i bolje je) koristiti drugi oblik
 ```c
  char ime[5] = "Ivan";
 ```
 - ili
 ```c
  char ime[] = "Ivan";
 ```
U tom slučaju "Ivan" je konstantan niz znakova (eng. string constant)

Polje je non-modifiable lvalue pa se ne može promijeniti nakon inicijalizacije tj.
```c
 char ime[10 + 1];
 ime = "Iva";  // Nije dopušteno
```

## Konverzijska specifikacija %s za scanf
 - Scanf učituje do whitespace-a
 - Scanf sam dodaje '\0'
 - Nesiguran (ne provjerava veličinu polja u koje učitava)

### fgets(char *p, int cap, FILE *stream)
 - učitava do '\n'
 - sprema rezultat u polje `p` i provjerava da ne dostiže `cap` - broj mjesta u polju
 - stream, uglavnom `stdin`, može biti i datoteka

# Demo zadatak 1
Programski zadatak
- s tipkovnice učitati niz znakova iz jednog retka. Niz znakova, uključujući oznaku novog retka (ako bude učitana), ne smije biti dulji od 10 znakova.
- ako učitani niz sadrži znak za prelazak u novi redak, izbaciti ga iz niza. Sva mala slova u nizu pretvoriti u velika. Ispisati novi sadržaj niza i odmah iza kraja niza uskličnik.

Primjeri ulaza:
```c
Upisite niz znakova > Kvaka 22↵
KVAKA 22!
```
```c
Upisite niz znakova > Put u svemir↵
PUT U SVEM!
```
```c
Upisite niz znakova > ↵
!
```

<details>
  <summary>Riješenje zadatka</summary>

```c
#include <stdio.h>
#define MAX_NIZ 10
int main(void) {
    char niz[MAX_NIZ + 1];
    int i = 0;
    printf("Upisite niz znakova > ");
    fgets(niz, MAX_NIZ + 1, stdin);
    while (niz[i] != '\0') {
	if (niz[i] >= 'a' && niz[i] <= 'z') {
	    niz[i] = niz[i] - ('a' - 'A');
	} else if (niz[i] == '\n') {
	    niz[i] = '\0';
	}
	i++;
    }
    printf("%s!", niz);
    return 0;
}
```

</details>

# Demo zadatak 2

Procijenite učestalost slova u engleskom jeziku tako što ćete prebrojiti koliko puta se koje slovo pojavljuje u svim Shakespearovim djelima.

Prikažite grafički, s pomoću stupčastog grafa (histogram).

> [!note]
> Datoteka sa svim Shakespearovim djelima nalazi se [ovdje](./P05-shakespeare-all-works.txt).
<!-- Preuzeto sa: https://www.gutenberg.org/cache/epub/100/pg100.txt -->

<details>
  <summary>Riješenje zadatka</summary>

```c
#include <stdio.h>
#include <string.h>

#define MAX_REDAK 1000

int main(int argc, char **argv) {
  // Za svako slovo u ASCII tablici
  int frekvencija[256] = {0};

  printf("Za zavrsetak rucnog unosa, upisati \"/kraj\" ili stisnuti CTRL+D.\n");
  printf("Za unos iz datoteke na linuxu napisati \"cat [ime_datoteke] | %s\"\n", argv[0]);

  char redak[MAX_REDAK];
  while (fgets(redak, MAX_REDAK, stdin) != NULL) {
    // Završava unos da se može izaći kada se ručno upisuje s komandne linije.
    if (!strcmp(redak, "/kraj\n")) break;

    for (int i = 0; redak[i] != '\0' && redak[i] != '\n'; i++) {
      frekvencija[(int)redak[i]]++;
    }
  }

  int frek_slova[26] = {0};
  int max_slova = 0;

  // Izračun frekvencija slova i treaženje maksimalne frekvencije
  for (int i = 0; i < 'Z' - 'A'; i++) {
    frek_slova[i] = frekvencija['A' + i] + frekvencija['a' + i];
    if (frek_slova[i] > max_slova) max_slova = frek_slova[i];
  }

  // Ispis
  printf("\nBroj ponavljanja  Znak Graficki prikaz broja ponavljanja\n");
  for (int i = 0; i < 'Z' - 'A'; i++) {
    printf("%16d     %c|", frek_slova[i], 'A' + i);

    // Ispis retka # za jedno slovo
    const int max_br_znakova = 100;
    for (int c = 0; c < max_br_znakova*frek_slova[i]/max_slova; c++) putchar('#');
    printf("\n");
  }

  return 0;
}
```

</details>
