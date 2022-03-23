//
//  BinaryTreeZigzagLevelOrderTraversal.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BinaryTreeZigzagLevelOrderTraversal_hpp
#define BinaryTreeZigzagLevelOrderTraversal_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root);
};

void testZigzagLevelOrder();

#endif /* BinaryTreeZigzagLevelOrderTraversal_hpp */
