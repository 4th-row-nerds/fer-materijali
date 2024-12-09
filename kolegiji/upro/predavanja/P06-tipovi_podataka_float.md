[← Natrag](..)

# Tipovi podataka - float

## Binarni razlomci

Racionalni broj `q` može se zapisati:
 - $q = \pm (c_n \cdot 2^n+c_{n-1} \cdot 2^{n-1} + \cdots + c_0 \cdot 2^0 + r_1 \cdot 2^1 + r_2 \cdot 2^2 + \cdots + r_n \cdot 2^n)$

 Taj zapis je neefektivan jer ne možemo prikazati puno dekadskih brojeva.

Rješenje! $\Rightarrow$ `float`

## Float - znanstveni zapis

Tvori se od 3 dijela:
 - bit predznaka
 - eksponent
 - mantisa

Za broj `-0.5` možemo zapisati bazom 2 kao: -0.1 ili $-1 \cdot 2^{-1}$

Tj. bit predznaka biti će 1 za negativan broj.

A bitovi exponenta biti će broj 127 - bitovi exponenta (kako bi mogli prikazati pozitivne i negativne eksponentet $\Rightarrow$ $2^{-1}$ = 01111110)

Raspon exponenata je $[-126, 127]$.

Mantisa će biti 1.`00000...` zato što se prva jedinica ne piše.

Tako će se broj `-0.5` zapisati
|Bit predznaka|Eksponent|Mantisa|
|:-:|:-:|:-:|
|1|01111110|00000000000000000000000|

Isti broj zapisan heksadekadski je $BF000000$


### Primjeri

- 2.0
- -2.0
- 4
- 0.75
- 1


### Posebni slučajevi

Prikaz 0: sve 0

|Bit predznaka|Eksponent|Mantisa|Vrijednost|
|:-:|:-:|:-:|:-:|
|0|00000000|00000000000000000000000|+0|
|1|00000000|00000000000000000000000|-0|

Denormalizirani broj:
 - Exponent je 0, a u mantisi se nalazi nešto.
 - Tretira se kao mantisa(bez jedinice na početku) * $2^{-126}$
<!-- Napisati objašnjenje do kraja -->

Beskonačno

|Bit predznaka|Eksponent|Mantisa|Vrijednost|
|:-:|:-:|:-:|:-:|
|0|11111111|00000000000000000000000|$+\infty$|
|1|11111111|00000000000000000000000|$-\infty$|

NaN
- Karakreristika kao za beskonačnost ali ima nešto u mantisi.

|Bit predznaka|Eksponent|Mantisa|Vrijednost|
|:-:|:-:|:-:|:-:|
|0|11111111|10000000000000000000000|NaN|

> [!note]
> U float stane 1.95% unsigned int brojeva.

### Pogreške pri prikazu brojeva

Najveća moguća relativna pogreška ovisi o broju bitova mantise
 - Za IEEE 754 standard preciznosi $$ \rho \le 2^{-12} \approx 6 \cdot 10^{-8} $$

 Za neki broj x progreška će biti:
 $$ \alpha \le 2^{-24} \cdot |x| \approx 6 \cdot 10^{-8} \cdot |x| $$

Za praćenje novca ili druge primjene gdje je preciznost bitna sve brojeve se može pomnožiti sa 100 (za novce) i spremiti u int.


# Tipovi podataka - double

Tvori se od 64bita:

|Bit predznaka|Karakteristika|Mantisa|
|-|-|-|
|1 bitova|11 bitova|52 bitova|

# Tolerancija

Kako bi se pogreške u pohranjivanju broja minimizirale, dodaje se mala vrijednost $\epsilon$ (tolerancija) u čijem se rasponu rješenje provjerava.

