//
//  Combinations.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/14.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Combinations.hpp"

/**
 Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
 
 You may return the answer in any order.
 
 Input: n = 4, k = 2
 Output:
 [
   [2,4],
   [3,4],
   [2,3],
   [1,2],
   [1,3],
   [1,4],
 ]
 */

void testCombinations() {
    printVector(Solution().combine(4, 2));
}

void _combine_recursion(vector<vector<int>>& result, int n, int k, vector<int> group) {
    if (group.size() == k) {
        result.push_back(group);
        return;
    }
    int p = group.empty() ? 1 : group.back() + 1;
    while (p <= n) {
        // build group
        group.push_back(p++);
        // recurse
        _combine_recursion(result, n, k, group);
        // pop p revert to original group
        group.pop_back();
    }
}

vector<vector<int>> Solution::combine(int n, int k) {
    vector<vector<int>> result;
    _combine_recursion(result, n, k, {});
    return result;
}
