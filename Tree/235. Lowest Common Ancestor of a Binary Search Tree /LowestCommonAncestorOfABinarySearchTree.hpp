//
//  LowestCommonAncestorOfABinarySearchTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef LowestCommonAncestorOfABinarySearchTree_hpp
#define LowestCommonAncestorOfABinarySearchTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q);
};

void testLowestCommonAncestor();

#endif /* LowestCommonAncestorOfABinarySearchTree_hpp */
