# ft_printf

## Own implementation of printf, dprintf and asprintf.

### To test:
##### 1. run Make at the root of the repository
##### 2. include "ft_printf.h" in your main .c-file
##### 3. compile your file with libftprintf.a
#### example: [ gcc your_file.c libftprintf.a -I./includes ]

### Bonuses that C library printf does not handle:


#### colours:
- eoc(end of colour)
- red
- green
- blue
- yellow
- purple
- cyan
- black
- white
<img width="351" alt="Screen Shot 2022-04-27 at 4 24 41 PM" src="https://user-images.githubusercontent.com/88145164/165528227-042b1abb-b05a-4206-ad75-068ea14fd073.png">
<img width="158" alt="Screen Shot 2022-04-27 at 4 25 36 PM" src="https://user-images.githubusercontent.com/88145164/165528345-f60e587d-a8fc-41bc-b00e-46ac79bb0a39.png">


#### %b-conversion:
- Coverts an unsigned integer into binary string, add a number after a dot for precision (zero padding).
<img width="356" alt="Screen Shot 2022-04-29 at 5 53 41 PM" src="https://user-images.githubusercontent.com/88145164/165969915-96296305-7f8d-4433-b58b-4cc5d1ffa5dd.png">
<img width="278" alt="Screen Shot 2022-04-29 at 5 54 19 PM" src="https://user-images.githubusercontent.com/88145164/165969925-747fa62d-a701-4c5b-a11c-4a5b2b6abdf7.png">

+ Banker's rounding on floats and doubles.



<img width="281" alt="Screen Shot 2022-04-27 at 4 18 29 PM" src="https://user-images.githubusercontent.com/88145164/165527008-421e79d1-559b-4e20-9fbd-a67008536f03.png">
<img width="177" alt="Screen Shot 2022-04-27 at 4 18 11 PM" src="https://user-images.githubusercontent.com/88145164/165527020-4f1c0d26-078e-4f8c-b70c-56a14d9838df.png">

