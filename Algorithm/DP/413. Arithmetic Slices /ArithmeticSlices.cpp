//
//  ArithmeticSlices.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ArithmeticSlices.hpp"

/**
 An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
 
 For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
 Given an integer array nums, return the number of arithmetic subarrays of nums.
 
 A subarray is a contiguous subsequence of the array.
 
 Input: nums = [1,2,3,4]
 Output: 3
 Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.
 
 Input: nums = [1]
 Output: 0
 */

void testArithmeticSlices() {
    vector<int> nums = {1,2,3,4,6,7,8};
    cout << Solution().numberOfArithmeticSlices(nums) << endl;
}

int Solution::numberOfArithmeticSlices(vector<int> &nums) {
    const int N = (int)nums.size();
    if (N <= 2) {
        return 0;
    }
    vector<vector<bool>> map(N, vector<bool>(N, false));
//    bool map[5001][5001] = {false};
    for (int i = 0; i < N-1; i++) {
        map[i][i+1] = true;
    }
    /**
     Use a DP map represents the subArray is arithmetic or not. The formula is:
     DP[j][i] = DP[j][i-1] && ((N[i]-N[i-1])==(N[i-1]-N[i-2]))
       i 1 2 3 4
     j
     1   0 1
     2     0 1
     3       0 1
     4         0
     */
    int result = 0;
    int lastDiff = nums[1]-nums[0];
    // i: from left to right
    for (int i = 2; i < N; i++) {
        int currDiff = nums[i] - nums[i-1];
        // j: from top to bottom
        for (int j = 0; j < i-1; j++) {
            // current sub array range is [j, i]
            if (map[j][i-1] && currDiff == lastDiff) {
                map[j][i] = true;
                result++;
            }
        }
        lastDiff = currDiff;
    }
    
    return result;
}
