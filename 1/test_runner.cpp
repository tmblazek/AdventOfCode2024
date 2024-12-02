#include "day1.hpp"

TEST(Toyinput, FileLoading)
{
    std::vector<int> v1, v2;
    loadVectors("../toiinput.txt", v1, v2);
    ASSERT_EQ(v1.size(), 6);
    ASSERT_EQ(v2.size(), 6);
    ASSERT_EQ(v2[4], 9);
}

TEST(Toyinput, Counting)
{
    std::vector<int> v1, v2;
    loadVectors("../toiinput.txt", v1, v2);
    uint64_t accum = ex1(v1, v2);
    ASSERT_EQ(accum, 11);
}

TEST(Toyinput, SimilarityScore)
{
    std::vector<int> v1, v2;
    loadVectors("../toiinput.txt", v1, v2);
    uint64_t accum = ex2(v1, v2);
    ASSERT_EQ(accum, 31);
}