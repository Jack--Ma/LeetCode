//
//  BinaryTreeLevelOrderTraversal.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/3/1.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "BinaryTreeLevelOrderTraversal.hpp"

/**
 Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 
 Input: root = [3,9,20,null,null,15,7]
 Output: [[3],[9,20],[15,7]]
 
 Input: root = [1,2,3,4,null,null,5]
 Output: [[1],[2,3],[4,5]]
 */

/// tree traversal from top to bottom
vector<vector<int>> Solution::levelOrder(TreeNode *root) {
    if (root == NULL) {
        return {};
    }
    vector<vector<int>> result;
    // current level nodes
    vector<TreeNode *> levelNodes = {root};
    result.push_back({root->val});
    
    // loop until current level nodes is empty
    while (levelNodes.size() > 0) {
        // save next level nodes
        vector<TreeNode *> nextLevelNodes;
        vector<int> nodeChildNums;
        for (TreeNode *node : levelNodes) {
            if (node->left) {
                nodeChildNums.push_back(node->left->val);
                nextLevelNodes.push_back(node->left);
            }
            if (node->right) {
                nodeChildNums.push_back(node->right->val);
                nextLevelNodes.push_back(node->right);
            }
        }
        if (nodeChildNums.size() > 0) {
            result.push_back(nodeChildNums);
        }
        // finish tree current level nodes loop
        levelNodes = nextLevelNodes;
    }
    
    return result;
}

void testLevelOrder() {
    vector<int> nums = {1,2,3,4,INT_MAX,INT_MAX,5};
    Solution().levelOrder(buildTree(nums));
}
