#include "cache.h"
#include <thread>
#include <iostream>
#include <random>
#include <vector>

class Benchmark {
public:
    const int NUM_OPS = 1000000;
    const int CACHE_CAPACITY = 10000;
    const int KEY_RANGE = 100000;
    const int NUM_THREADS = 2;
    const float READ_RATIO = 0.8;
    Cache* cache;
    std::vector<std::thread> threads;

    Benchmark(Cache* cache) : cache{cache} {}

    void threadRun(int num_ops);

    void run();
};