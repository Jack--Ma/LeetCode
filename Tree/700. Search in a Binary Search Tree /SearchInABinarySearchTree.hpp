//
//  SearchInABinarySearchTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef SearchInABinarySearchTree_hpp
#define SearchInABinarySearchTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/search-in-a-binary-search-tree/
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val);
};

void testSearchBST();

#endif /* SearchInABinarySearchTree_hpp */
