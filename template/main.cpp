#include "day1.hpp"


int main(){


    std::vector<int> v1, v2;
    loadVectors("../inputex1.txt", v1,v2);
    uint64_t accum = ex1(v1,v2);
    uint64_t similarity = ex2(v1, v2);
    std::cout << " *** AoC 2024, Day 1 *** " <<std::endl;
    std::cout << "Accumulated Diffs: " << accum << std::endl;
    
    std::cout << std::endl << "Similarity Score: " << similarity << std::endl;

    return 0;
}