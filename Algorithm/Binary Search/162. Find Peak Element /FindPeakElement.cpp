//
//  FindPeakElement.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FindPeakElement.hpp"

/**
 A peak element is an element that is strictly greater than its neighbors.
 Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
 You may imagine that nums[-1] = nums[n] = -∞.
 
 Input: nums = [1,2,3,1]
 Output: 2
 Explanation: 3 is a peak element and your function should return the index number 2.
 \
 Input: nums = [1,2,1,3,5,6,4]
 Output: 5
 Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
 */

void testFindPeakElement() {
    vector<int> nums = {1,2,1,3,5,6,4};
    cout << Solution().findPeakElement(nums) << endl;
}

int Solution::findPeakElement(vector<int> &nums) {
    const int size = (int)nums.size();
    int left = 0, right = size - 1;
    int i = (left + right) / 2;
    while (left < right) {
        // we just need find one of peaks
        if (nums[i] < nums[i+1]) {
            // so if i+1 bigger than i, that mean exist a peak after i
            left = i + 1;
        } else {
            // otherwise, mean exist a peal before i
            right = i;
        }
        i = (left + right) / 2;
    }
    
    return i;
}
