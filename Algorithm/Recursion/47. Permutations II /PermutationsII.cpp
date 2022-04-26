//
//  PermutationsII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PermutationsII.hpp"

/**
 Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
 
 Input: nums = [1,1,2]
 Output: [[1,1,2],[1,2,1],[2,1,1]]
 
 Input: nums = [1,2,3]
 Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 */

void testPermutationsII() {
    vector<int> nums = {1,2};
    printVector(Solution().permuteUnique(nums));
}

void Solution::_permuteUnique(vector<int> subNums) {
    if (subNums.size() == nums.size()) {
        result.push_back(subNums);
        return;
    }
    
    int last = -100;
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        // jump the duplicated num
        if (num == last) {
            continue;
        }
        // mark the num has been used
        if (num == -100) {
            continue;
        }
        nums[i] = -100;
        subNums.push_back(num);
        _permuteUnique(subNums);
        // revert the situation
        subNums.pop_back();
        nums[i] = num;
        last = num;
    }
}

vector<vector<int>> Solution::permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    this->nums = nums;
    _permuteUnique({});
    return result;
}
