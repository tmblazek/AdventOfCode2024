#include "day3.hpp"


int main(){
    lines_t v;
    loadLines("../input1.txt", v);
    
    std::cout << " *** AoC 2024, Day 3 *** " <<std::endl;
    std::cout << "Ex1: " << ex1(v) << std::endl;
    std::cout << "Ex2: " << ex2(v) << std::endl;
    return 0;
}