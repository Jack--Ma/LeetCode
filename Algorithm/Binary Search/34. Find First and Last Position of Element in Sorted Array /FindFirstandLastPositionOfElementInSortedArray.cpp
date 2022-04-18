//
//  FindFirstandLastPositionOfElementInSortedArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FindFirstandLastPositionOfElementInSortedArray.hpp"

/**
 Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
 If target is not found in the array, return [-1, -1].
 You must write an algorithm with O(log n) runtime complexity.
 
 Input: nums = [5,7,7,8,8,10], target = 8
 Output: [3,4]
 
 Input: nums = [5,7,7,8,8,10], target = 6
 Output: [-1,-1]
 
 Input: nums = [], target = 0
 Output: [-1,-1]
 */

void testFindFirstandLastPositionOfElementInSortedArray() {
    vector<int> nums = {5,7,7,8,8,10};
    printVector(Solution().searchRange(nums, 10));
}

vector<int> Solution::searchRange(vector<int> &nums, int target) {
    vector<int> result(2, -1);
    // use binary search
    const int size = (int)nums.size();
    int left = 0, right = size - 1;
    int i = (left + right) / 2;
    
    while (left <= right) {
        int num = nums[i];
        if (target < num) {
            right = i - 1;
        } else if (target > num) {
            left = i + 1;
        } else {
            // find range from i index
            int start = i, end = i;
            while (start >= 0) {
                if (nums[start] == num) {
                    result[0] = start;
                } else {
                    break;
                }
                start--;
            }
            while (end < size) {
                if (nums[end] == num) {
                    result[1] = end;
                } else {
                    break;
                }
                end++;
            }
            break;
        }
        i = (left + right) / 2;
    }
    
    return result;
}
