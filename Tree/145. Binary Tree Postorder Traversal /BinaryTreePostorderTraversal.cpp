//
//  BinaryTreePostorderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

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

vector<int> Solution::postorderTraversal(TreeNode *root) {
    vector<int> result;
    _postorderTraversal(root, result);
    return result;
}

void testPostorderTraversal() {
    vector<int> nums = {1,4,2,3};
    TreeNode *root = buildTree(nums);
    Solution().postorderTraversal(root);
}
