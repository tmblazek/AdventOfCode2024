#pragma once
#include "assert.h"
#include <aoc.hpp>
#include <math.h>

typedef std::vector<std::vector<int>> reportGrid_t;

reportGrid_t loadData(std::string fname) {
  reportGrid_t out;
  std::vector<std::string> v;
  loadLines(fname, v);

  for (auto &it : v) {
    std::vector<int> newV;
    int offset = 0, pos;
    while (std::string::npos != (pos = it.find(" ", offset))) {
      newV.push_back(stoi(it.substr(offset, pos - offset)));
      offset = pos + 1;
    }
    newV.push_back(stoi(it.substr(offset, it.size() - offset)));
    out.push_back(newV);
  }
  return out;
}

bool singleIsSafe(std::vector<int> &it) {

  bool isSafe = true;
  int lastSign = sgn<int>(it[1] - it[0]);
  int lastValue = it[0];
  for (int ii = 1; ii < it.size(); ii++) {

    int newSign = sgn<int>(it[ii] - lastValue);
    if (((ii > 1) && (newSign != lastSign)) || (newSign == 0) ||
        (abs(it[ii] - lastValue) > 3)) {
      isSafe = false;
      break;
    }
    lastValue = it[ii];
    lastSign = newSign;
  }
  return isSafe;
}
uint64_t countSafeReports(reportGrid_t input, bool dampener = false) {
  uint64_t cntSafe = 0;
  int wtf = 0;
  for (auto &it : input) {
    bool safe = false;
    int tripIdx, dummy;
    if (singleIsSafe(it)) {
      safe = true;
    } else if (dampener) {
      for (int ii = 0; ii < it.size(); ii++) {
        std::vector<int> redvec(0);
        for (int jj = 0; jj < it.size(); jj++) {
          if (ii != jj)
            redvec.push_back(it[jj]);
        }
        if (singleIsSafe(redvec)) {
          safe = true;
          break;
        }
        
        
      }if (!safe) std::cout << wtf << std::endl;
      
    }
    if (safe)
      cntSafe++;
    wtf++;
  }
  return cntSafe;
}
