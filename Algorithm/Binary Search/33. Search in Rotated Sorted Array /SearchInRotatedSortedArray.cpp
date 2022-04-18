//
//  SearchInRotatedSortedArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SearchInRotatedSortedArray.hpp"

/**
 There is an integer array nums sorted in ascending order (with distinct values).
 Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 
 Input: nums = [4,5,6,7,0,1,2], target = 0
 Output: 4
 
 Input: nums = [4,5,6,7,0,1,2], target = 3
 Output: -1
 
 Input: nums = [1], target = 0
 Output: -1
 */

void testSearchInRotatedSortedArray() {
    vector<int> nums = {4,5,6,7,0,1,2};
    cout << Solution().search(nums, 8) << endl;
}

int Solution::search(vector<int> &nums, int target) {
    int result = -1;
    const int size = (int)nums.size();
    int left = 0, right = size - 1;
    int i = (left + right) / 2;
    while (left <= right) {
        int num = nums[i];
        if (num == target) {
            result = i;
            break;
        }
        if (nums[left] <= num) {
            // nums range [left, i] is monotone increase
            if (nums[left] <= target && target < num) {
                right = i;
            } else {
                left = i + 1;
            }
        } else {
            // nums range [left, i] is not monotone increase
            // but range [i, right] is monotone increase
            if (num < target && target <= nums[right]) {
                left = i + 1;
            } else {
                right = i;
            }
        }
        i = (left + right) / 2;
    }
    
    return result;
}
