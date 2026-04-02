#include <iostream>
#include "include/benchmark.h"
#include "include/simple_mutex_cache.h"
#include "include/sharded_cache.h"
#include "include/single_threaded_cache.h"

int main() {
    const size_t cacheCapacity = 10000;
    const int threads = 2;

    std::cout << "SingleThreadedCache" << std::endl;
    {
        Cache* cache = new SingleThreadedCache(cacheCapacity);
        Benchmark benchmark(cache, 1);
        benchmark.run();
        delete cache;
    }

    std::cout << "SimpleMutexCache (global lock)" << std::endl;
    {
        Cache* cache = new SimpleMutexCache(cacheCapacity);
        Benchmark benchmark(cache, threads);
        benchmark.run();
        delete cache;
    }

    for (int shardCount : {2, 4, 8, 16, 32, 64, 128, 256, 512}) {
        std::cout << "ShardedCache (" << shardCount << " shards)" << std::endl;
        Cache* cache = new ShardedCache(cacheCapacity, shardCount);
        Benchmark benchmark(cache, threads);
        benchmark.run();
        delete cache;
    }
}

// to compile: g++ src/sharded_cache.cpp main.cpp src/simple_mutex_cache.cpp src/single_threaded_cache.cpp benchmarks/benchmark.cpp -o main -std=c++17