//
//  HouseRobber.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/15.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "HouseRobber.hpp"

/**
 You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 
 Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 
 Input: nums = [1,2,3,1]
 Output: 4
 Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 Total amount you can rob = 1 + 3 = 4.
 
 Input: nums = [2,7,9,3,1]
 Output: 12
 Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
 Total amount you can rob = 2 + 9 + 1 = 12.
 */

void testHouseRobber() {
    vector<int> nums = {2,9,8};
    cout << Solution().rob(nums) << endl;
}

int Solution::rob(vector<int> &nums) {
    if (nums.size() == 1) {
        return nums[0];
    }
    const int size = (int)nums.size();
    const int MAX_SIZE = 100;
    int cache[MAX_SIZE+1];
    /**
     f(0) = nums[0] + max(f(2), f(3))
     f(1) = nums[i] + max(f(3), f(4))
     ...
     f(i) = nums[i] + max(f(i+2), f(i+3))

     we need to traverse nums from end to begin
     */
    for (int i = size - 1; i >= 0; i--) {
        int num = nums[i];
        int next1 = i+2;
        int next2 = i+3;
        if (next2 < size) {
            cache[i] = num + max(cache[next1], cache[next2]);
        } else if (next1 < size) {
            cache[i] = num + cache[next1];
        } else {
            cache[i] = num;
        }
    }
    
    return max(cache[0], cache[1]);
}
