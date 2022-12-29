
#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "dsa.h"
#include "list.h"
#

TEST_CASE("Testing NULL input in list", "[single-file]")
{
    REQUIRE(list_create(NULL, 10) == DSA_INVALID_ARG)
}