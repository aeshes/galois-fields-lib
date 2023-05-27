#include "libs/catch_amalgamated.hpp"
#include "gf_misc.h"

TEST_CASE("Bit length computed", "[bit_length]")
{
    REQUIRE(bit_length(0) == 0);
    REQUIRE(bit_length(1) == 1);
    REQUIRE(bit_length(15) == 4);
    REQUIRE(bit_length(12) == 4);
    REQUIRE(bit_length(3) == 2);
    REQUIRE(bit_length(9) == 4);
}

TEST_CASE("Degree computed", "[degree]")
{
    REQUIRE(degree(0) == -1);
    REQUIRE(degree(1) == 0);
    REQUIRE(degree(3) == 1);
    REQUIRE(degree(6) == 2);
    REQUIRE(degree(12) == 3);
}
