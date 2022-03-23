//
//  BinaryTreeRightSideView.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "BinaryTreeRightSideView.hpp"

/**
 Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 
 Input: root = [1,2,3,null,5,null,4]
 Output: [1,3,4]
*/
void testRightSideView() {
    vector<int> nums = {};
    printVector(Solution().rightSideView(buildTree(nums)));
}

/// solution by use queue
/// @param nodeQueue the nodes in queue from front to behind, represent the node in tree from right to left
/// @param result store the most right side node value in evevy layer of tree
static inline void _rightSideView(queue<TreeNode *> nodeQueue, vector<int> &result) {
    if (nodeQueue.empty()) {
        return;
    }
    // front node is the most right node in this layer
    result.push_back(nodeQueue.front()->val);
    queue<TreeNode *> nextQueue;
    // build next layer nodes from right to left
    while (!nodeQueue.empty()) {
        TreeNode *node = nodeQueue.front();
        if (node->right) {
            nextQueue.push(node->right);
        }
        if (node->left) {
            nextQueue.push(node->left);
        }
        nodeQueue.pop();
    }
    // traverse next layer
    _rightSideView(nextQueue, result);
}

vector<int> Solution::rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> queue;
    if (root) {
        queue.push(root);
    }
    _rightSideView(queue, result);
    
    return result;
}
