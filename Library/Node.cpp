//
//  Node.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "Node.hpp"

Node* _buildNodeTree(vector<int> nums, int k);
void _outputNodeTreeByRight(Node* root);

#pragma mark - public

Node* buildNodeTree(vector<int> nums) {
    return _buildNodeTree(nums, 0);
}

void outputNodeTreeByRight(Node* root) {
    if (!root || !root->right) {
        assert("root node must be not nil!");
    }
    // print every level nodes by use right node
    cout << "[";
    _outputNodeTreeByRight(root);
    cout << "]" << endl;
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

void _outputNodeTreeByRight(Node* root) {
    Node *p = root;
    while (p) {
        cout << p->val << ",";
        p = p->next;
    }
    cout << "#";
    if (root->left) {
        cout << ",";
        _outputNodeTreeByRight(root->left);
    }
}
