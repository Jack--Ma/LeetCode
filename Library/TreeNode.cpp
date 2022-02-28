//
//  TreeNode.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "TreeNode.hpp"

TreeNode* _buildTree(vector<int> nums, int k);

TreeNode* buildTree(vector<int> nums) {
    return _buildTree(nums, 0);
}

TreeNode* _buildTree(vector<int> nums, int k) {
    TreeNode *root = nullptr;
    if (k < nums.size() && nums[k] != INT_MAX) {
        root = new TreeNode(nums[k]);
        root->left = _buildTree(nums, 2*k+1);
        root->right = _buildTree(nums, 2*k+2);
    }
    return root;
}

void outputTree(TreeNode *node) {
    // TODO: How to?
}
