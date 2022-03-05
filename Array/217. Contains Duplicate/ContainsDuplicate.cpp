//
//  ContainsDuplicate.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/16.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_set>

#include "ContainsDuplicate.hpp"

// my solution
bool Solution::containsDuplicate(vector<int> &nums) {
    unordered_set<int> set = unordered_set<int>();
    bool result = false;
    
    for (int num : nums) {
        // can't find num
        if (set.find(num) == set.end()) {
            set.insert(num);
        } else {
            result = true;
            break;
        }
        
    }
    return result;
}

// other solution
bool otherContainsDuplicate(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    // Searches the range [first, last) for two consecutive equal elements.
    return std::adjacent_find(nums.begin(), nums.end()) != nums.end();
}

void testContainsDuplicate(void) {
    Solution solution = Solution();
    vector<int> nums = {1,2,3,4};
    cout << solution.containsDuplicate(nums) << endl;
}
