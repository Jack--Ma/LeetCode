//
//  BinaryTreePreorderTraversal.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BinaryTreePreorderTraversal_hpp
#define BinaryTreePreorderTraversal_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root);
};

void testPreorderTraversal();

#endif /* BinaryTreePreorderTraversal_hpp */
