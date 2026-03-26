#define CATCH_CONFIG_MAIN

#include "../include/cache.h"
#include "catch_amalgamated.hpp"
#include <optional>

TEST_CASE("throws on zero capacity", "[cache]") {
    REQUIRE_THROWS_AS(Cache(0), std::invalid_argument);
}

TEST_CASE("can put and get", "[cache]") {
    Cache cache(2);

    cache.put(2, 3);

    std::optional<int> value = cache.get(2);
    REQUIRE(value.has_value());
    REQUIRE(value.value() == 3);
}

TEST_CASE("evicts the lru key", "[cache]") {
    Cache cache(2);

    cache.put(2, 7);
    cache.put(3, 8);
    cache.put(4, 9);


    std::optional<int> value = cache.get(2);
    REQUIRE(!value.has_value());

    std::optional<int> value2 = cache.get(3);
    std::optional<int> value3 = cache.get(4);
    REQUIRE(value2.value() == 8);
    REQUIRE(value3.value() == 9);
}

TEST_CASE("updates existing key", "[cache]") {
    Cache cache(2);

    cache.put(2, 6);
    cache.put(3, 7);
    cache.put(2, 8);
    cache.put(4, 9);

    std::optional<int> value = cache.get(2);
    std::optional<int> value2 = cache.get(3);
    
    REQUIRE(value.value() == 8);
    REQUIRE(!value2.has_value());
}