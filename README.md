A simple multithreaded LRU cache.

Benchmarks:
1M operations
Key space: 100k
Cache size: 10k
Read/write ratio: 80% read, 20% write

Access Patterns:
Random distribution
80% of operations use 20% of keys (hotspot)

Threaded tests:
1, 4, 8, 16 threads

Metrics:
Hit rate
Ops/sec

Cache versions:
1. single thread
2. Global mutex
3. Sharded mutex
