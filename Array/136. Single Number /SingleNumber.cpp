//
//  SingleNumber.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SingleNumber.hpp"

/**
 Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
 
 Input: nums = [2,2,1]
 Output: 1
 
 Input: nums = [4,1,2,1,2]
 Output: 4
 */

static inline int _singleNumber_bitwise(vector<int> &nums) {
    // use bitwise XOR operation
    // 4=0b100, 1=0b001, 2=0b010
    // 0^n=n, 4^1^2^1^2=4
    int result = 0;
    for (int num : nums) {
        result ^= num;
    }
    return result;
}

static inline int _singleNumber_sort(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i+=2) {
        // every nums[i] should be equal to nums[i-1]
        if ((i+1 < nums.size()) && (nums[i] != nums[i+1])) {
            return nums[i];
        }
    }
    return nums[nums.size()-1];
}

static inline int _singleNumber_map(vector<int> &nums) {
    unordered_map<int, int> numMap;
    for (int num : nums) {
        numMap[num]++;
    }
    for (auto numPair : numMap) {
        if (numPair.second == 1) {
            return numPair.first;
        }
    }
    
    return 0;
}

int Solution::singleNumber(vector<int> &nums) {
    return _singleNumber_bitwise(nums);
}

void testSingleNumber() {
    vector<int> nums = {4,1,2,1,2};
    cout << Solution().singleNumber(nums) << endl;
}
