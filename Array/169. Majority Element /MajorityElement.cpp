//
//  MajorityElement.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/6.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MajorityElement.hpp"

/**
 Given an array nums of size n, return the majority element.

 Input: nums = [3,2,3]
 Output: 3
 
 Input: nums = [2,2,1,1,1,2,2]
 Output: 2
 */

// other better solution
int _majorityElement(vector<int> &nums) {
    int cnt = 0, res = 0;
    for (int i : nums) {
        if (cnt == 0) {
            res = i;
            cnt = 1;
        } else {
            // cnt save the number res appear times
            cnt += (i == res) ? 1 : -1;
        }
    }
    return res;
}

// my solution
int Solution::majorityElement(vector<int> &nums) {
    unordered_map<int, int> numMap;
    for (int num : nums) {
        numMap[num]++;
    }
    
    for (auto pair : numMap) {
        if (pair.second > (nums.size() / 2)) {
            return pair.first;
        }
    }
    
    return 0;
}

void testMajorityElement() {
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << _majorityElement(nums) << endl;
}
