//
//  SquaresOfASortedArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <deque>
#include "SquaresOfASortedArray.hpp"

/**
 Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
 
 Input: nums = [-4,-1,0,3,10]
 Output: [0,1,9,16,100]
 Explanation: After squaring, the array becomes [16,1,0,9,100].
 After sorting, it becomes [0,1,9,16,100].
 
 Input: nums = [-7,-3,2,3,11]
 Output: [4,9,9,49,121]
 */

void testSquaresOfASortedArray() {
    vector<int> nums = {-7,-3,2,3,11};
    printVector(Solution().sortedSquares(nums));
}

// solution by use binary traverse
vector<int> _sortedSquares_binary(vector<int> &nums) {
    const int size = (int)nums.size();
    int start = 0, end = size - 1;
    
    deque<int> result;
    while (start <= end) {
        int startSquare = pow(nums[start], 2);
        int endSquare = pow(nums[end], 2);
        if (endSquare > startSquare) {
            result.push_front(endSquare);
            end--;
        } else {
            result.push_front(startSquare);
            start++;
        }
    }
    
    return vector<int>(result.begin(), result.end());
}

// solution by use sort
vector<int> Solution::sortedSquares(vector<int> &nums) {
    sort(nums.begin(), nums.end(), [](int& a, int& b){
        return abs(a) < abs(b);
    });
    
    vector<int> result = vector_map(nums, [](int& a){
        return a*a;
    });
    
    return result;
}
