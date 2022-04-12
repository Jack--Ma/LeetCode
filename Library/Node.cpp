//
//  Node.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "Node.hpp"

Node* _buildNodeTree(vector<int> nums, int k);

#pragma mark - public

Node* buildNodeTree(vector<int> nums) {
    return _buildNodeTree(nums, 0);
}

#pragma mark - private

Node* _buildNodeTree(vector<int> nums, int k) {
    Node *root = nullptr;
    if (k < nums.size() && nums[k] != INT_MAX) {
        root = new Node(nums[k]);
        root->left = _buildNodeTree(nums, 2*k+1);
        root->right = _buildNodeTree(nums, 2*k+2);
    }
    return root;
}
