#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

std::chrono::milliseconds benchmarkHardDriveOperations() {
    using namespace std::chrono;
    const std::string filename = "benchmark_file_temp.bin";
    const long long totalBytes = 1000000000LL; // 10^9 bytes
    const int chunkSize = 100;
    const std::vector<char> buffer(chunkSize, 'A'); // Data to write
}
