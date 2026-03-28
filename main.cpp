#include <iostream>
#include "include/single_threaded_cache.h"
#include "include/benchmark.h"

int main() {
    Cache* cache = new SingleThreadedCache(10000);
    Benchmark benchmark(cache);
    benchmark.run();
}

