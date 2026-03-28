#pragma once
#include <optional>

class Cache {
    public:

    virtual ~Cache() = default;
    virtual std::optional<int> get(int key) = 0; // optional to account for cache misses
    virtual void put(int key, int value) = 0; // assume put never fails
};