#include "gf.h"
#include "gf_misc.h"

gf_element gf_add(gf_element a, gf_element b)
{
    return a ^ b;
}

gf_element gf_sub(gf_element a, gf_element b)
{
    return a ^ b;
}

gf_element gf_mul(gf_element a, gf_element b, gf_element mod)
{
    gf_element result = 0;

    int deg = degree(mod);

    while (a != 0)
    {
        if (a & 1)
            result ^= b;
        a >>= 1;
        b <<= 1;
        if (degree(b) == deg)
            b ^= mod;
    }

    return result;
}

gf_element gf_exp(gf_element a, int exp, gf_element mod)
{
    gf_element result = 1;

    while (exp != 0)
    {
        if (exp & 0x01)
            result = gf_mul(result, a, mod);
        a = gf_mul(a, a, mod);
        exp >>= 1;
    }

    return result;
}

void div(gf_element a, gf_element b, gf_element & quo, gf_element & rem)
{
    rem = a;
    quo = 0;

    while (degree(rem) >= degree(b))
    {
        int power = degree(rem) - degree(b);

        rem ^= b << power;
        quo ^= 1 << power;
    }
}
