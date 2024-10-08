#include <iostream>
#include <chrono>

//32-bit int benchmark
std::chrono::duration<double> int_benchmark() {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // 10^10 additions
    int sum = 0;
    for(long long i = 0; i < 10000000000LL; ++i) {
        sum += 1; // Simple addition
    }

    // 5 x 10^9 multiplications
    int mul = 1;
    for(long long i = 0; i < 5000000000LL; ++i) {
        mul = mul * 2;
    }

    // 2 x 10^9 divisions
    int div = 1;
    for(long long i = 0; i < 2000000000LL; ++i) {
        div /= 2; // Simple division
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
    
}

//64-bit Float benchmark
std::chrono::duration<double> float_benchmark() {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();

    // 10^10 additions
    double sum = 0.0;
    for(long long i = 0; i < 10000000000LL; ++i) {
        sum += 1.0; // Simple addition
    }

    // 5 x 10^9 multiplications
    double mul = 1.0;
    for(long long i = 0; i < 5000000000LL; ++i) {
        mul *= 2.0; // Simplified operation for benchmarking
    }

    // 2 x 10^9 divisions
    double div = 1000;
    for(long long i = 0; i < 2000000000LL; ++i) {
        div /= 2.0; // Simplified operation for benchmarking
    }

    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start);
    
}

int main() {
    auto duration = int_benchmark();
    std::cout << "Total execution time of the 32 bit integer operation benchmark: " << duration.count() << " seconds" << std::endl;
    auto duration_2 = float_benchmark();
    std::cout << "Total execution time of the 64 bit floating point operation benchmark: " << duration_2.count() << " seconds" << std::endl;
}
