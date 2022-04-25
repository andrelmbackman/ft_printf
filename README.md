# ft_printf

Own implementation of printf, dprintf and asprintf.

Bonuses that printf does not handle:

%b-conversion:
- coverts an unsigned integer into binary string.

*-flag:
- use the asterisk to specify field width or precision in the argument preceding the conversion
example: ft_printf("%*s", 20, "Hello World!");

colours:
- eoc(end of colour)
- red
- green
- blue
- yellow
- purple
- cyan
- black
- white
example: ft_printf("{purple}Hello World!");
