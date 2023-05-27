#include <iostream>
#include <vector>

#include "libs/catch_amalgamated.hpp"
#include "gf.h"

TEST_CASE("Sum is computed", "[gf_add]")
{
    REQUIRE(gf_add(7, 7) == 0);
    REQUIRE(gf_add(5, 6) == 3);
}

TEST_CASE("Sub is computed", "[gf_sub]")
{
    REQUIRE(gf_sub(11, 11) == 0);
    REQUIRE(gf_sub(0, 7) == 7);
    REQUIRE(gf_sub(14, 10) == 4);
    REQUIRE(gf_sub(10, 14) == 4);
}

TEST_CASE("Mul is computed", "[gf_mul]")
{
    // x^4 + x + 1 = 0
    const gf_element mod = 19;

    REQUIRE(gf_mul(0, 0, mod) == 0);
    REQUIRE(gf_mul(0, 1, mod) == 0);
    REQUIRE(gf_mul(11, 14, mod) == 8);
    REQUIRE(gf_mul(7, 6, mod) == 1);
}

TEST_CASE("Exp is computed", "[gf_exp]")
{
    const gf_element mod = 19;

    REQUIRE(gf_exp(7, 0, mod) == 1);
    REQUIRE(gf_exp(7, 1, mod) == 7);
    REQUIRE(gf_exp(7, 3, mod) == 1);
    REQUIRE(gf_exp(2, 15, mod) == 1);
}

TEST_CASE("Div is computed", "[div]")
{
    gf_element quo, rem;

    div(13, 13, quo, rem);
    REQUIRE((quo == 1 && rem == 0));

    div(1, 13, quo, rem);
    REQUIRE((quo == 0 && rem == 1));

    div(13, 1, quo, rem);
    REQUIRE((quo == 13 && rem == 0));
}

TEST_CASE("Generate galois field index table")
{
    const int n = 15;
    gf_element mod   = 19;
    gf_element alpha = 0x02;
    gf_element next  = 0x01;
    std::vector<gf_element> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back(next);
        next = gf_mul(next, alpha, mod);
    }

    std::vector<gf_element> dataset = {
        1, 2, 4, 8, 3, 6, 12, 11,
        5, 10, 7, 14, 15, 13,  9
    };

    for (size_t i = 0; i < n; i++)
    {
        REQUIRE(v[i] == dataset[i]);
    }
}
