library ieee;
use ieee.std_logic_1164.all;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;


entity debouncer is
    port (
	key, clk: in std_logic;
	debounced: out std_logic
    );
end debouncer;

architecture x of debouncer is
    signal R_debounce_cnt: integer;
    signal R_key_sync, R_key_last: std_logic;

begin
    process(clk)
    begin
	if rising_edge(clk) then
	    R_key_sync <= key;
	    if R_key_last /= R_key_sync then
		R_debounce_cnt <= R_debounce_cnt - 1;
		if R_debounce_cnt < 0 then
		    R_key_last <= R_key_sync;
		end if;
	    else
		R_debounce_cnt <= 500000; -- 20 ms @ 25 MHz
	    end if;
	end if;
    end process;

    debounced <= R_key_last;
end;
