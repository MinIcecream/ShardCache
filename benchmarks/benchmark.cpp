#include "../include/benchmark.h"

void Benchmark::threadRun(int num_ops) {
    std::cout<<"Thread running " << num_ops<<std::endl;
}

void Benchmark::run() {
    int OPS_PER_THREAD = NUM_OPS / NUM_THREADS;
    for (int i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back([this, OPS_PER_THREAD](){
            threadRun(OPS_PER_THREAD);
        });
    }
    for (auto& thread: threads) {
        thread.join();
    }
    std::cout<<"Done"<<std::endl;
}
