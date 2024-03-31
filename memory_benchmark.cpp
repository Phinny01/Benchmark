#include <iostream>
#include <chrono>
#include <vector>

// Memory Benchmark Function
auto memoryBenchmark() {
    using namespace std::chrono;
    const long long numElements = 5000000000LL; // 5 x 10^9 elements

    // Allocate memory: Using vector for RAII and simplicity. Each element is 4 bytes.
    std::vector<int> array(numElements, 0); // Initialize all elements to 0.

 auto start = high_resolution_clock::now();


// Read from each array element
    int sink; 
    for(long long i = 0; i < numElements; ++i) {
        sink = array[i];
    }
    
    // Write to each array element
    for(long long i = 0; i < numElements; ++i) {
        array[i] = i % 100; // Example write operation
    }

    

  auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    return duration;
}

int main() {
        auto duration = memoryBenchmark();
        std::cout << "Total execution time of the memory benchmark: " << duration.count() << " seconds" << std::endl;

}
 