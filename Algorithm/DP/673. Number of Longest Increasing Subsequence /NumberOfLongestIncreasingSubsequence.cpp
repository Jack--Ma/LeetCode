//
//  NumberOfLongestIncreasingSubsequence.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "NumberOfLongestIncreasingSubsequence.hpp"

/**
 Given an integer array nums, return the number of longest increasing subsequences.
 Notice that the sequence has to be strictly increasing.
 
 Input: nums = [1,3,5,4,7]
 Output: 2
 Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
 
 Input: nums = [2,2,2,2,2]
 Output: 5
 Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
 */

void testNumberOfLongestIncreasingSubsequence() {
    vector<int> nums = {1,3,5,4};
    cout << Solution().findNumberOfLIS(nums) << endl;
}

int _findNumberOfLIS_DP(vector<int> &nums) {
    const int size = (int)nums.size();
    
    int maxLength = 1;
//    vector<vector<int>> DP(size, vector<int>(size, 1));
    // stores max LIS length of nums
    vector<int> maxDP(size, 1);
    // stores count of longest sequence of length lis[i]
    vector<int> countDP(size,1);
    /**
     DP represents the LIS length in range [0,j]+[i,i]
      i 1 3 5 4 7
     j
     1  1 2 2 2 2
     3    1 3 3 3
     5      1 1 4
     4        1 4
     7          1
  maxDP 1 2 3 3 4
     */
    
    for (int i = 1; i < size; i++) {
        for (int j = 0; j < i; j++) {
            // range is [j,i]
            int num_j = nums[j], num_i = nums[i];
            if (num_i > num_j) {
                if (maxDP[j]+1 > maxDP[i]) {
                    // exist number which smaller than nums[i]
                    maxDP[i] = maxDP[j]+1;
                    // There is a LIS ending at length maxDP[j], and count is countDP[j]
                    countDP[i] = countDP[j];
                } else if (maxDP[j]+1 == maxDP[i]) {
                    // before i, the range [0,j] is LIS. And there are more subsequences of same length ending at length maxDP[i]
                    countDP[i] += countDP[j];
                }
//                DP[j][i] = maxDP[i];
            }
        }
        maxLength = max(maxLength, maxDP[i]);
    }
//    printVector(DP);
//    printVector(countDP);

    int result = 0;
    for (int i = 0; i < maxDP.size(); i++) {
        if (maxDP[i] == maxLength) {
            result += countDP[i];
        }
    }
    
    return result;
}

int Solution::findNumberOfLIS(vector<int> &nums) {
    return _findNumberOfLIS_DP(nums);
}
