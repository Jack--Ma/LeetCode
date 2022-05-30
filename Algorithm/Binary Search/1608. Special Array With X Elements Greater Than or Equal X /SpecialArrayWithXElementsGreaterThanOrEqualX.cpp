//
//  SpecialArrayWithXElementsGreaterThanOrEqualX.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/29.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SpecialArrayWithXElementsGreaterThanOrEqualX.hpp"

/**
 You are given an array nums of non-negative integers. nums is considered special if there exists a number x such that there are exactly x numbers in nums that are greater than or equal to x.
 
 Notice that x does not have to be an element in nums.
 
 Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.
 
 Input: nums = [3,5]
 Output: 2
 Explanation: There are 2 values (3 and 5) that are greater than or equal to 2.
 
 Input: nums = [0,4,3,0,4]
 Output: 3
 Explanation: There are 3 values that are greater than or equal to 3.
 */

void testSpecialArrayWithXElementsGreaterThanOrEqualX() {
    vector<int> nums = {3,6};
    cout << Solution().specialArray(nums) << endl;
}

int _specialArray_BS(vector<int> &nums) {
    int size = (int)nums.size();
    int left = 1, right = size;
    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        // find the count of numbers beyond mid
        for (int i = 0; i < size; i++) {
            if (nums[i] >= mid) {
                count++;
            }
        }
        if (count == mid) {
            // match condition
            return mid;
        } else if (count < mid) {
            // there are more numbers smaller than mid
            right = mid-1;
        } else {
            // there are more numbers bigger than mid
            left = mid+1;
        }
    }
    
    return -1;
}

int Solution::specialArray(vector<int> &nums) {
    int size = (int)nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 1; i <= size; i++) {
        // find the first index which number beyond i
        long index = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
        // there are [count] numbers bigger than i
        long count = size - index;
        // match condition
        if (count == i) {
            return i;
        }
    }
    
    return -1;
}
