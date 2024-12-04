#include "day4.hpp"

TEST(Toyinput, Counting)
{
    lines_t v;
    loadLines("../toyinput.txt", v);
    ASSERT_EQ(ex1(v), 18);
}


TEST(Toyinput, Counting2)
{
    lines_t v;
    loadLines("../toyinput2.txt", v);
    ASSERT_EQ(ex1(v), 4);
}

TEST(Toyinput, Counting3)
{
    lines_t v;
    loadLines("../toyinput3.txt", v);
    ASSERT_EQ(ex1(v), 8);
}

TEST(Toyinput, Counting4)
{
    lines_t v;
    loadLines("../toyinput4.txt", v);
    ASSERT_EQ(ex1(v), 8);
}
TEST(Single, bottom)
{
    lines_t v;
    loadLines("../bottom.txt", v);
    ASSERT_EQ(ex1(v), 6);
}

TEST(Single, top)
{
    lines_t v;
    loadLines("../top.txt", v);
    ASSERT_EQ(ex1(v), 6);
}

TEST(Single, right)
{
    lines_t v;
    loadLines("../right.txt", v);
    ASSERT_EQ(ex1(v), 6);
}

TEST(Single, left)
{
    lines_t v;
    loadLines("../left.txt", v);
    ASSERT_EQ(ex1(v), 6);
}
TEST(Toyinput, ex2)
{
    lines_t v;
    loadLines("../toyex2.txt", v);
    ASSERT_EQ(ex2(v), 9);
}
