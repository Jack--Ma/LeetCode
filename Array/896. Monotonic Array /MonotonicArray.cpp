//
//  MonotonicArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MonotonicArray.hpp"

/**
 An array is monotonic if it is either monotone increasing or monotone decreasing.
 
 An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].
 
 Given an integer array nums, return true if the given array is monotonic, or false otherwise.
 
 Input: nums = [1,2,2,3]
 Output: true
 
 Input: nums = [6,5,4,4]
 Output: true
 
 Input: nums = [1,3,2]
 Output: false
 */

void testMonotonicArray() {
    vector<int> nums = {11,11,9,4,3,3,3,1,-1,-1,3,3,3,5,5,5};
    cout << Solution().isMonotonic(nums) << endl;
}

bool Solution::isMonotonic(vector<int> &nums) {
    if (nums.size() <= 2) {
        return true;
    }
    // -1 mean decrease; 1 mean increase
    int lastTrend = 0;
    for (int i = 1; i < nums.size()-1; i++) {
        int num_a = nums[i-1];
        int num = nums[i];
        int num_b = nums[i+1];
        if (num_a == num && num == num_b) {
            // same
            continue;
        } else if ((num_a <= num && num <= num_b)) {
            // increase
            if (lastTrend == 0) {
                lastTrend = 1;
            } else if (lastTrend != 1) {
                return false;
            }
        } else if ((num_a >= num && num >= num_b)) {
            // decrease
            if (lastTrend == 0) {
                lastTrend = -1;
            } else if (lastTrend != -1) {
                return false;
            }
        } else {
            return false;
        }
    }
    
    return true;
}
