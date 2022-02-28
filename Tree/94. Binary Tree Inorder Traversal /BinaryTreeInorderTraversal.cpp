//
//  BinaryTreeInorderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BinaryTreeInorderTraversal.hpp"

/**
 Given the root of a binary tree, return the inorder traversal of its nodes' values.
 inorder traversal: left->current->right
 
 Input: root = [1,null,2,3]
 Output: [1,3,2]
 */

static inline void _inorderTraversal(TreeNode *root, vector<int> &nums) {
    if (root == nullptr) {
        return;
    }
    _inorderTraversal(root->left, nums);
    nums.push_back(root->val);
    _inorderTraversal(root->right, nums);
}

vector<int> Solution::inorderTraversal(TreeNode *root) {
    vector<int> result;
    _inorderTraversal(root, result);
    return result;
}

void testInorderTraversal() {
    vector<int> nums = {1,4,2,3};
    TreeNode *root = buildTree(nums);
    Solution().inorderTraversal(root);
}
