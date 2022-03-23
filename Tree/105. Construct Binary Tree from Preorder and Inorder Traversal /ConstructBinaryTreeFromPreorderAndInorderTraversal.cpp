//
//  ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ConstructBinaryTreeFromPreorderAndInorderTraversal.hpp"

/**
 Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
 
 Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 Output: [3,9,20,null,null,15,7]
*/

void testConstructBinaryTreeFromPreorderAndInorderTraversal() {
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    outputTree(Solution().buildTree(preorder, inorder));
}

TreeNode* Solution::_buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
    if (start > end) {
        return NULL;
    }
    // build current node
    TreeNode *node = new TreeNode(preorder[index++]);
    
    // calculate node left and right, in inorder list, the numbers before pos are in the left-branch, the numbers after pos are in the right-branch
    int pos = 0;
    for (int i = start; i <= end; i++) {
        if (inorder[i] == node->val) {
            pos = i;
            break;
        }
    }
    
    // build left and right branch
    node->left = _buildTree(preorder, inorder, start, pos - 1);
    node->right = _buildTree(preorder, inorder, pos + 1, end);
    
    return node;
}

TreeNode* Solution::buildTree(vector<int>& preorder, vector<int>& inorder) {
    index = 0;
    TreeNode *root = _buildTree(preorder, inorder, 0, (int)preorder.size() - 1);
    
    return root;
}
