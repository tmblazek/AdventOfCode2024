#pragma once
#include "assert.h"
#include <aoc.hpp>


enum direction {
    eTop,
    eRight,
    eBottom,
    eLeft,
    eTopLeft,
    eTopRight,
    eBottomRight,
    eBottomLeft,
    eX
};

struct hit_s {
    int rowIdx;
    int colIdx;
    direction dir;
};

uint64_t testXmas(lines_t& v, std::vector<hit_s>& hits, int row, int col);
uint64_t ex1(lines_t& v)
{
    std::vector<hit_s> hits;

    for (int rowIdx = 0; rowIdx < v.size(); rowIdx++) {
        bool lastX = false;
        int colIdx = 0;
        while (!lastX) {
            colIdx = v[rowIdx].find("X", colIdx);
            if (colIdx == std::string::npos) {
                lastX = true;
                colIdx = 0;
                break;
            }
            testXmas(v, hits, rowIdx, colIdx);
            colIdx++;
        }
    }

    return hits.size();
}

uint64_t ex2(lines_t& v)
{
    std::vector<hit_s> hits;

    for (int rowIdx = 1; rowIdx < v.size()-1; rowIdx++) {
        bool lastX = false;
        int colIdx = 1;
        while (!lastX) {
            
            colIdx = v[rowIdx].find("A", colIdx);
            if (colIdx == std::string::npos || colIdx == v[rowIdx].size()-1) {
                lastX = true;
                colIdx = 0;
                break;
            }
            char data[] = {v[rowIdx-1][colIdx-1], v[rowIdx-1][colIdx+1], v[rowIdx+1][colIdx+1], v[rowIdx+1][colIdx-1]};
            int offset =0;
            for(;offset<4;offset++){
                if (data[offset]=='M' && data[(offset+1)%4] == 'M' &&
                    data[(offset+2)%4] == 'S' && data[(offset+3)%4] == 'S'){
                        hits.push_back({rowIdx, colIdx, eX});
                    }
            }
                
            colIdx++;
        }
    }

    return hits.size();
}

uint64_t testXmas(lines_t& v, std::vector<hit_s>& hits, int row, int col)
{
    std::string testfor = "XMAS";
    if (row >= (testfor.size() - 1)) { // Test Top
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row - ii][col] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eTop });
    }
    if ((row >= (testfor.size() - 1)) && (col <= (v.size() - testfor.size()))) { // Test TopRight
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row - ii][col + ii] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eTopRight });
    }

    if ((col <= (v.size() - testfor.size()))) { // Test Right
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row][col + ii] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eRight });
    }
    if ((row <= (v.size() - testfor.size())) && (col <= (v.size() - testfor.size()))) { // Test BottomRight
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row + ii][col + ii] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eBottomRight });
    }

    if ((row <= (v.size() - testfor.size()))) { // Test Bottom
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row + ii][col] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eBottom });
    }
    if ((row <= (v.size() - testfor.size())) && (col >= (testfor.size() - 1))) { // Test BottomLeft
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row + ii][col - ii] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eBottomLeft });
    }

    if ((col >= (testfor.size()-1))) { // Test Left
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row][col-ii] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eLeft });
    }
    if ((row >= (testfor.size() - 1)) && (col >= (testfor.size() - 1))) { // Test TopLeft
        bool found = true;
        for (int ii = 0; ii < testfor.size(); ii++) {
            if (v[row - ii][col - ii] != testfor[ii]) {
                found = false;
                break;
            }
        }
        if (found)
            hits.push_back({ row, col, eTopLeft });
    }
    return hits.size();
}