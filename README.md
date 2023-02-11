# ft_printf
Replicating behaviour of printf with some own additions, such as %b (binary) and {color}.

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
