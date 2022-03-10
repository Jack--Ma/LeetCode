//
//  ProductOfArrayExceptSelf.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/10.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ProductOfArrayExceptSelf.hpp"

/**
 Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 
 The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 You must write an algorithm that runs in O(n) time and without using the division operation.
 
 Input: nums = [1,2,3,4]
 Output: [24,12,8,6]
 */

// my solution
vector<int> Solution::productExceptSelf(vector<int> &nums) {
    int multiplyResult = 1, zeroCount = 0;
    for (int num : nums) {
        if (num == 0) {
            zeroCount++;
        } else {
            multiplyResult *= num;
        }
    }
    
    if (zeroCount >= 2) {
        return vector<int>(nums.size(), 0);
    }
    vector<int> result;
    for (int num : nums) {
        if (zeroCount == 1) {
            result.push_back(num == 0 ? multiplyResult : 0);
        } else {
            result.push_back(multiplyResult / num);
        }
    }
    return result;
}

// other better solution
vector<int> _productExceptSelf_better(vector<int> &nums) {
    int temp = 1;
    vector<int> res(nums.size());
    
    for (int i = 0; i < nums.size(); i++) {
        res[i] = temp;
        temp = temp * nums[i];
    }
    // now temp is nums every num multiply
    // now res list num[n] = !num[n-1]
    
    temp = 1;
    for (int i = (int)nums.size()-1; i >= 0; i--) {
        // in each loop, temp is equal to nums'multiple behind nums[i]
        // such as: i=4, temp 1; i=3, temp=5
        res[i] = res[i] * temp;
        temp = temp * nums[i];
    }
    
    return res;
}

void testProductExceptSelf() {
    vector<int> nums = {1,2,3,4,5};
    printVector(_productExceptSelf_better(nums));
}
