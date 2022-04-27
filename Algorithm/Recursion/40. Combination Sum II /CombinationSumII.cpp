//
//  CombinationSumII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "CombinationSumII.hpp"

/**
 Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
 Each number in candidates may only be used once in the combination.
 Note: The solution set must not contain duplicate combinations.
 
 Input: candidates = [10,1,2,7,6,1,5], target = 8
 Output: [[1,1,6],[1,2,5],[1,7],[2,6]]
 
 Input: candidates = [2,5,2,1,2], target = 5
 Output: [[1,2,2],[5]]
 */

void testCombinationSumII() {
    vector<int> nums = {2,5,2,1,2};
    printVector(Solution().combinationSum2(nums, 5));
}

void Solution::_combinationSum2(vector<int> subNums, int index, int leftTarget) {
    int lastNum = -100;
    for (int i = index; i < candidates.size(); i++) {
        int num = candidates[i];
        // jump the number had been used
        if (num == -100) {
            continue;
        }
        // jump the duplicated number
        if (num == lastNum) {
            continue;
        }
        if (num > leftTarget) {
            // left nums are bigger than leftTarget
            break;
        } else if (num == leftTarget) {
            // find the correct num
            subNums.push_back(num);
            result.push_back(subNums);
            break;
        } else {
            // num is smaller than leftTarget
            // build sunNums and jump next loop
            subNums.push_back(num);
            candidates[i] = -100;
            _combinationSum2(subNums, i+1, leftTarget-num);
            // revert original scene
            candidates[i] = num;
            subNums.pop_back();
            // build last number
            lastNum = num;
        }
    }
}

vector<vector<int>> Solution::combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    this->target = target;
    _combinationSum2({}, 0, target);
    
    return result;
}
