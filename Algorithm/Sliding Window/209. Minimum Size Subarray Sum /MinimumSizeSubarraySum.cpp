//
//  MinimumSizeSubarraySum.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/21.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MinimumSizeSubarraySum.hpp"

/**
 Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.
 
 Input: target = 7, nums = [2,3,1,2,4,3]
 Output: 2
 Explanation: The subarray [4,3] has the minimal length under the problem constraint.
 
 Input: target = 4, nums = [1,4,4]
 Output: 1
 
 Input: target = 11, nums = [1,1,1,1,1,1,1,1]
 Output: 0
 */

void testMinimumSizeSubarraySum() {
    vector<int> nums = {1,1,1,1,1,1,1,1};
    cout << Solution().minSubArrayLen(11, nums) << endl;
}

/// solution by use sliding window
int Solution::minSubArrayLen(int target, vector<int> &nums) {
    const int size = (int)nums.size();
    int result = size;
    // sliding window rang is [left,right]
    int left = 0, right = 0;
    int sum = 0;
    while (left < size && right < size) {
        int num_l = nums[left];
        int num_r = nums[right];
        sum += num_r;
        // sum is bigger, calculate subArray length
        if (sum >= target) {
            result = min(result, right-left+1);
            // for next loop, left++
            sum -= (num_l+num_r);
            left++;
        } else {
            right++;
        }
    }
    // no subArray that sum bigger than target
    if (left == 0) {
        return 0;
    }
    return result;
}
