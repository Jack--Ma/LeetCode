//
//  ShuffleAnArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ShuffleAnArray.hpp"

/**
 Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.
 
 Implement the Solution class:
 
 Solution(int[] nums) Initializes the object with the integer array nums.
 int[] reset() Resets the array to its original configuration and returns it.
 int[] shuffle() Returns a random shuffling of the array.
 
 Input
 ["Solution", "shuffle", "reset", "shuffle"]
 [[[1, 2, 3]], [], [], []]
 Output
 [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
 */

void testShuffleAnArray() {
    vector<int> nums = {1,2,3};
    Solution_384 sol = Solution_384(nums);
    printVector(sol.shuffle());
    printVector(sol.reset());
    printVector(sol.shuffle());
}

Solution_384::Solution_384(vector<int>& nums) {
    numbers = nums;
}

vector<int> Solution_384::reset() {
    return numbers;
}

vector<int> Solution_384::shuffle() {
    vector<int> shuffle = numbers;
    // from tail to head
    for (int i = (int)numbers.size()-1; i >= 0; i--) {
        int j = rand() % (i+1);
        
        swap(shuffle[i], shuffle[j]);
    }
    
    return shuffle;
}
