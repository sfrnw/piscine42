#include <unistd.h>

unsigned char reverse_bits(unsigned char b)
{
    unsigned char r = 0;  // Result variable to store reversed bits
    unsigned char_len = 8;  // Number of bits in a char (8 bits)

    while (char_len--)
    {
        // Multiply r by 2 (equivalent to left shift by 1) and add the least significant bit of b
        r = (r * 2) + (b & 1);
        
        // Divide b by 2 (equivalent to right shift by 1)
        b /= 2;
    }
    return (r);
}

