#include <iostream>
#include "include/single_threaded_cache.h"
#include "include/benchmark.h"
#include "include/simple_mutex_cache.h"

int main() {
    Cache* cache = new SimpleMutexCache(10000);
    Benchmark benchmark(cache);
    benchmark.run();
}

