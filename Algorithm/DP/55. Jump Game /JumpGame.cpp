//
//  JumpGame.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/29.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "JumpGame.hpp"

/**
 You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

 Return true if you can reach the last index, or false otherwise.
 
 Input: nums = [2,3,1,1,4]
 Output: true
 Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 
 Input: nums = [3,2,1,0,4]
 Output: false
 Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 */

void testJumpGame() {
    vector<int> nums = {3,4};
    cout << Solution().canJump(nums) << endl;
}

bool Solution::canJump(vector<int> &nums) {
    const int size = (int)nums.size();
    // represent the number index which can access to target
    int targetIndex = size-1;
    for (int i = size-2; i >= 0; i--) {
        int num = nums[i];
        // can jump into target index
        if (i + num >= targetIndex) {
            targetIndex = i;
        }
    }
    
    return targetIndex == 0;
}
