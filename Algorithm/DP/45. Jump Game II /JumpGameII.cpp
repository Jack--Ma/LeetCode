//
//  JumpGameII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/29.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "JumpGameII.hpp"

/**
 Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.
 You can assume that you can always reach the last index.
 
 Input: nums = [2,3,1,1,4]
 Output: 2
 Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
 
 Input: nums = [2,3,0,1,4]
 Output: 2
 */

void testJumpGameII() {
    vector<int> nums = {4,1,1,3,1,1,1};
    cout << Solution().jump(nums) << endl;
}

int Solution::jump(vector<int> &nums) {
    const int size = (int)nums.size();
    int result = 0;
    // the fast index always point to the farthest target
    int fastIndex = 0;
    int lastIndex = 0;
    
    for (int i = 0; i < size; i++) {
        int num = nums[i];
        int maxJumpIndex = i+num;
        // have jumped all numbers before last
        if (i > lastIndex) {
            lastIndex = fastIndex;
            // jump to the fastIndex
            result++;
        }
        fastIndex = max(fastIndex, maxJumpIndex);
    }
    
    return result;
}
