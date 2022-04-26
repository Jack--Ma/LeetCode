//
//  CombinationSum.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef CombinationSum_hpp
#define CombinationSum_hpp

#include <stdio.h>

// https://leetcode.com/problems/combination-sum/
class CombinationSumSolution {
private:
    vector<int> candidates;
    int target;
    
    void _combinationSum(vector<int> subNums, int index, int leftTarget);
    
public:
    vector<vector<int>> result;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
};

void testCombinationSum();

#endif /* CombinationSum_hpp */
