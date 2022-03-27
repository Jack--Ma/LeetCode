//
//  LowestCommonAncestorOfABinaryTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef LowestCommonAncestorOfABinaryTree_hpp
#define LowestCommonAncestorOfABinaryTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestorOfBinaryTree(TreeNode* root, TreeNode* p, TreeNode* q);
};

void testLowestCommonAncestorOfBinaryTree();

#endif /* LowestCommonAncestorOfABinaryTree_hpp */
