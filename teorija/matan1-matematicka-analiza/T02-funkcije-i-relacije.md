[← Natrag na početnu](../../README.md#matematička-analiza-1)

> **🔴🔴🔴 Napomena 🔴🔴🔴**
>
> Ova stranica još nije gotova  i ne garantiramo njezinu točnost

# Funkcije i relacije

## Funkcije teorija

### Za definiciju funkcije potrebna je:
- Domena
- Kodomena
- Pravilo pridruživanja

### Zapis i definicija

- $f:D\to K$, gdje su D i K neprazni skupovi
- pravilo pridruživanja koje svakom $x\in D$ pridružuje **točno jedan** $y\in K$
  - $x\mapsto y = f(x)$

<!--Prvo korištenje napomene -->
> **🔴 Napomena**
> 
> Dvije funkcije su jednake ako se podudaraju u:
> - **Domeni**
> - **Kodomeni**
> - **Pravilu pridruživanja**

## Injektivnost, Surjektivnost i Bijektivnost

### Injektivnost
- $(\forall x_1, x_2 \in D) (x_1 \neq x_2) \implies f(x_1) \neq f(x_2)$
- Funkcija različite elemente **domene** preslikava u različite elemente **kodomene**
- Funkcija je injekcija za:
  -  $(\forall x_1, x_2 \in D)\space f(x_1) = f(x_2) \implies x_1 = x_2$
- Funkcijanije injekcija za:
  -  $(\exists x_1, x_2 \in D)\space x_1 \neq x_2 \space \wedge  f(x_1) = f(x_2)$
  > 🟡 Za izvod gore navedenog suda potrebno je znati negaciju implikacije
  > 
  > $\urcorner (X \Rightarrow Y) \equiv X \space \wedge \space \urcorner Y$

### Surjektivnost
-  Za svaki element **kodomene** postoji barem jedan 
- $(\forall y \in K)(\exist x \in D) \space y = f(x)$
element **domene** koji se u njega preslikava
-  $Im(f) = K$ tj. Slika funkcije je jednaka kodomeni

### Bijekcija
- Za svaki element y iz kodomene postoji jedinstveni element domene x koji se u njega preslikava
- **surjekcija** i **bijekcija**
- $(\forall y \in K)(\exist! x \in D) \space y = f(x)$

### Horizontalni test
<!-- Provjeriti kasnije-->
| Svojstvo   | Uvjet | Broj sjecišta |
|------------|-------|----------|
| Injekcija | Svaki horizontalni pravac siječe funkciju u **najviše** **jednoj** točki| 0 ili 1 |
| Surjekcija | Svaki horizontalni pravac siječe funkciju u **barem** **jednoj** točki | Nije 0 |
| Bijekcija | Svaki horizontalni pravac siječe funkciju u **samo jednoj** točki | 1 |

<!--Prvo korištenje napomene -->
> **🔴 Napomena:**
> 
> Prilikom provjere surjektivnosti bitno je paziti na kodomenu funkcije:

### Parnost i neparnost  funkcija

|     Parna      | Neparna |
| ---------------| ------- |
| $f(-x) = f(x)$ | $f(-x) = -f(x)$ |





### Inverzna funkcija
- Definicija
  - $f:D \to K$
  - $g:K \to D$
  - $g$ je inverzna Funkcija od $f$ ako je:
    - $(\forall x \in D)(g \space \circ f)(x) = x$
    - $(\forall y \in K)(f \space \circ g)(y) = y$
- $f^{-1}: K \to D$
- **Prema definiciji vrijede funkcija iduća svojstva**
  - $(\forall x \in D)\space f^{-1}(f(x)) = x$
  - $(\forall y \in K)\space f(f^{-1}(x)) = x$


## Funkcije dokazi  

|Teorem 2.1.1. |
|--------------|
|Funkcija $f:D \to K$ ima inverznu funkciju ako i samo ako je $f$ bijekcija|

### Dokaz
- Kako je teorem iskazan **ekvivalencijom** (ako i samo ako), onda za dokaz pokazujemo 2 **implikacije**
- A = "Funkcija $f:D \to K$ ima inverznu fuknciju $f^{-1}:K \to D$"
- B = "Funkcija$f$ je bijekcija"
- $A \implies B$
  - Pretpostavljamo A i dokazujemo B
  - Kako bi dokazali **bijektivnost** moramo prvo dokazati **injektivnost** i **surjektivnost**
  - Injektivnost
    1. Koristimo definiciju injektivnosti $(\forall x_1,x_2 \in D) \space f(x_1)=f(x_2) \implies x_1 = x_2$
    1. Koristimo $f^{-1}(f(x)) = x$
    1. Želimo pokazati da je $x_1 = x_2$
    - $$\begin{align*} f(x_1) &= f(x_2) \qquad\qquad \text{(Primjenjujemo inverz funkcije na obje strane)} \\ f^{-1}(f(x_1)) &= f^{-1}(f(x_2)) \qquad\qquad \text{(Koristimo formulu b)} \\ x_1 &= x_2 \qquad\qquad\qquad \text{(Dokazali smo injektivnost)} \end{align*}$$
  - Surjektivnost
    1. Koristimo definiciju surjekcije $(\forall y \in K)(\exist x \in D) y = f(x)$
    1. Koristimo $f(f^{-1}(y)) = y$, gdje je $y \in K$
    1. Sada moramo za svaki $y$ pronaći barem jedan $x$ tako da vrijedi $y = f(x)$
    1. Uzmimo da nam je $x = f^{-1}(y)$
    - $$\begin{align*} y &= f(x) \qquad\qquad \text{(Umjesto x uvrštavamo} \space f^{-1} (y)\text{)} \\ y &=f(f^{-1}(y)) \qquad \qquad \text{(Koristimo formulu b)}  \\ y&=y \qquad \qquad \qquad\text{(Dokazali smo surjektivnost)}\end{align*}$$ 
- $B \implies A$
  - Pretpostavimo B i dokazujemo A
    - Definicija bijekcije $(\forall y \in K)(\exist ! x \in D) \space y = f(x)$
    - Želimo pokazati da vrijede svojstva inverzne funckije
      - $f^{-1}(f(x)) = x$
      - $f(f^{-1}(y)) = y$
    - Definiramo $f:D \to K$ i $g:K \to D$
    - Definiramo $g(y) \coloneqq x$
      - Ovo vrijedi jer funkcija $g$ pridružuje elemente kodomene fukcnije $f$ elementima njezine domene
    - Definiramo $f(x) \coloneqq y$
      - Ovo vrijedi jer funkcija $f$ pridružuje elemente domeni svojoj kodomeni
    - Dokazujemo svojsta inverzne 2 svojstva inverzne funckije koje smo ranije naveli
      - za proizvoljni $x \in D$, $g(f(x)) = g(y) = x$
      - za proizvoljni $y \in K$, $f(g(y)) = f(x) = y$
      - Ovime smo dokazali $B \implies A$
- Ovime smo dokazali teorem