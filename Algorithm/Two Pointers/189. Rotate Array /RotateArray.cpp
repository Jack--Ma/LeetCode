//
//  RotateArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/6.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RotateArray.hpp"

/**
 Given an array, rotate the array to the right by k steps, where k is non-negative.

 Input: nums = [1,2,3,4,5,6,7], k = 3
 Output: [5,6,7,1,2,3,4]
 Explanation:
 rotate 1 steps to the right: [7,1,2,3,4,5,6]
 rotate 2 steps to the right: [6,7,1,2,3,4,5]
 rotate 3 steps to the right: [5,6,7,1,2,3,4]
 
 Input: nums = [-1,-100,3,99], k = 2
 Output: [3,99,-1,-100]
 Explanation:
 rotate 1 steps to the right: [99,-1,-100,3]
 rotate 2 steps to the right: [3,99,-1,-100]
 */

void testRotateArray() {
    vector<int> nums = {1,2,3,4,5,6,7};
    Solution().rotateArray(nums, 7);
    printVector(nums);
}

void Solution::rotateArray(vector<int> &nums, int k) {
    const int size = (int)nums.size();
    k = k % size;
    
    vector<int> frontNums(nums.begin(), nums.begin()+(size - k));
    nums.erase(nums.begin(), nums.begin()+(size-k));
    nums.insert(nums.end(), frontNums.begin(), frontNums.end());
}
