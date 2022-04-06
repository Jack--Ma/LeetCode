//
//  MoveZeroes.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/6.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MoveZeroes.hpp"

/**
 Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 Note that you must do this in-place without making a copy of the array.
 
 Input: nums = [0,1,0,3,12]
 Output: [1,3,12,0,0]
 */

void testMoveZeroes() {
    vector<int> nums = {1,0};
    Solution().moveZeroes(nums);
    printVector(nums);
}

void Solution::moveZeroes(vector<int> &nums) {
    int numIndex = 0, zeroIndex = 0;
    while (numIndex < nums.size() && zeroIndex < nums.size()) {
        // numIndex must point to number
        if (nums[numIndex] == 0) {
            numIndex++;
            continue;
        }
        // zeroIndex must point to zero
        if (nums[zeroIndex] != 0) {
            zeroIndex++;
            continue;
        }
        // exchange zero and number when numIndex behind zeroIndex
        if (zeroIndex > numIndex) {
            numIndex++;
            continue;
        }
        swap(nums[zeroIndex], nums[numIndex]);
        zeroIndex++;
        numIndex++;
    }
}
