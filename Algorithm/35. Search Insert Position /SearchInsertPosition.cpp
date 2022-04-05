//
//  SearchInsertPosition.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SearchInsertPosition.hpp"

/**
 Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 
 You must write an algorithm with O(log n) runtime complexity.
 
 Input: nums = [1,3,5,6], target = 5
 Output: 2
 
 Input: nums = [1,3,5,6], target = 2
 Output: 1
 
 Input: nums = [1,3,5,6], target = 7
 Output: 4
 */

void testSearchInsertPosition() {
    vector<int> nums = {1,3,5,8};
    cout << Solution().searchInsert(nums, 9) << endl;
}

int Solution::searchInsert(vector<int> &nums, int target) {
    int left = 0, right = (int)nums.size() - 1;
    int i = -1;
    while (left <= right) {
        i = (left + right) / 2;
        if (nums[i] < target) {
            // turn right
            left = i + 1;
        } else if (nums[i] > target) {
            // turn left
            right = i - 1;
        } else {
            // find target
            return i;
        }
    }
    
    return left;
}
