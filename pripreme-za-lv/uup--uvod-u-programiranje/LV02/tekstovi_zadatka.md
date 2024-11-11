[← Natrag na početnu](../../../README.md#uvod-u-programiranje)

[Rješenja Zadataka](.)

# Zadatak 01
Napišite program koji s tipkovnice učitava prirodni broj N (broj članova polja) te učitava polje od N prirodnih brojeva. Zatim s tipkovnice učitati novi prirodni broj te indeks na koji će biti dodan u postojeće polje. Ostali članovi polja se u odnosu na umetnutog člana pomiču udesno, a zadnji član će izaći "izvan" polja. Program treba ispisati početno te novodobiveno polje.

Unesene vrijednosti nije potrebno provjeravati. Pretpostaviti da će uvijek biti odabran indeks unutar dimenzija odabranog polja.

Primjeri izvršavanja:

```c
Unesite·broj·clanova·polja:4↵
Unesite·clanove·polja·(4):↵
1·2·3·4↵
Unesite·vrijednost·novog·clana·te·indeks:↵
12·2↵
Pocetno·polje↵
1·2·3·4·↵
Novodobiveno·polje↵
1·2·12·3·
```
```c
Unesite·broj·clanova·polja:10↵
Unesite·clanove·polja·(10):↵
3·12·27·83·2·54·3·21·105·8↵
Unesite·vrijednost·novog·clana·te·indeks:↵
1000·4↵
Pocetno·polje↵
3·12·27·83·2·54·3·21·105·8·↵
Novodobiveno·polje↵
3·12·27·83·1000·2·54·3·21·105·
```
> Napomena: Polje definirati tako da se za njegovu pohranu koristi minimalan memorijski prostor. Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).


# Zadatak 02
S tipkovnice učitati cijeli broj n koji predstavlja broj elemenata u polju. Nakon toga učitati n cijelih brojeva u polje. Svaki od elemenata zamijeniti zbrojem tog elementa i elemenata većih indeksa od trenutnog. Nakon izračuna ispisati dobiveno polje.

Primjer izvršavanja programa:

```c
Unesite·duljinu·polja:·3↵
Unesite·elemente·polja:↵
1·2·3↵
Izracunato·polje:·6·5·3
```
```c
Unesi·duljinu·polja:·5↵
Unesite·elemente·polja:↵
4·1·9·8·8↵
Izracunato·polje:·30·26·25·16·8
```
> Napomena: Polje definirati tako da se za njegovu pohranu koristi minimalan memorijski prostor. Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).


# Zadatak 03
S tipkovnice učitati vrijednosti za broj redaka m i broj stupaca n dvodimenzijskog cjelobrojnog polja. Ako vrijednosti m i n nisu jednake, prekinuti s izvršavanjem programa i ispisati odgovarajuću poruku.

Po retcima učitati prirodne brojeve kao vrijednosti članova polja od m redaka i n stupaca. Nakon što su sve vrijednosti upisane, napisati program koji ispisuje razliku zbroja kvadrata glavne dijagonale i sporedne dijagonale polja.

Primjer izvršavanja programa:

```c
Unesi·dimenzije:·2·3↵
Dimenzije ne odgovaraju kvadratnoj matrici!↵
```
```c
Unesi·dimenzije:·3·3↵
Unesi·clanove·polja:↵
1·2·3↵
4·5·6↵
7·8·9↵
Odabrana·je·matrica:↵
·1·2·3↵
·4·5·6↵
·7·8·9↵
Razlika·zbrojeva·je·24.↵
```
> Napomena: Polje definirati tako da se za njegovu pohranu koristi minimalan memorijski prostor. Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).


# Zadatak 04
S tipkovnice učitati cijeli broj n koji predstavlja broj redaka i stupaca dvodimenzionalnog polja. Po retcima učitati cijele brojeve kao vrijednosti članova polja.

U drugo polje jednakih dimenzija upisati elemente jednake elementima prvog polja rotiranog za 90 stupnjeva u smjeru kazaljke na satu. Ispisati dobiveno polje.

```c
Unesite·dimenzije·polja:·3↵
Unesite·elemente·polja:·↵
1·2·3·↵
4·5·6·↵
7·8·9·↵
Izracunato·polje:·↵
7·4·1·↵
8·5·2·↵
9·6·3·↵
```
```c
Unesite·dimenzije·polja:·2↵
Unesite·elemente·polja:·↵
1·2·↵
3·4·↵
Izracunato·polje:·↵
3·1·↵
4·2·↵
```
> Napomena: Polje definirati tako da se za njegovu pohranu koristi minimalan memorijski prostor. Znak ↵ ukazuje da na tom mjestu treba "ispisati skok u novi red" ili pritisnuti tipku Enter (odnosno Return), a znak · da na tom mjestu treba ispisati prazninu (space).
