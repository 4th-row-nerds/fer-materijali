[← Natrag na početnu](../../README.md#uvod-u-programiranje)

# Pokazivači

## Definicija
Varijabla koja pokazuje na mjesto u memoriji gdje se nalaze vrijednosti koje nam trebaju.

tj. pokazivač je referenca na varijablu

## Deklaracija
Pokazivač se može deklarirati od bilokojeg osnovnog tipa podatka dodavanjem zvjezdice nakon imena varijable.

Za deklariranje pokazivaca `char` tipa:
```c
int *pokazivac;
```
<br>

Za deklariranje pokazivaca `char` tipa:
```c
char *pokazivac;
```


## Korištenje
Kreiranje varijable `a` i kreiranje reference na tu varijablu.

```c
int a = 4;
int *ap; // Deklariranje pokazivača int tipa
ap = &a; // Inicijalizacija pokazivača na adresu varijable a

*ap = 5; // Mijenjanje varijable a preko reference (engl. dereferencing)
```

# Demo Zadatak
Upotrijebimo void* da ispišemo bitove odnosno IEEE754 reprezentaciju float broja (binarnu i hex)

> [!caution]
> Napraviti zadatak
