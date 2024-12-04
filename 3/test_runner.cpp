#include "day3.hpp"

TEST(Toyinput, ex1)
{
    lines_t v;
    FSM fsm(false);
    loadLines("../toyinput.txt", v);
    uint64_t total = fsm.readline(v[0]);
    ASSERT_EQ(total, 161);
}
TEST(Toyinput, ex2)
{
    lines_t v;
    FSM fsm(true);
    loadLines("../toyinput2.txt", v);
    uint64_t total = fsm.readline(v[0]);
    ASSERT_EQ(total, 48);
}