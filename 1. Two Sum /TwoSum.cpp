//
//  TwoSum.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/16.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_map>
#include "TwoSum.hpp"

/*
 Input: nums = [2,7,11,15], target = 9
 Output: [0,1]
 Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 */
vector<int> Solution::twoSum(vector<int> &nums, int target) {
    vector<int> result;
    unordered_map<int, int> map;
    
    for (int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int reduceNum = target - num;
        if (map.find(reduceNum) == map.end()) {
            // insert map when not find
            map[num] = i;
        } else {
            result.push_back(map[reduceNum]);
            result.insert(result.end(), i);
            break;
        }
    }
    return result;
}


void testTwoSum() {
    vector<int> nums = {3,2,4};
    for (auto i : Solution().twoSum(nums, 6)) {
        cout << i << endl;
    }
}
