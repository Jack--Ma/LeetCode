//
//  PathSumII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PathSumII.hpp"

/**
 Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
 
 A root-to-leaf path is a path starting from the root and ending at any leaf node.
 A leaf is a node with no children.
 
 Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 Output: [[5,4,11,2],[5,8,4,5]]
 Explanation: There are two paths whose sum equals targetSum:
 5 + 4 + 11 + 2 = 22
 5 + 8 + 4 + 5 = 22
 
 Input: root = [1,2,3], targetSum = 5
 Output: []
 */

void testPathSumII() {
    vector<int> nums = {5,4,8,11,NullTreeNodeVal,13,4,7,2,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,5,1};
    TreeNode *root = buildTree(nums);
    outputTree(root);
    printVector(Solution().pathSumII(root, 22));
}

/// solution by use recursion
/// @param root every node in tree
/// @param targetSum from root node the target sum
/// @param nums before root node, the root node's parent nodes value array
/// @param result two-dimension array store the appropriate nums
static inline void _pathSumII(TreeNode* root, int targetSum, vector<int> nums, vector<vector<int>> &result) {
    // find the leaf node and return
    if (!root) {
        return;
    }
    // nums array store all parent nodes' value
    nums.push_back(root->val);
    
    int leftTarget = targetSum - root->val;
    // root node is leaf node, and target is reachable
    if (!root->left && !root->right && leftTarget == 0) {
        result.push_back(nums);
        return;
    }
    _pathSumII(root->left, leftTarget, nums, result);
    _pathSumII(root->right, leftTarget, nums, result);
}

vector<vector<int>> Solution::pathSumII(TreeNode* root, int targetSum) {
    vector<vector<int>> result;
    _pathSumII(root, targetSum, {}, result);
    return result;
}
