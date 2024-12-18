# Zanimljive VHDL provale

**Kakav sam počeo, takav ću i završiti**

Sljedeći blok će **rezultirati povećanjem R za 1**. Svaka naredba će
se normalno izvršiti, ali R koji se nalazi sa desne strane naredbe
`<=` u drugom retku neće poprimiti vrijednost koja je dodjeljena u prvom
već će imati vrijednost koju je R imao na početku bloka. Stoga će sve 3 naredbe
dodijeliti istu vrijednost signalu R.
```vhdl
process(R)
begin

if falling_edge(clk_key) then
    R <= R + x"1";
    R <= R + x"1";
    R <= R + x"1";
endif;

end process;
```
