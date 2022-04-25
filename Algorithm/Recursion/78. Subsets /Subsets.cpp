//
//  Subsets.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Subsets.hpp"

/**
 Given an integer array nums of unique elements, return all possible subsets (the power set).
 The solution set must not contain duplicate subsets. Return the solution in any order.
 
 Input: nums = [1,2,3]
 Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
 */

void testSubsets() {
    vector<int> nums = {1,2,3};
    printVector(Solution().subsets(nums));
}

void Solution::_subsets_dfs(vector<int>& nums, int index, vector<int> subNums) {
    subNums.push_back(nums[index]);
    result.push_back(subNums);
    if (index == nums.size() - 1) {
        // recurse to last num
        return;
    }
    // recurse next index continue with subNums
    for (int i = index + 1; i < nums.size(); i++) {
        _subsets_dfs(nums, i, subNums);
    }
}

vector<vector<int>> Solution::subsets(vector<int> &nums) {
    result.push_back({});
    for (int i = 0; i < nums.size(); i++) {
        _subsets_dfs(nums, i, {});
    }
    return result;
}
