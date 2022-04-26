//
//  PermutationsII.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef PermutationsII_hpp
#define PermutationsII_hpp

#include <stdio.h>

// https://leetcode.com/problems/permutations-ii/
class Solution {
private:
    vector<int> nums;
    void _permuteUnique(vector<int> subNums);
    
public:
    vector<vector<int>> result;
    vector<vector<int>> permuteUnique(vector<int>& nums);
};

void testPermutationsII();

#endif /* PermutationsII_hpp */
