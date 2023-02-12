Replicating behaviour of printf with some own additions, such as %b (binary) and {color}.

## Colors
Colors the output using widely supported ANSI color codes. Can color the text and also background. Syntax:
```c
ft_printf("{red}%s{reset}\n", "ERROR MESSAGE HERE.");
ft_printf("{green}%s{reset}\n", "SUCCESS MESSAGE HERE.");

ft_printf("{bg_cyan}%s{reset}\n", "BACKGROUND COLOR.");
ft_printf("{bg_purple}%s{reset}\n", "BACKGROUND COLOR.");
```
<img src="https://i.imgur.com/KN7tz2d.png" alt="Colors">

Supported colors:
black, red, green, yellow, blue, purple, cyan, white
bg_black, bg_red, bg_green, bg_yellow, bg_blue, bg_purple, bg_cyan, bg_white

Color can be reset with ```reset``` or ```eoc```.

## Full IEEE 754 floating point support
Can represent any IEEE 754 floating point numbers (single to extended) with full accuracy at any given precision. This is achieved by converting exponential form of floats to division by 2-integers with own big integer libary. 
Example (single precision float 1.75f to division of 2 big integers):


    1.75f = 00111111111000000000000000000000
    [sign = 0][exponent = 01111111 = 127][mantissa = 11000000000000000000000]
    Exponent is biased by 127 (offset), so substracting 127 leaves 0 as exponent
    Mantissa is 6291456

    Equation is: (1 + [mantissa] / 2^23)2^([exponent]-127)
            = (1 + 6291456 / 2^23)2^0
            = 1 + 6291456 / 8388608 = 1.75

    The idea is to modify this equation so that it becomes a fraction of two
    integers instead of exponential form:

    (1 + [mantissa] / 2^23)2^([exponent]-127)2^0
    (1 + [mantissa] / 2^23)2^([exponent]-127)2^(23-23)
    (1 + [mantissa] / 2^23)2^([exponent]-127-23)2^23
    (2^23 + [mantissa])2^([exponent]-127-23)
    (2^23 + [mantissa]) / 2^-([exponent]-127-23)
    numerator           / denumerator

    Using same numbers as above:
    1.75f = (2^23 + 6291456) / 2^-(127-127-23) = 14680064 / 8388608 = 1.75

    single precision (float) exponent is biased by 127
    double precision (double) exponent is biased by 1023
    extended precision (long double) exponent is biased by 16383

Example of printing ```__LDBL_MIN__``` with full accuracy:

```c
ft_printf("{purple}%.16500Lf{eoc}\n", __LDBL_MIN__);
```

<img src="https://i.imgur.com/Fnobhwt.png" alt="LDBL_MIN">

## "Anybase" conversion %w
Converts an integer to any base between 2 and 62.
```c
ft_printf("Number 255 in base  2: %12.2w\n", 255);
ft_printf("Number 255 in base 10: %12.10w\n", 255);
ft_printf("Number 255 in base 16: %12.16w\n", 255);
ft_printf("Number 255 in base 36: %12.36w\n", 255);
ft_printf("Number 255 in base 37: %12.37w\n", 255);
ft_printf("Number 255 in base 62: %12.62w\n", 255);
```

<img src="https://i.imgur.com/cuWtKpe.png" alt="Anybase example">

## Binary conversion %b
Integer binary conversion with formatting flags support.
```c
ft_printf("\n{green}Binary %%b{reset}\n");
ft_printf("%b\n", 1);
ft_printf("%b\n", -1);
ft_printf("%b\n", 16777215);
ft_printf("%b\n", 44739242);

ft_printf("\n{cyan}Binary with flags{reset}\n");
ft_printf("%b%c\n", 1, '|');
ft_printf("%-10b%c\n", 1, '|');
ft_printf("%.10b%c\n", 1, '|');
ft_printf("%-#010.5b%c\n", 1, '|');
```

<img src="https://i.imgur.com/cuWtKpe.png" alt="Binary conversion">