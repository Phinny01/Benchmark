#include <iostream>
#include <chrono>
int main() {
  using namespace std::chrono;
  auto start = high_resolution_clock::now();
  int sum = 0;// 10^10 additions
  for(long long i = 0; i < 10000000000LL; ++i) {
      sum += 1;// Simple addition
  }
}