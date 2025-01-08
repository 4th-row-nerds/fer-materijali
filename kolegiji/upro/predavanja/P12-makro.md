[← Natrag](..)

# Makro

- direktive predprocesoru

## Define
- `#define [identifikator] [lista_za_zamjenu]`

- Predprocesor gdje god pronađe ovaj identifikator, zamijeni ga s listom za zamjenu.

### Opasnosti

Makro se "copy-paste"-a u program.
```c
#define POMNOZI(x, y) x * y // ovdje je greška

int main() {
  int a = POMNOZI(5, 2+1);

  // a ce biti 5 * 2+1 što nije 15 već 11!!
}
```

Bolji način:
```c
#define POMNOZI(x, y) ((x) * (y)) // ovdje je dobro

int main() {
  int a = POMNOZI(5, 2+1);

  // a ce biti ((5) * (2+1)) što je 15
}
```

Vanjske zagrade su bitne ako će se vrijednost koristiti u kompleksnijem izrazu.

