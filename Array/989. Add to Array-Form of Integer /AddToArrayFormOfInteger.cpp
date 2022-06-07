//
//  AddToArrayFormOfInteger.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/6.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "AddToArrayFormOfInteger.hpp"

/**
 The array-form of an integer num is an array representing its digits in left to right order.
    * For example, for num = 1321, the array form is [1,3,2,1].
 Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.
 
 Input: num = [1,2,0,0], k = 34
 Output: [1,2,3,4]
 Explanation: 1200 + 34 = 1234
 
 Input: num = [2,1,5], k = 806
 Output: [1,0,2,1]
 Explanation: 215 + 806 = 1021
 */

void testAddToArrayFormOfInteger() {
    /**
     [0]
     10000
     */
    vector<int> nums = {0};
    printVector(Solution().addToArrayForm(nums, 10000));
}

vector<int> Solution::addToArrayForm(vector<int> &nums, int k) {
    const int size = (int)nums.size();
    
    vector<int> result;
    int carryNum = 0;
    for (int i = size-1; i >= 0; i--) {
        int num = nums[i];
        int num_k = k % 10;
        k = k / 10;
        result.insert(result.begin(), (carryNum + num + num_k) % 10);
        carryNum = (carryNum + num + num_k) / 10;
    }
    while (k > 0) {
        int num_k = k % 10;
        k = k / 10;
        result.insert(result.begin(), (carryNum + num_k) % 10);
        carryNum = (carryNum + num_k) / 10;
    }
    if (carryNum > 0) {
        result.insert(result.begin(), carryNum);
    }
    return result;
}
