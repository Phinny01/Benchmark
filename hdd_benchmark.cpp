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
     // Prepare a file of 10^9 bytes for reading
    {
        std::ofstream file(filename, std::ios::binary);
        for(long long i = 0; i < totalBytes; i += chunkSize) {
            file.write(buffer.data(), buffer.size());
        }
    }
      auto start = high_resolution_clock::now();
     // Read the file in chunks of 100 bytes
    {
        std::ifstream file(filename, std::ios::binary);
        std::vector<char> readBuffer(chunkSize);
        while (file.read(readBuffer.data(), readBuffer.size())) {
            // Optionally process data
        }
    }
    
    
}
