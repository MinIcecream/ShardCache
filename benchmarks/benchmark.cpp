#include "../include/benchmark.h"

void Benchmark::threadRun(int thread_ops) {
    std::random_device rd;
    std::mt19937 rng(rd()); //32-bit ints
    std::uniform_int_distribution<> dist(1, NUM_OPS);
    int threshold = READ_RATIO * NUM_OPS;

    int gets = 0;
    int puts = 0;

    for (int i = 0; i < thread_ops; i++) {
        int key = dist(rng);
        int rand = dist(rng);
        // put
        if (rand > threshold) {
            puts ++;
            cache->put(key, rand);
        }
        else {
            gets ++;
            cache->get(key);
        }
    }
}

void Benchmark::run() {
    int OPS_PER_THREAD = NUM_OPS / NUM_THREADS;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back([this, OPS_PER_THREAD](){
            threadRun(OPS_PER_THREAD);
        });
    }
    for (auto& thread: threads) {
        thread.join();
    }
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate duration and cast to desired units (e.g., milliseconds)
    std::chrono::duration<double, std::milli> duration = end - start;

    // Output the result
    std::cout << "Execution time: " << duration.count() << " ms" << std::endl;
}
