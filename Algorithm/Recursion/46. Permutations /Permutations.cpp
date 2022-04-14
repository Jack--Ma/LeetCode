//
//  Permutations.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/14.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Permutations.hpp"

/**
 Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
 
 Input: nums = [1,2,3]
 Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 
 Input: nums = [0,1]
 Output: [[0,1],[1,0]]
 */

void testPermutations() {
    vector<int> nums = {1,2,3,4};
    printVector(Solution().permute(nums));
}

void _permute_recursion(vector<vector<int>>& result, vector<int>& nums, vector<int> group) {
    if (nums.size() == group.size()) {
        result.push_back(group);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        // set 100 in order to mark this number has already been used
        // in next recursion could jump mark=100 number
        if (num == 100) {
            continue;
        }
        group.push_back(num);
        nums[i] = 100;
        _permute_recursion(result, nums, group);
        // must recover original scene
        nums[i] = num;
        group.pop_back();
    }
}

vector<vector<int>> Solution::permute(vector<int> &nums) {
    vector<vector<int>> result;
    _permute_recursion(result, nums, {});
    return result;
}
