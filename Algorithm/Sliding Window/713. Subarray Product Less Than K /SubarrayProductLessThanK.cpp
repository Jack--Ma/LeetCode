//
//  SubarrayProductLessThanK.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/20.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SubarrayProductLessThanK.hpp"

/**
 Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
 
 Input: nums = [10,5,2,6], k = 100
 Output: 8
 Explanation: The 8 subarrays that have product less than 100 are:
 [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
 Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
 */

void testSubarrayProductLessThanK() {
    vector<int> nums = {10,5,2,6};
    cout << Solution().numSubarrayProductLessThanK(nums, 100) << endl;
}

// solution by use sliding window
int _numSubarrayProductLessThanK_better(vector<int> &nums, int k) {
    int result = 0;
    const int size = (int)nums.size();
    
    // window range is [p1, p2],
    int p1 = 0, p2 = p1, mult = 1;
    while (p1 < size && p2 < size) {
        int num_p2 = nums[p2];
        mult *= num_p2;
        if (mult < k) {
            // in the range subArray count is p2-p1+1
            result += (p2-p1+1);
            p2++;
        } else {
            // recalculate mult and move window forward
            mult /= (nums[p1]*num_p2);
            mult = max(1, mult);
            p1++;
            p2 = max(p1, p2);
        }
    }
    
    return result;
}

// solution but Time Limit Exceeded
int Solution::numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int result = 0;
    const int size = (int)nums.size();
    
    int p1 = 0, p2 = p1, mult = 1;
    while (p1 < size) {
        int num_p2 = nums[p2];
        mult *= num_p2;
        if (mult >= k) {
            p1++;
            p2 = p1;
            mult = 1;
        } else {
            result++;
            p2++;
            if (p2 >= size) {
                p1++;
                p2 = p1;
                mult = 1;
            }
        }
    }
    
    return (int)result;
}

