//
//  BinarySearch.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BinarySearch.hpp"

/**
 Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
 
 Input: nums = [-1,0,3,5,9,12], target = 9
 Output: 4
 Explanation: 9 exists in nums and its index is 4
 
 Input: nums = [-1,0,3,5,9,12], target = 2
 Output: -1
 Explanation: 2 does not exist in nums so return -1
 */

void testBinarySearch() {
    vector<int> nums = {-1,0,3,5,9,12};
    cout << Solution().binarySearch(nums, -6) << endl;
}

int Solution::binarySearch(vector<int> &nums, int target) {
    const int size = (int)nums.size();
    
    int left = 0, right = size - 1;
    int i = (left + right) / 2;
    
    while (left <= right) {
        if (nums[i] < target) {
            // turn right
            left = i + 1;
        } else if (nums[i] > target) {
            // turn left
            right = i - 1;
        } else {
            return i;
        }
        i = (left + right) / 2;
    }
    return -1;
}
