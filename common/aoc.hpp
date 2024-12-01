#pragma once
#include "assert.h"
#include <algorithm>
#include <cstdint>
#include <fstream>
#include <gtest/gtest.h>
#include <iostream>
#include <unordered_map>
#include <vector>
void loadVectors(std::string fname, std::vector<int>& l1, std::vector<int>& l2)
{
    std::ifstream indata(fname);
    assert(indata.is_open());
    std::string w1, w2;
    for (std::string line; getline(indata, line);) {
        int splitpos = line.find("  ");
        l1.push_back(stoi(line.substr(0, splitpos)));
        l2.push_back(stoi(line.substr(splitpos + 3, line.size() - 3 - splitpos)));
    }
}
