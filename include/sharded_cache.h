
#pragma once
#include <optional>
#include "simple_mutex_cache.h"
#include "vector"

class ShardedCache: public Cache{
    size_t capacity;
    int shardCount;
    std::vector<Cache*> shards;

    public:
    ~ShardedCache();
    ShardedCache(size_t capacity, int shardCount): capacity{capacity}, shardCount{shardCount} {
        if (capacity < 1) {
            throw std::invalid_argument("Capacity must be >0!");
        }
        if (shardCount < 1) {
            throw std::invalid_argument("Shards must be >0!");
        }
        int shardCapacity = capacity / shardCount;
        for (int i = 0; i < shardCount; i++) {
            Cache* shard = new SimpleMutexCache(shardCapacity);
            shards.push_back(shard);
        }
    }
    std::optional<int> get(int key) override; // optional to account for cache misses
    void put(int key, int value) override; // assume put never fails
};