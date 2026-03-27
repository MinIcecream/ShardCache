#include "cache.h"
#include <thread>
#include <iostream>
#include <vector>

class Benchmark {
public:
    const int NUM_OPS = 1000000;
    const int CACHE_CAPACITY = 10000;
    const int KEY_RANGE = 100000;
    const int NUM_THREADS = 1;
    const int NUM_RUNS = 5;
    const int READ_RATIO = 80;
    Cache* cache;
    std::vector<std::thread> threads;

    Benchmark(Cache* cache) : cache{cache} {}

    void threadRun(int num_ops);

    void run();
};