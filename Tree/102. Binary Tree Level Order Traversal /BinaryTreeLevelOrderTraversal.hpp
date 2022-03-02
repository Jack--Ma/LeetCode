//
//  BinaryTreeLevelOrderTraversal.hpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/3/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BinaryTreeLevelOrderTraversal_hpp
#define BinaryTreeLevelOrderTraversal_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root);
};

void testLevelOrder();

#endif /* BinaryTreeLevelOrderTraversal_hpp */
