#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

std::chrono::seconds benchmarkHardDriveOperations() {
    using namespace std::chrono;
   
    const std::string filename = "benchmark_file_temp.bin";
    const long long totalBytes = 1000000000LL; // 10^9 bytes
    const int chunkSize = 100;
    const std::vector<char> buffer(chunkSize, 'A'); // Data to write
     // Prepare a file of 10^9 bytes for reading
      auto start = high_resolution_clock::now();
    {
        std::ofstream file(filename, std::ios::binary);
        for(long long i = 0; i < totalBytes; i += chunkSize) {
            file.write(buffer.data(), buffer.size());
        }
    }
     
     // Read the file in chunks of 100 bytes
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

    return duration_cast<seconds>(end - start);
}
    
int main() {
    auto duration = benchmarkHardDriveOperations();
    std::cout<< "Execution time for Hard drive operation one is "<< duration.count()<<" second"<<std::endl;
}   

