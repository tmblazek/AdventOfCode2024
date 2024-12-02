#pragma once
#include <aoc.hpp>

uint64_t ex1(std::vector<int>& l1, std::vector<int>& l2)
{
    stable_sort(l1.begin(), l1.end());
    stable_sort(l2.begin(), l2.end());
    uint64_t accum = 0;
    for (int ii = 0; ii < l1.size(); ii++) {
        accum += abs(l1[ii] - l2[ii]);
    }
    return accum;
}

uint64_t ex2(std::vector<int>& l1, std::vector<int>& l2)
{
    std::unordered_map<uint64_t, uint64_t> lut;
    for (auto& a : l2) {
        lut[a]++;
    }

    uint64_t accum = 0;
    for (auto& a : l1) {
        accum += a * lut[a];
    }
    return accum;
}