//
//  BinaryTreePostorderTraversal.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BinaryTreePostorderTraversal_hpp
#define BinaryTreePostorderTraversal_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root);
};

void testPostorderTraversal();

#endif /* BinaryTreePostorderTraversal_hpp */
