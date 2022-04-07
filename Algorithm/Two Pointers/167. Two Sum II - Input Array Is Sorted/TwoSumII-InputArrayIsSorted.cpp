//
//  TwoSumII-InputArrayIsSorted.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/7.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "TwoSumII-InputArrayIsSorted.hpp"

/**
 Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

 Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

 The tests are generated such that there is exactly one solution. You may not use the same element twice.

 Your solution must use only constant extra space.
 
 Input: numbers = [2,7,11,15], target = 9
 Output: [1,2]
 Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
 
 Input: numbers = [2,3,4], target = 6
 Output: [1,3]
 Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
 */

void testTwoSumII() {
    vector<int> nums = {-2,-1,0};
    printVector(Solution().twoSumII(nums, -1));
}

vector<int> Solution::twoSumII(vector<int>& numbers, int target) {
    const int size = (int)numbers.size();
    int p = 0, q = size - 1;
    while (q > p) {
        int sum = numbers[p] + numbers[q];
        if (sum == target) {
            // find correct p and q, directly return
            return {p+1, q+1};
        } else if (sum < target) {
            // smaller, should increase left(p) value
            p++;
        } else if (sum > target) {
            // bigger, should decrease right(q) value
            q--;
        }
    }
    
    return {};
}
