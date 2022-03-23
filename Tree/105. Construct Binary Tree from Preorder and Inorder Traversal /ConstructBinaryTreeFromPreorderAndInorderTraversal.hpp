//
//  ConstructBinaryTreeFromPreorderAndInorderTraversal.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ConstructBinaryTreeFromPreorderAndInorderTraversal_hpp
#define ConstructBinaryTreeFromPreorderAndInorderTraversal_hpp

#include <stdio.h>
#include "TreeNode.hpp"

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
class Solution {
private:
    int index;
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end);
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
};

void testConstructBinaryTreeFromPreorderAndInorderTraversal();

#endif /* ConstructBinaryTreeFromPreorderAndInorderTraversal_hpp */
