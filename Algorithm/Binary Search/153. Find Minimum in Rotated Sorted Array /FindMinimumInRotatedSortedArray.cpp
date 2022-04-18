//
//  FindMinimumInRotatedSortedArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "FindMinimumInRotatedSortedArray.hpp"

/**
 Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
 [4,5,6,7,0,1,2] if it was rotated 4 times.
 [0,1,2,4,5,6,7] if it was rotated 7 times.
 Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 
 Input: nums = [3,4,5,1,2]
 Output: 1
 Explanation: The original array was [1,2,3,4,5] rotated 3 times.
 
 Input: nums = [4,5,6,7,0,1,2]
 Output: 0
 Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
 */

void testFindMinimumInRotatedSortedArray() {
    vector<int> nums = {3,4,5,1,2};
    cout << Solution().findMin(nums) << endl;
}

int Solution::findMin(vector<int> &nums) {
    int result = INT_MAX;
    const int size = (int)nums.size();
    int left = 0, right = size - 1;
    int mid = (left + right) / 2;
    
    while (left <= right) {
        // nums range [left, mid] is monotone increase
        if (nums[left] <= nums[mid]) {
            result = min(result, nums[left]);
            // next traverse range: [mid+1, right]
            left = mid + 1;
        }
        // nums range [mid, right] is monotone increase
        if (nums[mid] <= nums[right]) {
            result = min(result, nums[mid]);
            // next traverse range: [left, mid-1]
            right = mid - 1;
        }
        mid = (left + right) / 2;
    }
    
    return result;
}
