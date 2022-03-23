//
//  ConvertSortedArrayToBinarySearchTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ConvertSortedArrayToBinarySearchTree_hpp
#define ConvertSortedArrayToBinarySearchTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums);
};

void testSortedArrayToBST();

#endif /* ConvertSortedArrayToBinarySearchTree_hpp */
