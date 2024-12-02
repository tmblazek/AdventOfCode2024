#include "day2.hpp"


int main(){

    std::cout << "AoC 2024, Day 2" << std::endl;
    std::cout << "Safety Analysis:               " << countSafeReports(loadData("../input1.txt")) << std::endl;
    std::cout << "Safety Analysis with Dampener: " << countSafeReports(loadData("../input1.txt"), true) << std::endl;
    return 0;
}