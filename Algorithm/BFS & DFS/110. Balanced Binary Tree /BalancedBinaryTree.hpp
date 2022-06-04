//
//  BalancedBinaryTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef BalancedBinaryTree_hpp
#define BalancedBinaryTree_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/balanced-binary-tree/
class Solution {
private:
    bool result;
    
public:
    bool isBalanced(TreeNode* root);
};

void testBalancedBinaryTree();

#endif /* BalancedBinaryTree_hpp */
