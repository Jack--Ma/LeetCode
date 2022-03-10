//
//  IncreasingTripletSubsequence.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/10.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "IncreasingTripletSubsequence.hpp"

/**
 Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.

 Input: nums = [1,2,3,4,5]
 Output: true
 Explanation: Any triplet where i < j < k is valid.
 */

bool Solution::increasingTriplet(vector<int> &nums) {
    // save the minimum and middle numer
    pair<int, int> duple = {INT_MAX, INT_MAX};
    
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        if (num <= duple.first) {
            duple.first = num;
        } else {
            if (num <= duple.second) {
                duple.second = num;
            } else {
                // num is bigger than duple
                return true;
            }
        }
    }
    
    return false;
}

void testIncreasingTriplet() {
    vector<int> nums = {1,2,3,4,5};
    cout << Solution().increasingTriplet(nums) << endl;
}
