//
//  BinaryTreeInorderTraversal.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BinaryTreeInorderTraversal_hpp
#define BinaryTreeInorderTraversal_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/binary-tree-inorder-traversal/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root);
};

void testInorderTraversal();

#endif /* BinaryTreeInorderTraversal_hpp */
