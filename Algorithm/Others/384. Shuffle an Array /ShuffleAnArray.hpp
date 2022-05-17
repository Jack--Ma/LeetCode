//
//  ShuffleAnArray.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/5/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ShuffleAnArray_hpp
#define ShuffleAnArray_hpp

#include <stdio.h>

// https://leetcode.com/problems/shuffle-an-array/
class Solution_384 {
private:
    vector<int> numbers;
    
public:
    Solution_384(vector<int>& nums);
    
    vector<int> reset();
    
    vector<int> shuffle();
};

void testShuffleAnArray();

#endif /* ShuffleAnArray_hpp */
