//
//  3Sum.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/6.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "3Sum.hpp"

/**
 Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 
 Input: nums = [-1,0,1,2,-1,-4]
 Output: [[-1,-1,2],[-1,0,1]]
 */

// my solution time out
vector<vector<int>> _threeSum_timeout(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size()-2; i++) {
        // nums[i] must below with zero
        if (nums[i] > 0) {
            continue;
        }
        // nums i equal to i-1, reduce loop count
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for (int j = i+1; j < nums.size()-1; j++) {
            // nums j equal to j-1, reduce loop count
            if ((j > i+1) && (nums[j] == nums[j-1])) {
                continue;
            }
            
            // invert order traverse
            for (int k = ((int)nums.size()-1); k > j; k--) {
                if ((nums[i] + nums[j] + nums[k]) < 0) {
                    break;
                } else if ((nums[i] + nums[j] + nums[k]) == 0) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    break;
                }
            }
        }
    }
    return result;
}

// better solution
vector<vector<int>> Solution::threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
        return {};
    }
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size()-2; i++) {
        // nums[i] must below with zero
        if (nums[i] > 0) {
            continue;
        }
        // nums i equal to i-1, reduce loop count
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        
        // two pointer traverse
        int j = i+1, k = int(nums.size())-1;
        while (j < k) {
            // nums j equal to j-1, reduce loop count
            if ((j > i+1) && (nums[j] == nums[j-1])) {
                j++;
                continue;
            }
            if ((nums[i] + nums[j] + nums[k]) > 0) {
                k--;
            } else if ((nums[i] + nums[j] + nums[k]) < 0) {
                j++;
            } else if ((nums[i] + nums[j] + nums[k]) == 0) {
                result.push_back({nums[i], nums[j], nums[k]});
                j++;
            }
        }
    }
    
    return result;
}

void testThreeSum() {
    vector<int> nums = {0,0,0,0};
    Solution().threeSum(nums);
}
