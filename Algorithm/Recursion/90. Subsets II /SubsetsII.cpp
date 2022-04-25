//
//  SubsetsII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SubsetsII.hpp"

/**
 Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
 
 The solution set must not contain duplicate subsets. Return the solution in any order.
 
 Input: nums = [1,2,2]
 Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
 */

void testSubsetsII() {
    vector<int> nums = {1,2,2};
    printVector(Solution().subsetsWithDup(nums));
}

void Solution::_subsetsWithDup(int index, vector<int> subNums) {
    subNums.push_back(nums[index]);
    result.push_back(subNums);
    if (index == nums.size() - 1) {
        return;
    }
    int last = -100;
    for (int i = index + 1; i < nums.size(); i++) {
        // jump the repeated num
        if (nums[i] != last) {
            _subsetsWithDup(i, subNums);
            last = nums[i];
        }
    }
}

vector<vector<int>> Solution::subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    this->nums = nums;
    
    int last = -100;
    for (int i = 0; i < nums.size(); i++) {
        // jump the repeated num
        if (nums[i] != last) {
            _subsetsWithDup(i, {});
            last = nums[i];
        }
    }
    result.push_back({});
    return result;
}
