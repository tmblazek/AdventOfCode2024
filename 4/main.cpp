#include "day4.hpp"


int main(){


    //std::vector<int> v1, v2;
    //loadVectors("../inputex1.txt", v1,v2);
    //uint64_t accum = ex1(v1,v2);
    //uint64_t similarity = ex2(v1, v2);
    lines_t v;
    loadLines("../input1.txt", v);
    std::cout << " *** AoC 2024, Day 1 *** " <<std::endl;
    std::cout << "Found XMAS:  " << ex1(v) << std::endl;
    std::cout << "Found X-MAS: " << ex2(v) << std::endl;
    
    //std::cout << std::endl << "Similarity Score: " << similarity << std::endl;

    return 0;
}