//
//  InvertBinaryTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef InvertBinaryTree_hpp
#define InvertBinaryTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/invert-binary-tree/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root);
};

void testInvertTree();

#endif /* InvertBinaryTree_hpp */
