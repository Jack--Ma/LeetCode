//
//  SubsetsII.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef SubsetsII_hpp
#define SubsetsII_hpp

#include <stdio.h>

// https://leetcode.com/problems/subsets-ii/
class Solution {
private:
    vector<int> nums;
    
    void _subsetsWithDup(int index, vector<int> subNums);
    
public:
    vector<vector<int>> result;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums);
};

void testSubsetsII();

#endif /* SubsetsII_hpp */
