//
//  MaximumSubarray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/16.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MaximumSubarray.hpp"

// my
int Solution::maxSubArray(vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    int largestSum = nums[0];
    int sum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int num = nums[i];
        if (num >= sum + num) {
            sum = num;
        } else {
            sum += num;
        }
        largestSum = max(largestSum, sum);
    }
    
    return largestSum;
}

// other
int otherMaxSubArray(vector<int> &nums) {
    int largestSum = nums[0];
    int sum = 0;
    for (int num : nums) {
        sum = max(sum, 0);
        sum += num;
        largestSum = max(largestSum, sum);
    }
    return largestSum;
}

void testMaxSubArray(void) {
    Solution s = Solution();
    vector<int> nums = {31,-41,59,26,-53,58,97,-93,-23,84};
    cout << s.maxSubArray(nums) << endl;
}
