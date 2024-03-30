#include <iostream>
#include <chrono>
int main() {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  int sum = 0;// 10^10 additions
  for(long long i = 0; i < 10000000000LL; ++i) {
      sum += 1;// Simple addition
  }
  // 5 x 10^9 multiplications
  int  mul = 1;
  for(long long i = 0; i < 5000000000LL; ++i) {
      mul *= 2; // Simplified operation for benchmarking
  }
}