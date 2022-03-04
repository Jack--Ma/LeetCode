//
//  InsertIntoABinarySearchTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef InsertIntoABinarySearchTree_hpp
#define InsertIntoABinarySearchTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/insert-into-a-binary-search-tree/
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val);
};

void testInsertIntoBST();

#endif /* InsertIntoABinarySearchTree_hpp */
