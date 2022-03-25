//
//  DeleteNodeInABST.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef DeleteNodeInABST_hpp
#define DeleteNodeInABST_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/delete-node-in-a-bst/
class Solution {
public:
    TreeNode* deleteNodeInBST(TreeNode* root, int key);
};

void testDeleteNodeInBST();

#endif /* DeleteNodeInABST_hpp */
