//
//  SubtreeOfAnotherTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef SubtreeOfAnotherTree_hpp
#define SubtreeOfAnotherTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/subtree-of-another-tree/
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot);
};

void testSubtreeOfAnotherTree();

#endif /* SubtreeOfAnotherTree_hpp */
