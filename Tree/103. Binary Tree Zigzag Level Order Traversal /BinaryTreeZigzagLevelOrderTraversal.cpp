//
//  BinaryTreeZigzagLevelOrderTraversal.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include <stack>
#include "BinaryTreeZigzagLevelOrderTraversal.hpp"

/**
 Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 
 Input: root = [3,9,20,null,null,15,7]
 Output: [[3],[20,9],[15,7]]
 */

void testZigzagLevelOrder() {
    vector<int> nums = {3,9,20,1,2,15,7};
    printVector(Solution().zigzagLevelOrder(buildTree(nums)));
}

/// solution by use stack
/// @param nodeStack use stack to store current level nodes of tree
/// @param result two-dmension array
/// @param isLeft mark loop direction, true mean left->right
static inline void _zigzagLevelOrder(stack<TreeNode *> nodeStack, vector<vector<int>> &result, bool isLeft) {
    if (nodeStack.empty()) {
        return;
    }
    vector<int> levelNums;
    // build next level nodes stack
    stack<TreeNode *> nextStack;
    while (!nodeStack.empty()) {
        TreeNode *node = nodeStack.top();
        nodeStack.pop();
        // node should be inserted at array head
        levelNums.insert(levelNums.begin(), node->val);
        if (isLeft) {
            if (node->left) {
                nextStack.push(node->left);
            }
            if (node->right) {
                nextStack.push(node->right);
            }
        } else {
            if (node->right) {
                nextStack.push(node->right);
            }
            if (node->left) {
                nextStack.push(node->left);
            }
        }
    }
    
    result.push_back(levelNums);
    _zigzagLevelOrder(nextStack, result, !isLeft);
}

vector<vector<int>> Solution::zigzagLevelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> result;
    stack<TreeNode *> stack;
    stack.push(root);
    _zigzagLevelOrder(stack, result, false);
    
    return result;
}

