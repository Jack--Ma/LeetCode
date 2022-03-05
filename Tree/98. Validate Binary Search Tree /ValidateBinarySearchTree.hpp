//
//  ValidateBinarySearchTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ValidateBinarySearchTree_hpp
#define ValidateBinarySearchTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/validate-binary-search-tree/
class Solution {
public:
    bool isValidBST(TreeNode* root);
};

void testIsValidBST();

#endif /* ValidateBinarySearchTree_hpp */
