//
//  Subsets.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef Subsets_hpp
#define Subsets_hpp

#include <stdio.h>

// https://leetcode.com/problems/subsets/
class Solution {
private:
    void _subsets_dfs(vector<int>& nums, int index, vector<int> subNums);
    
public:
    vector<vector<int>> result;
    
    vector<vector<int>> subsets(vector<int>& nums);
};

void testSubsets();

#endif /* Subsets_hpp */
