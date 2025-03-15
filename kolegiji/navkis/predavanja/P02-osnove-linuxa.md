[← Natrag](..)

# Osnove Linuxa

- Najbitnije zadaće
  - Uspostavljanje korisničkog sučelja
  - Apstrahiranje implementacijskih detalja

- OS je posrednik između aplikacije i hardvera

- Jezgra operacijskog sustava

- UNIX
  - Unix je zaštićen znak
  - Linux je unixoid (jer ne placa licencu)

- Prva verzija 14.03.1994. (na dan broja $\pi$)

## Terminal i ljuska
"Uređaj" koji prima znakove u prikazuje ispis
 - Nekada su bili fizicki uređaji
 - Danas aplikacije oponasaju fizicke terminale

Emulatori
 - kitty
 - xterm
 - rxvt
 - gnome-terminal
 - ghost terminal

Terminali upravljaju unosom i ispisom znakova

Ljuska priča sa operacijskim sustavom:
 - bash
 - fish
 - zhs

## Osnovne naredbe
`man`
 - "upute", (engl. manual) za bilo koju aplikaciju
 - pr. (`man ls`) -> upute za aplikaciju `ls`

`cd [dir]`
 - engl. change directory
 - mijenja trenutni direktorij u `[dir]`
 - više riječi spojiti tako da stavimo u navodnike

 `pwd`
 - ispisuje trenutni direktorij

`touch [ime]`
 - kreira file `[ime]`

 `rmdir [ime]`
 - briše direktorij `[ime]`

`rm [ime]`
 - briše datoteku `[ime]` (ili direktorij ovisno o flagovima)

 `echo "[text]"`
 - ispisuje `[text]`

`cp [dat] [path]`
 - kopira datoteku `[dat]` na putanju `[path]`


## Apsolutne i relativne staze
- Apsolutne počinju sa / (npr. /home/user/file.txt odnosi se na jedan file)
- Relativne adrese pocinju sa `.`, `..` ili imenom datoteke (npr. ako smo u `/home/user` i napisemo `file.txt` odnosimo se na `/home/user/file.txt`, ali ako smo u `/dir1/dir2` i napisemo `file.txt`, odnosimo se na file `/dir1/dir2/file.txt`)

## Vanjski file sustav

`lsblk` -> ispis spojenik diskova

`mount` -> moze mounitat disk na bilo koje mjesto na sustavu

`udiskctl mount -b [disk]` -> mounta `[disk]` na file sustav

## Korištenje tipke <TAB>

Kliknuti tab 2 puta da ispis svih opcija

Kliknuti tab za nadopunu trenutno napisane komande

CTRL + U -> briše trenutno napisanu komandu

CTRL + E -> exit

CTRL + C -> pošalje SYSINT za kašenje trenutno pokrenute aplikacije

## još par naredbi

`cat [file]`
 - ispisuje sadržaj datoteke `[file]` na `stdout`

 `head -n [n] [file]`
 - ispisuje prvih `[n]` linija datoteke `[file]`

 `tail [file]`
 - ispisuje zadnjih n linija datoteke `[file]`

 `df`
 - ispisuje zauzeće diska po particiji

 `du -sh`
 - ispisuje zauzeće diska po direktoriju (-s sažme i -h pretvori iz bytova u kB, MB, GB, TB)

 `stat [file ili dir]`
 - Ispisuje statistiku te datoteke
 - MAC vremena (modified, accesed, changed)

 `sudo apt install neofetch`
 `sudo pacman -S neofetch`
 - instalira aplikaciju neofetch

 `ping [adresa ili domena]`
 - šalje ping poruke na adresu ili domenu (npr. www.google.com)

 `curl [adresa ili domena (npr. www.google.com)]`
 - "ode na tu adresu" i povuče podatke sa stranice

 `jq`
 - prima hrpu json texta i uljepša ga

 `wc [file]`
 - broji riječi u datoteci `file` ili linije sa opcijom `-l`

 `which [naredba]`
 - pokazuje koju datoteku pokreće naredba

 `whereis [naredba]`
 - pokazuje gdje se nalazi izvorni kod naredbe

 `find`
 - pretraživanje datotečnog sustava

 `grep`
 - traži znakove u svomjim ulaznim podatcima
 - npr. `ls | grep .txt`


## Redirekcija
 Operator `>`
  - Uzima izlaz naredbe prije operatora i stavlja ju u file nakon njega
  - npr. `ls > file.txt`, sada će `file.txt` sadržati sadržaj trenutnog direktorija

  - Broj ispred `[n]>`, `1>` je default i to je `stdout`, `2>` je za preusmjeravanje grešaka i `&>` je za preusmjeravanje teksta i grešaka.

 Operator `<` preusmjerava sav tekst datoteke u naredbu
 Operator `<<[end]` heredoc
  - preusmjerava u naredbu sve dok se ne upiše `[end]`

 `/dev/null` -> za poslati neženjeni output


## Ovlasti

pokretanjem naredbe `ls -l`
prvi znak je tip datoteke (c -> character device, d -> directory)

ostalih 9 su ovlasti:
 - prve tri za onoga tko je napravio datoteku
 - druga tru za grupu onoga tko je napravio datoteku
 - zadnja tri za sve ostale

primjer. `-rwxr-xr--` znači da je ovo normalna datoteka (`-`) kojoj njen vlasnik ima ovlasti (`rwx` -> read write i execute), grupa ima ovlasti (`r-x` -> read i execute i svi ostali samo read)


Mijenjanje ovlasti:
 - `chmod [flag] [file]` daje ovlasti file-u s obzirom na flag
 - `chown [flag] [file]` mijenja vlasnika file-a s obzirom na flag

Root:
 - UID(User ID) = 0
 - Ima ovlasti raditi SVE
 - Privremeno raditi kao root -> naredba `sudo`
 - trajno prebacivanje na root -> `su -` (switch user)


## Grupe

Za pokazat kojoj grupi pripada trenutni korisnik `groups`

`whomai` -> kao koji si korisnik ulogiran

`who` -> tko sve koristi trenutnu mašinu

`w` -> tko sve koristi trenutnu mašinu (više informacija)

- `adduser` - dodavanje usera
- `passswd` - mijenjanje šifre usera
- `usermod` - mijenjanje grupa u kojima je user
- `deluser` - brisanje usera
- `newgrp` - kreacija nove grupe

## Sudo

Sučelje za dobivanje administrativnih prava

Pravila definirana u `/etc/sudoers` i uređuje se sa `visudo`


## Procesi

Za ispis svih pokrenutih procesa `ps`

Načešće se koristi `ps aux`


## Signali
`man 7 signal` za listu svih signala.

SIGINT  -> CTRL+C, gasi proces, može se sprijčit

SIGKILL -> ubije proces (ne može se uhvatiti)

SIGSTOP -> suspendira proces

```bash
trap "echo Try harder" SIGINT SIGSTOP

while

elihw
```

može se ubiti sa `killall -KILL skripta.sh`

## Wildcards

`*` -> bilo koji znakovi

`?` -> jedan bilo koji znak

`[A-Z]` -> interval svih slova od A do Z

Za ispis svih file-ove u folderu:
```bash
echo *
```


Za ispis svih hidden file-ova:
```bash
echo .*
```


Za ispis svih koji završavaju sa `v`:
```bash
echo *v
```

Kreiranje file-ova `file00.txt` do `file15.txt`:
```bash
touch file{00..15}.txt
```


## Grep

Alat za pretraživanje teksta.

Korisni flagovi:
 - `-i` -> ignorira case
 - `-v` -> obrne uvijet
