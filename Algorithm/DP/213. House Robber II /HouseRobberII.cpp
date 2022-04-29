//
//  HouseRobberII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "HouseRobberII.hpp"

/**
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

 Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 
 Input: nums = [2,3,2]
 Output: 3
 Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
 
 Input: nums = [1,2,3,1]
 Output: 4
 Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 Total amount you can rob = 1 + 3 = 4.
 */

void testHouseRobberII() {
    vector<int> nums = {2,3};
    cout << Solution().robII(nums) << endl;
}

int _houseRobber(vector<int>& nums) {
    int result = 0;
    const int size = (int)nums.size();
    /**
     Make sure the DP function
     f(0) = num_0 + max(f(2), f(3))
     ...
     f(n) = num_n + max(f(n+2), f(n+3)) (n+3 < size)
     */
    vector<int> DP(size, 0);
    for (int i = size - 1; i >= 0; i--) {
        int num = nums[i];
        if (i+3 < size) {
            DP[i] = num + max(DP[i+2], DP[i+3]);
        } else if (i+2 < size) {
            DP[i] = num + DP[i+2];
        } else {
            DP[i] = num;
        }
        result = max(result, DP[i]);
    }
    return result;
}

int Solution::robII(vector<int> &nums) {
    const int size = (int)nums.size();
    if (size == 1) {
        return nums[0];
    }
    
    // divide nums into two subNums to prevent robbing head+tail
    vector<int> subNums1 = vector<int>(nums.begin()+1, nums.end());
    vector<int> subNums2 = vector<int>(nums.begin(), nums.end()-1);
    return max(_houseRobber(subNums1), _houseRobber(subNums2));
}
