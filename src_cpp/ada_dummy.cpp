#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

int dump_random_to_file_pgm8 (const std::vector<unsigned char>& mem, 
                              const unsigned int offset,
                              const unsigned int width,
                              const unsigned int height,
                              const std::string& filename){
    int r = 0;
    const std::string comment = "sec_elec_pgm8";
    std::ofstream file (filename, std::ios::binary);
    if (file.is_open()){
        file << "P5\n#" << comment << "\n" << width << " " << height << "\n" << 255 << "\n";
        unsigned int length = width*height;
        if (offset + length <= mem.size()){
            file.write(reinterpret_cast<const char*>(&mem[offset]), length);
        } else {
            r = -1; // Error: Offset and length exceed buffer size
        }
        file.close();
    } else {
        r = -1; // Error opening the file
    }
    return r;
}

std::vector<unsigned char> create_random_buffer(size_t size){
    std::vector<unsigned char> output_buff(size);
    // Set up a random number generator
    std::random_device rd; // Seed for the random number generator
    std::mt19937 gen(rd()); // Mersenne Twister random number generator
    std::uniform_int_distribution<> dis(0,255); // Uniform distribution between 0 and 255

    // Fill the vector with random unsigned char values
    for (auto& value : output_buff){
        value = static_cast<unsigned char>(dis(gen));
    }

    std::cout<<"Buffer size: "<<static_cast<unsigned int>(output_buff.size())<<std::endl;
    return output_buff;
}







