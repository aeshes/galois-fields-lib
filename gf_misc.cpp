#include "gf_misc.h"

int bit_length(gf_element a)
{
    int length = 0;

    while (a > 0)
    {
        length++;
        a >>= 1;
    }

    return length;
}

int degree(gf_element a)
{
    if (a == 0)
        return -1;
    else
        return bit_length(a) - 1;
}
