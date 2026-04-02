#include <iostream>
#include "include/single_threaded_cache.h"
#include "include/benchmark.h"
#include "include/simple_mutex_cache.h"
#include "include/sharded_cache.h"

int main() {
    size_t cacheCapacity = 10000;
    Cache* cache = new ShardedCache(cacheCapacity, 4);
    // Cache* cache = new SingleThreadedCache(cacheCapacity);
    Benchmark benchmark(cache);
    benchmark.run();
}

