#include <iostream>
#include <chrono>
#include <vector>

// Memory Benchmark Function
auto memoryBenchmark() {
    using namespace std::chrono;
    const long long numElements = 5000000000LL; // 5 x 10^9 elements

    // Allocate memory: Using vector for RAII and simplicity. Each element is 4 bytes.
    std::vector<int> array(numElements, 0); // Initialize all elements to 0.

}
 