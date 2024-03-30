#include <iostream>
#include <chrono>
#include <climits>

auto int_benchmark() {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // 10^10 additions
   volatile int sum = 0; // Use volatile to discourage optimization
    for(long long i = 0; i < 10000000000LL; ++i) {
        sum += 1; // Simple addition
    }

    // 5 x 10^9 multiplications, corrected to prevent overflow
  volatile int mul = 1;
    for(long long i = 0; i < 5000000000LL; ++i) {
        mul = mul * 2;
    }

    // 2 x 10^9 divisions, corrected to do something trivial but not optimized away
  volatile int div = 1;
    for(long long i = 0; i < 2000000000LL; ++i) {
        div /= 2; // Simple division
    }

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    return duration;
}

int main() {
    auto duration = int_benchmark();
    std::cout << "Total execution time of the benchmark: " << duration.count() << " seconds" << std::endl;
}

