//
//  BalancedBinaryTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BalancedBinaryTree.hpp"

/**
 Given a binary tree, determine if it is height-balanced.

 For this problem, a height-balanced binary tree is defined as:
    * a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
 
 Input: root = [3,9,20,null,null,15,7]
 Output: true
 
 Input: root = [1,2,2,3,3,null,null,4,4]
 Output: false
 */
void testBalancedBinaryTree() {
    vector<int> nums = {1,2,2,3,3,NullTreeNodeVal,NullTreeNodeVal,4,4};
    TreeNode *root = buildTree(nums);
    cout << Solution().isBalanced(root) << endl;
}

int _isBalanced_DFS(TreeNode *root, int depth, bool &result) {
    if (!root) {
        return depth;
    }
    int leftTreeDepth = _isBalanced_DFS(root->left, depth+1, result);
    int rightTreeDepth = _isBalanced_DFS(root->right, depth+1, result);
    
    if (abs(leftTreeDepth - rightTreeDepth) > 1) {
        result = false;
    }
    return max(leftTreeDepth, rightTreeDepth);
}

bool Solution::isBalanced(TreeNode *root) {
    result = true;
    _isBalanced_DFS(root, 0, result);
    
    return result;
}
