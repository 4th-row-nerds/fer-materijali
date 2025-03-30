[← Natrag](..)

# Kriptografija

## [Link na zadatke](../repo/navkis_kriptografija_zadaci.zip)


<!-- [Link na ctf101.org](https://ctf101.org/cryptography/overwiew) -->

# Klasična kriptografija

## Simetrična i asimetrična

- U simetričnoj se koristi isti ključ za zaključavanje i otključavanje
- U antisimetričnoj se koristi matematika tako da se jednim ključen može samo zaključati (javni ključ), a drugim se može otključati (privatni ključ)

## Kategorija 1: Zadatci koji zapravo nemaju veze sa kriptografijom

Korisni alati:
- Linux naredba `file`
- [CyberChef](https://gchq.github.io/CyberChef/)

### Zadatak 01: Mic Check
> Svi zadatci dostupni [ovdje](../repo/navkis_kriptografija_zadaci.zip)

```
HA! SCH! PF! PF! HA! N! N! Z85! ZeroMQ! Mic check!

x<$N]w{X!SeP0jLeP2iiuT)+9v@3F
```

Nije zapravo enkriptirano namjerno već se koristi određeni message protokol
Koristiti [CyberChef](https://gchq.github.io/CyberChef/) za dekriptiranje.

>[!note]
> Koristiti from Base 85, odabrati Z85 abecedu i maknuti zero group char


## Cezarova šifra

Svako slovo u ulazu mijenja se sa slovom koje je `K` slova prije njega u abecedi.

## Kategorija 2: Brute-force napadi na kriptosustave

Pristup:
- Isprobaj sve moguće ključeve

Korisni alati:
- Hashcat
- John the ripper
- [Crackstation](https://crackstation.net)
- Programski jezik po vlastitom izboru :)

### Zadatak 02: Super Encryption
> Svi zadatci dostupni [ovdje](../repo/navkis_kriptografija_zadaci.zip)

Dobijemo `encript.py` i `cypher.txt`.
Moramo unazad raditi kako bi dobili zastavicu.

Zastavicu `m` program šifrira ključem `k1` i onda opet ključem `k2`.

$$
    E\left(E(m, k_1), k_2\right) = cypher
$$

U `encript.py` nam je poznat oblik zastavice tj. znamo da počinje sa `TheBlockTechLtd{`

U aes ecb načinu rada, šifra ako je dulja od 16 bajta djeli se u blokove od 16 bajta.


Koristimo meet in the middle metodu s $m_{16}$[prvih poznatih 16 bajta poruke]:
|$k_1$|$E(m_{16}, k_1)$|
|:-:|:-:|
|00 $\dots$ 0|`ashdsl`|
|00 $\dots$ 1|`ogisaf`|
|$\vdots$|`asčisa`|
|$k_1'$|`x`|
|$\vdots$|`asčisa`|
|11 $\dots$ 1|`pdsajd`|

```py
for k2 ... (svaki mogući k2 [20 bit])
  x = D(cypher, k2)
  nađi x u drugom stupcu tablice
```

## Kategorija 3: Povijesna kriptografija

Korisni alati:
- [CyberChef](https://gchq.github.io/CyberChef/)
- [dcode](https://www.dcode.fr/en)

### Vigenèreova šifra

Koristi ključ kako bi zbrojio poruku i ključ da dobije rezultat (ponavlja ključ ako je potrebno)

npr.
```
k = "DEDA"
m = "NAPADAMO U ZORU"

V(m, k) = "QESAGEPO Y ZRVX"
```

Dešifriranje: frekvencijska analiza Kaskijevim testom (ili for petljom)
- neke riječi u određenom jeziku često se ponavljaju (npr. riječ "the")


# Simetrične šifre
Jedan ključ s kojim se enkriptira i dekriptira

## Jednokratna bilježnica (one-time pad)

Poruka se šifrira sa ključem tako da se odradi xor operacija nad porukom.

```
OTP(m, k) = c
OTP(c, k) = m
```
primjer
```c
OTP(0110, 0011) = 0101  // cypher isto kao i 0110 ^ 0011
OTP(0101, 0011) = 0110  // plain text isto kao i 0101 ^ 0011
```

>[!note] Nedostatci
> - ključ se može koristiti samo jednom jer se inače može dobiti ključ
> - ključ mora biti jednako velik kao i poruka
> - ne štiti integritet komunikacije (kao niti jedna šifra sama po sebi)

### Zadatak 03: Otp Saas
> Svi zadatci dostupni [ovdje](../repo/navkis_kriptografija_zadaci.zip)

- koristan python lib `pwntools`


Ključ su znakovi engleske abecede i brojevi od 0 do 9

Poruka se dobiva xor-anjem poruke i ključa bajt po bajt.

Greška u programu, isti ključ koristi se dva puta.

```python
c = flag ^ k
m = input() # user inputed message
c1 = m ^ k

c1 ^ m == m ^ k ^ m == k
```


## Kategorija 4: Neispravna upotreba inače rezumnog kriptografskog algoritma

Pristupi:
- Pronađi dio koji nije dobar
- Pronađi napad (Google, čitanje udžbenika, čitanje znanstvenih članaka, čitanje writeup-ova).
-  Pronađi ili implementiraj alat koji napada kriptosustav.


## Kategorija 5: Traži se poznavanje pojmova i implementacija
Pristupi:
- Pronađi te prilagodi, ili samo upogoni gotovu implementaciju.

Korisni alati:
- Google
- Github

# Asimetrične šifre (kriptiranje javnim ključem)
Dva ključa `pub` i `priv`
Enkripcija se radi sa `pub` ključem i dekripcija sa `priv`

## Teorija brojeva
- $N$ - pridorni broj
- $p, q$ - prosti brojevi
- $\Z_N = {0, 1, \dots, N - 1}$ - prsten u kojemu se zbraja, oduzima i množi modulo $N$
- Pišemo $a = b$ u $\Z_N$ umjesto $a \equiv b \;\;(mod N)$

Aritmetika u $\Z_N$

9 + 8 = 5 u $\Z_{12}$

5 ⋅ 7 = 11 u $\Z_{12}$

7 − 9 = 10 u $\Z_{12}$


### Prosti brojevi i najveći zajednički djelitelj
Prirodni broj je prost ako je veći od 1 i ako je djeljiv samo s brojem 1 i sa samim sobom.
- $k = nzd(x, y)$ – najveći zajednički djelitelj
- Ako je $nzd( x, y) = 1$ onda kažemo da su $x$ i $y$ relativno prosti.

>[!propozicija]
>Neka su $x$ i $y$ cijeli brojevi i neka je $k$ njihov najveći zajednički djelitelj, $k = nzd(x, y)$. Postoje cijeli brojevi $a$ i $b$ tako da vrijedi $ax + by = k$. Brojevi $a$, $b$ i $k$ se mogu efikasno odrediti proširenim Euklidovim algoritmom.



### Eulerova funkcija
Eulerova funkcija $\pi(N) = |\Z\cdot N |$ je broj prirodnih brojeva
manjih od $N$ i relativno prostih s $N$.

na primjer: $\phi(15) = 8$

>[!teorem] Eulerov teorem
> Za svaki prirodni broj $N$ i za svaki $a \in Z^*_N$ vrijedi $a^{\phi(N)} = 1$ u $\Z_N$ .

>[!teorem] Fermatov teorem
> Za svaki prosti broj $p$ i za svaki $a \in Z^*_p$ vrijedi $a^{p-1} = 1$ u $\Z_p$ .


## RSA - generiranje kljuceva
Algoritam G:
1. Odaberem velike slučajne proste brojeve $p$ i $q$
2. Izračunam $N = p \cdot q$
3. Izračunam $\phi(N) = (p − 1)(q − 1)$
4. Odaberem proizvoljni $e \in \Z^*_{\phi N}$ (u praksi 𝑒 = 65537)
5. Izračunam $d = e −1 u \Z^*_{\phi N}$
6. Javni ključ: $pk = e, N$
7. Privatni ključ: $sk = (d, N)$


>[!napomena]
> Ako je moguće $N$ efikasno rastaviti na faktore onda je RSA nesiguran.
>
> Ako je moguće efikasno izračunati $\phi(N)$ onda je RSA nesiguran

### Običan RSA - enkripcija i dekripcija
- e - javni exponent
- d - privatni exponent
- N - modul
- cyphertext i plaintext su brojevi u $\Z_N$

Algoritam E:
- $E(m, (e, N)) = m^e \text{ u } \Z_N$

Algoritam D:
- $D(c, (d, N)) = c^d \text{ u } \Z_N$

>[!note]
> $(m^e)^d = m^{ed} =m^{1+ke(N)} = m(m^{e(N)})^k \stackrel{\text{eulerov teorem}}{=} m$


#### Običan RSA nije siguran sustav kriptiranja javnim ključem
- Niti od napada poznatim izvornim tekstom.
- Niti od napada odabranim tekstom.


### Primjer 1
Kriptiramo glasove na izborima
- sudjeluju dva kandidata označeni s 1 i 2
$$E(1, pk) = 1$$
$$E(2, pk) \neq 1$$

### Primjer 2
Datoteka je enkriptirana tako da je bajt po bajt enkriptiran sa RSA.

Svaki ASCII znak može se izračunati pomoču dobivenog javnog ključa i stavljen u tablicu. Onda koristimo tu tablicu tako da gledamo originalnu poruku i uspoređujemo s podatkom u tablici.

|bajt|cypher|
|:-:|:-:|
|$0$|$0^e$|
|$1$|$1^e$|
|$2$|$2^e$|
|$\vdots$|$\vdots$|
|$255$|$255^e$|

### Primjer 3
Nepoznati ključ k (64 bit), enkriptiran je sa RSA

$$c = k^e \mod N$$
$$k = k_1\cdot k_2$$

$$
\begin{align*}
c &= (k_1k_2)^e \\
c &= k_1^ek_2^e \\
c(k_1^e)^{-1} &= k_2^e
\end{align*}
$$

Koristimo meet in the middle metodu:
|$k_1$|$c\cdot(k_1^e)^{-1}$|
|:-:|:-:|
|$0$|$\vdots$|
|$\vdots$|$\vdots$|
|$2^{32}$|$\vdots$|

```python
for k2 ... (za svaki 32 bitni k2)
  x = k2^e
  pronađi x u tablici
```


### Primjer 4
Šifriramo 128-bitni AES ključ $k$
- Koristimo 2048-bitni RSA ključ u kojem je $e = 3$
- šaljemo $c = E(k, pk)$
- Može li napadač odrediti 𝐾 na temelju javnog ključa i 𝑐?

Ponekad će se slučajno dogoditi da je $k = k_1 \cdot k_2$ gdje su $k_1$ i $k_2$ 32-bitni brojevi
$$
\begin{align*}
c &= k^e = k_1^e \cdot k_2^e \;\;\;\text{ u }\; \Z_N \\
c\cdot k^{e-1} &= k_2^e \;\;\;\text{ u }\; \Z_N \\
\end{align*}
$$
Meet-in-the-middle algoritam nalazi $k_1$ i $k_2$ u 232 koraka

## Kategorija 7: Razni napadi na RSA

Tipičan zadatak: zadan je i skriveni tekst i ključ i postupak šifriranja baziran na RSA algoritmu.
- Primjer: https://github.com/infobip/infobip-ctf-2021/tree/master/crypto/rsa_lol/attachments
- https://gitlab.com/CapTaaha/foobarctf-22/-/tree/main/crypto/new-intern/dist?ref_type=heads

Pristupi:
- Ručno pronađi matematički način da se dođe do privatnog ključa ili poruke.
- Pretraživanjem literatura pronađi točan napad.

Korisna literatura:
- https://crypto.stanford.edu/~dabo/papers/RSA-survey.pdf

Korisni alati:
- https://github.com/Ganapati/RsaCtfTool
- Sage
