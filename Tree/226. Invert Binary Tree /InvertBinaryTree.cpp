//
//  InvertBinaryTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "InvertBinaryTree.hpp"

/**
 Given the root of a binary tree, invert the tree, and return its root.

 Input: root = [4,2,7,1,3,6,9]
 Output: [4,7,2,9,6,3,1]
 
 Input: root = [2,1,3]
 Output: [2,3,1]
 */

// my solution by use recursion
static inline void _invertTree_recursion(TreeNode *root) {
    if (!root) {
        return;
    }
    swap(root->left, root->right);
    _invertTree_recursion(root->left);
    _invertTree_recursion(root->right);
}

TreeNode* Solution::invertTree(TreeNode *root) {
    if (root) {
        TreeNode *tempNode = root->right;
        root->right = invertTree(root->left);
        root->left = invertTree(tempNode);
    }
//    _invertTree_recursion(root);
    return root;
}

// other solution by use queue
TreeNode* _invertTree_queue(TreeNode *root)  {
    if (!root) {
        return NULL;
    }
    
    queue<TreeNode *> treeQueue;
    treeQueue.push(root);
    
    // use queue traverse tree node
    while (!treeQueue.empty()) {
        // treeQueue store tree's node in some level
        for (int i = 0; i < treeQueue.size(); i++) {
            TreeNode *node = treeQueue.front();
            treeQueue.pop();
            // swap every node->left and node->right child node
            swap(node->left, node->right);
            if (node->left) {
                treeQueue.push(node->left);
            }
            if (node->right) {
                treeQueue.push(node->right);
            }
        }
    }
    
    return root;
}

void testInvertTree() {
    vector<int> nums = {4,2,7,1,3,6,9};
    Solution().invertTree(buildTree(nums));
}
