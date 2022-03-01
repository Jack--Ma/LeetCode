//
//  BinaryTreePostorderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "BinaryTreePostorderTraversal.hpp"

/**
 Given the root of a binary tree, return the postorder traversal of its nodes' values.
 
 Input: root = [1,4,2,3]
 Output: [3,4,2,1]
 */

static inline void _postorderTraversal(TreeNode *root, vector<int> &nums) {
    if (root == NULL) {
        return;
    }
    _postorderTraversal(root->left, nums);
    _postorderTraversal(root->right, nums);
    nums.push_back(root->val);
}

/// postorder by use stack
/// 1. loop curr->left until find null
/// 2. loop right branch when right node exist and first find, otherwise use stack top node and pop stack
static inline void _postorderTraversal_stack(TreeNode *root, vector<int> &nums) {
    stack<TreeNode *> tempStack;
    
    // loop curr node when exist
    TreeNode *curr = root;
    // last stack pop node
    TreeNode *last = nullptr;
    while (curr || !tempStack.empty()) {
        if (curr) {
            tempStack.push(curr);
            curr = curr->left;
        } else {
            TreeNode *top = tempStack.top();
            if (top->right && top->right != last) {
                curr = top->right;
            } else {
                nums.push_back(top->val);
                tempStack.pop();
                last = top;
            }
        }
    }
}

vector<int> Solution::postorderTraversal(TreeNode *root) {
    vector<int> result;
//    _postorderTraversal(root, result);
    _postorderTraversal_stack(root, result);
    return result;
}

void testPostorderTraversal() {
    vector<int> nums = {1,4,2,3};
    TreeNode *root = buildTree(nums);
    Solution().postorderTraversal(root);
}
