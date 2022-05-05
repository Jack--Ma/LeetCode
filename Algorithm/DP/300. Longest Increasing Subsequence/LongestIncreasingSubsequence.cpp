//
//  LongestIncreasingSubsequence.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "LongestIncreasingSubsequence.hpp"

/**
 Given an integer array nums, return the length of the longest strictly increasing subsequence.
 
 A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
 
 Input: nums = [10,9,2,5,3,7,101,18]
 Output: 4
 Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
 
 Input: nums = [0,1,0,3,2,3]
 Output: 4
 */

void testLongestIncreasingSubsequence() {
    vector<int> nums = {0,1,0,3,2,3};
    cout << Solution().lengthOfLIS(nums) << endl;
}

// Solution by recursion
// Time complexity is O(2^n) Time Limit Exceeded
int _lengthOfLIS_recursion(vector<int> &nums, int i, int prev) {
    if (i >= nums.size()) {
        return 0;
    }
    int currentLength = _lengthOfLIS_recursion(nums, i+1, prev);
    int nextLength = 0;
    if (nums[i] > prev) {
        nextLength = 1 + _lengthOfLIS_recursion(nums, i+1, nums[i]);
    }
    return max(currentLength, nextLength);
}

// Solution by use DP
// Time complexity is O(n^2)
int _lengthOfLIS_DP(vector<int> &nums) {
    const int size = (int)nums.size();
    vector<vector<int>> DP(size, vector<int>(size, 1));
    vector<int> maxDP(size, 1);
    /**
     DP sketch, default value is 1
       j 0 1 0 3 2 3
     i
     0   1 2 1 2 2 2
     1     1 1 3 3 3
     0       1 2 2 2
     3         1 1 1
     2           1 4
     3             1
  maxDP  1 2 1 3 3 4
     DP[i][j] means sub nums' max LIS length which range is [i,j]
     DP[0][3] = max(max(DP[0~n][0])+1, max(DP[0~n][1])+1, max(DP[0~n][2])+1)
     DP[i][j] = max(max(DP[0~n][0])+1, ..., max(DP[0~n][j-1])+1)
     
     As maxDP, maxDP[i] mean the LIS length ending at index i. The formula is:
     maxDP[i] = max(maxDP[0]+1, maxDP[1]+1, ..., maxDP[i-1]+1)
     */
    int result = 1;
    for (int j = 1; j < size; j++) {
        for (int i = 0; i < j; i++) {
            int num_i = nums[i];
            int num_j = nums[j];
            if (num_j > num_i) {
                maxDP[j] = max(maxDP[j], maxDP[i]+1);
                result = max(result, maxDP[j]);
            }
        }
    }
    
    return result;
}

int Solution::lengthOfLIS(vector<int> &nums) {
    return _lengthOfLIS_DP(nums);
//    return _lengthOfLIS_recursion(nums, 0, INT_MIN);
}
