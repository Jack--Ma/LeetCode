//
//  CombinationSumII.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef CombinationSumII_hpp
#define CombinationSumII_hpp

#include <stdio.h>

// https://leetcode.com/problems/combination-sum-ii/
class Solution {
private:
    vector<int> candidates;
    int target;
    void _combinationSum2(vector<int> subNums, int index, int leftTarget);
    
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
};

void testCombinationSumII();

#endif /* CombinationSumII_hpp */
