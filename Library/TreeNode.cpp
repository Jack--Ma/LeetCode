//
//  TreeNode.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/28.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "TreeNode.hpp"

int NullTreeNodeVal = INT_MAX;

TreeNode* _buildTree(vector<int> nums, int k);
int _findTreeDepth(TreeNode *root, int depth);
void _printSeriesSpace(int count);

#pragma mark - public

TreeNode* buildTree(vector<int> nums) {
    return _buildTree(nums, 0);
}

bool isLeafNode(TreeNode *node) {
    if (!node) {
        return false;
    }
    return !node->left && !node->right;
}

void outputTree(TreeNode *root) {
    // level order traverse tree and print node
    int depth = _findTreeDepth(root, 0);
    // trverse tree by use queue
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    
    for (int i = 0; i < depth; i++) {
        // print " " front of num
        _printSeriesSpace((pow(2, depth-i-1) - 1));
        int queueSize = (int)nodeQueue.size();
        for (int j = 0; j < queueSize; j++) {
            TreeNode *front = nodeQueue.front();
            nodeQueue.pop();
            // print number or "_"
            if (front->val == NullTreeNodeVal) {
                cout << "_";
            } else {
                printf("%d", front->val);
            }
            _printSeriesSpace((pow(2, depth-i)-1));
            
            // build next level node queue
            if (front->left) {
                nodeQueue.push(front->left);
            } else {
                TreeNode *placeholderNode = new TreeNode(NullTreeNodeVal);
                nodeQueue.push(placeholderNode);
            }
            if (front->right) {
                nodeQueue.push(front->right);
            } else {
                TreeNode *placeholderNode = new TreeNode(NullTreeNodeVal);
                nodeQueue.push(placeholderNode);
            }
        }
        // print " " behind of num
        _printSeriesSpace((pow(2, depth-i-1) - 1));
        cout << endl;
    }
}

#pragma mark - private

TreeNode* _buildTree(vector<int> nums, int k) {
    TreeNode *root = nullptr;
    if (k < nums.size() && nums[k] != NullTreeNodeVal) {
        root = new TreeNode(nums[k]);
        root->left = _buildTree(nums, 2*k+1);
        root->right = _buildTree(nums, 2*k+2);
    }
    return root;
}

int _findTreeDepth(TreeNode *root, int depth) {
    if (root == NULL) {
        return depth;
    }
    int leftDepth = _findTreeDepth(root->left, depth+1);
    int rightDepth = _findTreeDepth(root->right, depth+1);
    return max(leftDepth, rightDepth);
}

void _printSeriesSpace(int count) {
    for (int j = 0; j < count; j++) {
        cout << " ";
    }
}
