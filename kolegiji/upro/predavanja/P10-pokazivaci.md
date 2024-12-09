[← Natrag na početnu](../../README.md#uvod-u-programiranje)

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

> [!caution]
> Napraviti zadatak
