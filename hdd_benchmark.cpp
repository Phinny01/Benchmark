#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

// Correcting the function return type and the duration_cast to use std::chrono::duration<double>
std::chrono::duration<double> benchmarkHardDriveOperations() {
    using namespace std::chrono;

    const std::string filename = "benchmark_file_temp.bin";
    const long long totalBytes = 1000000000LL; // 10^9 bytes
    const int chunkSize = 100; // chunk size
    const std::vector<char> buffer(chunkSize, 'A'); // Data to write

    // Prepare a file of 10^9 bytes for reading
    auto start = high_resolution_clock::now();
    {
        std::ofstream file(filename, std::ios::binary);
        for(long long i = 0; i < totalBytes; i += chunkSize) {
            file.write(buffer.data(), buffer.size());
        }
    }

    // Read the file in chunks
    {
        std::ifstream file(filename, std::ios::binary);
        std::vector<char> readBuffer(chunkSize);
        while (file.read(readBuffer.data(), readBuffer.size())) {
            // Optionally process data
        }
    }

    auto end = high_resolution_clock::now();
    // Removing the temporary file
    std::remove(filename.c_str());

    // Return the duration in seconds as a double
    return duration_cast<duration<double>>(end - start);
}

std::chrono::duration<double> benchmarkHardDriveOperations_2() {
    using namespace std::chrono;

    const std::string filename = "benchmark_file_temp.bin";
    const long long totalBytes = 1000000000LL; // 10^9 bytes
    const int chunkSize = 10000; // chunk size
    const std::vector<char> buffer(chunkSize, 'A'); // Data to write

    // Prepare a file of 10^9 bytes for reading
    auto start = high_resolution_clock::now();
    {
        std::ofstream file(filename, std::ios::binary);
        for(long long i = 0; i < totalBytes; i += chunkSize) {
            file.write(buffer.data(), buffer.size());
        }
    }
 // Read the file in chunks
    {
        std::ifstream file(filename, std::ios::binary);
        std::vector<char> readBuffer(chunkSize);
        while (file.read(readBuffer.data(), readBuffer.size())) {
            // Optionally process data
        }
    }

    auto end = high_resolution_clock::now();
    // Removing the temporary file
    std::remove(filename.c_str());

    // Return the duration in seconds as a double
    return duration_cast<duration<double>>(end - start);
   
}

int main() {
    auto duration = benchmarkHardDriveOperations();
    std::cout << "Execution time for Hard drive operation one is " << duration.count() << " seconds" << std::endl;
    auto duration_2 = benchmarkHardDriveOperations();
    std::cout << "Execution time for Hard drive operation two is " << duration_2.count() << " seconds" << std::endl;
}
