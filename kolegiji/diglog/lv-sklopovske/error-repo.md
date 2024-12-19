# LV Sklopovske errors

[← Natrag](.)

Ovaj file sadrži popis poznatih grešaka na koje možete naiči prilikom
uporabe Lattice Diamond alata.

## Kako tražiti greške

Prvo provjerite `Error` tab u `Output` prozoru Lattice Diamonda, ako ovdje nema
grešaka otvorite datoteku `syntax.log` (NE `syntax.log.db`) u proizvoljnom text
editoru/pregledniku (npr notepad) i tražite greške od gore prema dolje.

Unutar `syntax.log` datoteke linije sa greškom često počinju sa slovom `E`.

## Greške

- **Pogrešan Top Level Unit**

  Ova pogreška može rezultirati poznatom greškom `Error 9`, ali nije nužno.
  Moguće da sklop bude normalno sintetiziran, ali ne daje znakove života.
  Uopće ne izvodi očekivanu funkcionalnost, ledice svijetle slabim sjajem.

  Do ovoga dolazi kada u alatu imate više datoteka (`.vhd` ili `.sch`) koje nisu
  međusobno povezane, odnosno imate više od jedne datoteke u kojem je definiran
  sklop koji se ne koristi u niti jednoj drugoj datoteci.

  Kada započnete sintetiziranje sklopa Lattice Diamond će nasumično odabrati jednu
  od takvih datoteka i nju će sintetizirati. Stoga ako imate neke module koje ste
  prije napisali i više ih ne koristite moguće je da je diamond sintetizirao jedan
  od tih modula.

  Ovo možete jednostavno provjeriti, otvorite:
  `View > Reports > Process Reports > Signal/Pad`

  U tablici pogledajte stupac `Port Name`, ako se u stupcu ne nalaze poznati ulazni
  signali poput `led[x]`, `btn_right` i sl. vjerojatno se radi i ovoj grešci.

  **Otklanjanje pogreške** je jednostavno, otvorite `File List` i kliknite desni klik
  na `impl1` i zatim na `Properties` te ponovo `impl1` u prozoru koji se otvorio. U tablici
  postavite `Top-Level Unit` na ime entiteta koji želite sintetizirati.

  Ako traženi entitet nije ponuđen, moguće je da u toj datoteci imate sintaksnu pogrešku
  ili da je datoteka isključena iz implementacije.

  Ako pak **ne želite** postaviti `Top-Level Unit` možete i samo obrisati datoteku ili je
  isključiti iz implementacije.
