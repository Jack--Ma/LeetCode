//
//  BinaryTreePreorderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
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

/// preorder by use stack
/// 1. Add root node into stack, loop stack when it's not empty
/// 2. Pop stack top node
/// 3. Add right node into stack, add left node into stack
static inline void _preorderTraversal_stack(TreeNode *root, vector<int> &nums) {
    stack<TreeNode *> tempStack;
    tempStack.push(root);
    
    while (!tempStack.empty()) {
        nums.push_back(tempStack.top()->val);
        tempStack.pop();
        if (root->right != NULL) {
            tempStack.push(root->right);
        }
        if (root->left != NULL) {
            tempStack.push(root->left);
        }
    }
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
