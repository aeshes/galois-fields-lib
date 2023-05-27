#ifndef GF_H
#define GF_H

#include <cstdint>

using gf_element = uint8_t;

gf_element gf_add(gf_element a, gf_element b);
gf_element gf_sub(gf_element a, gf_element b);
gf_element gf_mul(gf_element a, gf_element b, gf_element mod);
gf_element gf_div(gf_element a, gf_element b, gf_element mod);
gf_element gf_exp(gf_element a, int exp, gf_element mod);

void div(gf_element a, gf_element b, gf_element & quo, gf_element & rem);

#endif // GF_H
