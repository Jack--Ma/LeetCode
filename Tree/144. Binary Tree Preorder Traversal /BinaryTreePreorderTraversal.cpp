//
//  BinaryTreePreorderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BinaryTreePreorderTraversal.hpp"

/**
 Given the root of a binary tree, return the preorder traversal of its nodes' values.
 Input: root = [1,null,2,3]
 Output: [1,2,3]
 
 Input: root = [1,4,2,3]
 Output: [1,4,3,2]
 */

static inline void _preorderTraversal(TreeNode *root, vector<int> &nums) {
    if (root == NULL) {
        return;
    }
    nums.push_back(root->val);
    _preorderTraversal(root->left, nums);
    _preorderTraversal(root->right, nums);
}

vector<int> Solution::preorderTraversal(TreeNode *root) {
    vector<int> result;
    
    _preorderTraversal(root, result);
    
    return result;
}

void testPreorderTraversal() {
    vector<int> nums = {1,4,2,3};
    TreeNode *root = buildTree(nums);
    Solution().preorderTraversal(root);
}
