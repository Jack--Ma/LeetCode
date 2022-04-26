//
//  CombinationSum.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "CombinationSum.hpp"

/**
 Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

 The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

 It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
 
 Input: candidates = [2,3,6,7], target = 7
 Output: [[2,2,3],[7]]
 Explanation:
 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
 7 is a candidate, and 7 = 7.
 These are the only two combinations.
 
 Input: candidates = [2,3,5], target = 8
 Output: [[2,2,2,2],[2,3,3],[3,5]]
 */

void testCombinationSum() {
    vector<int> nums = {2,7,6,3,5,1};
    printVector(CombinationSumSolution().combinationSum(nums, 9));
}

void CombinationSumSolution::_combinationSum(vector<int> subNums, int index, int leftTarget) {
    // traverse every number from input index
    // so every index traverse range is [index, size-1]
    // such as: [0,3] [1,3] [2,3] [3,3]
    for (int i = index; i < candidates.size(); i++) {
        int num = candidates[i];
        if (num > leftTarget) {
            // left nums are bigger
            return;
        } else if (num == leftTarget) {
            // correct num
            subNums.push_back(num);
            result.push_back(subNums);
        } else {
            // push smaller num, then recurse next level
            subNums.push_back(num);
            _combinationSum(subNums, i, leftTarget-num);
            // pop num revert original scene
            subNums.pop_back();
        }
    }
}

vector<vector<int>> CombinationSumSolution::combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    this->target = target;
    
    _combinationSum({}, 0, target);

    return result;
}
