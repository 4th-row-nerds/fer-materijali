# LV04

[← Natrag](..) | [Files](_)

## Postupak rješavanja

Slijedi objašnjenje i postupak rješavanja svakog od zadataka iz vježbe.

### Zadatak 1

Kreirajte novi direktorij u kojem ćete pohraniti sve datoteke ove laboratorijske vježbe,
u njega odmah kopirajte datoteke `count.vhd` i `debouncer.vhd` koje ste preuzeli sa weba.
Osim toga iz prošle vježbe kopirajte i LPF datoteku za vaš tip pločice `ulx2s.lpf` / `ulx3s.lpf`.

Otvorite Lattice Diamond i kreirajte novi projekt, kao direktorij projekta odaberite odaberite
onaj koji ste kreirali.

U koraku Add Source dodajte datoteke koje ste ranije kopirali, ne zaboravite LPF datoteku,
kako bi postala vidljiva promijenite `Files of type` polje.
Također obavezno odaberite `Synplify` Pro u koraku Select Synthesis Tool.

Zamijenite blok proces kako je traženo:
```vhdl
library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;

entity count is
    port (
	clk_25m: in std_logic;
	btn_down: in std_logic;
	sw: in std_logic_vector(3 downto 0);
	led: out std_logic_vector(7 downto 0)
    );
end count;

architecture x of count is
    signal R, delta: std_logic_vector(31 downto 0);

begin
    R <= R + delta when rising_edge(clk_25m);
    delta <= x"0000000" & sw;

    led <= R(31 downto 24) when btn_down = '0' else R(23 downto 16);
end x;
```

Gore navedeni sklop prilikom svakog clock ciklusa (kod rastućeg brida CLK signala)
signalu `R` probraja vrijednost signala `delta` koja se podešava prekidačima na
pločici. Najtežih 8 binarnih znamenki prikazano je LED diodama na pločici, pritiskom na
tipku `btn_down` diode prikazuju sljedećih 8 bita, nižih 16 bita nije prikazano.

### Zadatak 2

To ćemo jednom u budučnosti...