[← Natrag na početnu](../../README.md#matematička-analiza-1)

# Skupovi, matematička logika, realni brojevi

## Uvod

### Konzultacije
| prof.   | Marin Bužančić            |
|---------|---------------------------|
| email   | marin.buzancic@fer.hr     |
| vrijeme | od 12 sati, svaku srijedu |
> Ukoliko se na mail ne javi dolazak, potražiti u kabinetu

### Polaganje
1. Kontinuirana nastava
	- Međuispit, završni ispit
	- 50 bodova
2. Ispitni rokovi
	- Zimski, Ljetni, Jesenski i Dekanski

> Više informaciji na [stranici predmeta](https://www.fer.unizg.hr/predmet/matan1)

### Materijali
#### Web stranica kolegija
 - [skripta](https://www.fer.unizg.hr/predmet/matan1/materijali/online_skripta)
 - [auditorne vježbe 23/24](https://www.fer.unizg.hr/predmet/matan1/materijali/auditorne_vjezbe_2023/24)
 - ispiti prijašnjih godina
 - Moodle

#### Materijali s drugih fakulteta
 - [PMF - Matematički Odsjek](https://www.pmf.unizg.hr/math)
 - [FESB](https://www.fesb.unist.hr/)
 - [FKIT](https://www.fkit.unizg.hr/) (za integrale i ostalo u II. ciklusu)

<hr>
<br>

## Definicije

| Pojam       | Definicija                                                                                      |
|-------------|-------------------------------------------------------------------------------------------------|
| Aksiom      | tvrdnja koja se uzima kao očigledna istina                                                      |
| Definicija  | točan opis značenja ili svojstva nekog pojma s poznatim pojmovima  ne smije biti cirkularna     |
| Teorem      | tvrdnja čiju istinu treba dokazati izvođenjem dokaza   iskaz se sastoji od pretpostavki teorema |
| Propozicija | teorem manje važnosti                                                                           |
| Lema        | pomoćna tvrdnja za dokaz većih teorema                                                          |
| Korolar     | slijedi jednostavnim logičkim zaključivanjem kao posljedica teorema                             |
| Skup        | mnoštvo (nekih) objekata koje nazivamo elementima                                               |

### Oznake kod skupova
| Oznaka                                                            | Značenje                 |
|-------------------------------------------------------------------|--------------------------|
| $A, B, C, S, D, U, ...$                                           | Primjeri oznaka za skup  |
| $a, b, c, x, y, ...$                                              | Primjeri elemenata skupa |
| $x \in S$                                                         | $x$ pripada skupu $S$    |
| $A \subseteq B$                                                   | $A$ je podskup skupa $B$ |
| $\emptyset$ ili `{}`                                               | Prazan skup              |
| $A \cup B, A \cap B, A \space\backslash\space B, A^C, A \times B$ | Operacije nad skupovima  |

<hr>
<br>

 ## Uvod u matematičku logiku i pravila zaključivanja

 ### Sudovi

 |Sud|smislena izjavna rečenica (tvrdnja) za koju se može utvrditi istina ili laž|
 |:-:|:-:|

 Sud može imati vrijednost $X \equiv T$ ako je sud $X$ istinit i $X \equiv F$ ako je lažan.

<hr>

|Konjunkcija|logička operacija koja je istinita samo kada su oba suda istina|
|:-:|:-:|
|oznaka|$X \wedge Y$ ili $X \space i \space Y$|

Tablica istinitosti
|$X$|$Y$|$X \wedge Y$|
|:-:|:-:|:-:|
|F|F|F|
|F|T|F|
|T|F|F|
|T|T|T|

<hr>

|Disjunkcija|logička operacija koja je lažna samo kada su oba suda laž|
|:-:|:-:|
|oznaka|$X \vee Y$ ili $X \space ili \space Y$|

Tablica istinitosti
|$X$|$Y$|$X \vee Y$|
|:-:|:-:|:-:|
|F|F|F|
|F|T|T|
|T|F|T|
|T|T|T|

<hr>

|Implikacija|složeni skup koji je lažan jedino onda kada je $X$ istinit i $Y$ lažan|
|:-:|:-:|
|oznaka|$X \Rightarrow Y$|
|čitamo|"$X$ povlači $Y$" ili "iz $X$ slijedi $Y$" ili "ako $X$ onda $Y$"|

Tablica istinitosti
|$X$|$Y$|$X \Rightarrow Y$|
|:-:|:-:|:-:|
|F|F|T|
|F|T|T|
|T|F|F|
|T|T|T|

<hr>

|Ekvivalencija sudova|logička operacija koja je istinita samo kada su oba sudajednaka (ili oba lažna ili oba istinita)|
|:-:|:-:|
|oznaka|$X \Leftrightarrow Y$|

Tablica istinitosti
|$X$|$Y$|$X \Leftrightarrow Y$|
|:-:|:-:|:-:|
|F|F|T|
|F|T|F|
|T|F|F|
|T|T|T|

<hr>

|Negacija|negacija suda $X$ je istina samo ako je $X$ lažan|
|:-:|:-:|
|oznaka|$\urcorner X$|

Tablica istinitosti
|$X$|$\urcorner X$|
|:-:|:-:|
|F|T|
|T|F|

<hr>

### Transformacija pravila (logički ekvivalenti)

#### Teorem 1.3.1 u skripti
> Dokazati za DZ

| $(i)$   | $\urcorner (\urcorner X)$     | $\equiv$ | $X$                                                        | pravilo dvostruke negacije |
|:-------:|------------------------------:|:--------:|:-----------------------------------------------------------|:---------------------------|
| $(ii)$  | $\urcorner (X \wedge Y)$      | $\equiv$ | $\urcorner X \space \vee \space \urcorner Y$               | De Morganov zakon          |
| $(iii)$ | $\urcorner (X \vee Y)$        | $\equiv$ | $\urcorner X \space \wedge \space \urcorner Y$             | De Morganov zakon          |
| $(iv)$  | $\urcorner (X \Rightarrow Y)$ | $\equiv$ | $X \space \wedge \space \urcorner Y$                       | negacija implikacije       |
| $(v)$   | $X \Rightarrow Y$             | $\equiv$ | $\urcorner X \space \wedge \space Y$                       |                            |
| $(vi)$  | $X \Rightarrow Y$             | $\equiv$ | $\urcorner Y \Rightarrow \space \urcorner X$               | obrat po kontrapoziciji    |
| $(vi)$  | $X \Leftrightarrow Y$         | $\equiv$ | $(X \Rightarrow Y) \space \wedge \space (Y \Rightarrow X)$ |                            |

<hr>

### Tautologije
Za formulu kažemo da je tautologija ako je istina neovisno o ulazima.

#### Propozicija 1
Neka su $X$ i $Y$ sudovi, sljedeće formule su tautologije:

| $(i)$   | $(X \wedge (X \Rightarrow Y))$                                   | $\Rightarrow$ | $Y$           | modus ponens          |
|:-------:|-----------------------------------------------------------------:|:-------------:|:--------------|:----------------------|
| $(ii)$  | $((X \Rightarrow Y) \space \wedge \space \urcorner Y)$           | $\Rightarrow$ | $\urcorner X$ | modus pollens         |
| $(iii)$ | $((\urcorner X \Rightarrow Y) \space \wedge \space \urcorner Y)$ | $\Rightarrow$ | $X$           | dokaz po kontadikciji |

<hr>

### Predikati i logički kvantifikatiori

#### Predikati

Sjetimo se da izjava $x^2 + 1 > 5$ nije sud. Ukoliko **uvrstimo** $x \in \mathbb{R}$ dobiljemo sud

|$x$|Sud|vrijednost suda|
|---|:-:|:-------------:|
|$x = 3$|$3^2 + 1 > 5$|T|
|$x = 0$|$0^2 + 1 > 5$|F|

Izjava $P(x)$ ovisi o varijabli $x \in U$, takav da za $a \in U$ uvijek vrijedi. Onda je $P(x)$ predikat.


#### Logički kvantifikatori

|Ime kvantifikatora|Oznaka|Čita se|
|-|-|-|
|Univerzalni kvantifikator|$\forall x \in U$|za svaki (el. $x$ u skupu $U$)|
|Egzistencijalni kvantifikator|$\exists x \in U$|postoji barem jedan (el. $x$ u skupu $U$)|
|Kvantifikator jedinstvenosti|$\exists! x \in U$|postoji točno jedan (el. $x$ u skupu $U$)|
