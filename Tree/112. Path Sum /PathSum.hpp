//
//  PathSum.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef PathSum_hpp
#define PathSum_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/path-sum/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum);
};

void testHasPathSum();

#endif /* PathSum_hpp */
