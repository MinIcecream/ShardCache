#include <iostream>
#include "include/cache.h"
#include "include/benchmark.h"

int main() {
    Cache* cache = new Cache(10000);
    Benchmark benchmark(cache);
    benchmark.run();
}

