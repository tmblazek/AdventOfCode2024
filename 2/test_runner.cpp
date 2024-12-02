#include "day2.hpp"

TEST(Toyinput, FileLoading)
{
    std::vector<std::vector<int>> data = loadData("../toyinput.txt");
    ASSERT_EQ(data.size(), 6);
    ASSERT_EQ(data[0].size(), 5);
    ASSERT_EQ(data[2][2], 6);
}

TEST(Toyinput, Safety){
    std::vector<std::vector<int>> data = loadData("../toyinput.txt");
    ASSERT_EQ(countSafeReports(data), 2);
}

TEST(Toyinput, SafetyWithDampener){
    std::vector<std::vector<int>> data = loadData("../toyinput.txt");
    ASSERT_EQ(countSafeReports(data, true), 4);
}