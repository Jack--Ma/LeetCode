//
//  ShuffleAnArray.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ShuffleAnArray.hpp"

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
