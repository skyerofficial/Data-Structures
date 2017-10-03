
#include "catch.hpp"
#include "Hider.h"
#include "hider.cpp"
TEST_CASE("Count Bull And Cows"){
Hider hider;
SECTION("Positive Scenario"){
    int *arr = hider.getBullsCowsCount("globe","slack");
    REQUIRE (arr[0]==1);
    REQUIRE (arr[1]==0);
}

}

