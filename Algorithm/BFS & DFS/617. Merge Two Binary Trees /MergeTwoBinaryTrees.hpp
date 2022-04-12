//
//  MergeTwoBinaryTrees.hpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef MergeTwoBinaryTrees_hpp
#define MergeTwoBinaryTrees_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/merge-two-binary-trees/
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2);
};

void testMergeTwoBinaryTrees();

#endif /* MergeTwoBinaryTrees_hpp */
