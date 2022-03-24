//
//  PathSumII.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef PathSumII_hpp
#define PathSumII_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/path-sum-ii/
class Solution {
public:
    vector<vector<int>> pathSumII(TreeNode* root, int targetSum);
};

void testPathSumII();

#endif /* PathSumII_hpp */
