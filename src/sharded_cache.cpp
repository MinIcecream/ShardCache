#include "../include/sharded_cache.h"

std::optional<int> ShardedCache::get(int key) {
    size_t shardIndex = key % shardCount;
    return shards[shardIndex] -> get(key);
}

void ShardedCache::put(int key, int value) {
    size_t shardIndex = key % shardCount;
    return shards[shardIndex] -> put(key, value);
}

ShardedCache::~ShardedCache() {
    for (auto shard: shards) {
        delete shard;
    }
}