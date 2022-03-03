//
//  PathSum.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "PathSum.hpp"

/**
 Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
 
 Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
 Output: true
 Explanation: The root-to-leaf path with the target sum is shown.
 
 Input: root = [1,2,3], targetSum = 5
 Output: false
 Explanation: There two root-to-leaf paths in the tree:
 (1 --> 2): The sum is 3.
 (1 --> 3): The sum is 4.
 There is no root-to-leaf path with sum = 5.
 */

// my solution by usr recursion
static inline bool _hasPathSum_recursion(TreeNode *root, int targetSum) {
    if (!root) {
        return false;
    }
    if (root->left || root->right) {
        // not leaf node, recurse left and right node
        bool left = _hasPathSum_recursion(root->left, targetSum-root->val);
        bool right = _hasPathSum_recursion(root->right, targetSum-root->val);
        return (left || right);
    } else {
        // leaf node, judge value equal
        return targetSum == root->val;
    }
}

bool Solution::hasPathSum(TreeNode *root, int targetSum) {
    return _hasPathSum_recursion(root, targetSum);
}

void testHasPathSum() {
    vector<int> nums = {5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,INT_MAX,1};
    cout << Solution().hasPathSum(buildTree(nums), 17) << endl;
}
