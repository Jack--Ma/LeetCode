//
//  MaximumDepthOfBinaryTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/2.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MaximumDepthOfBinaryTree.hpp"

/**
 Given the root of a binary tree, return its maximum depth.

 Input: root = [3,9,20,null,null,15,7]
 Output: 3
 
 Input: root = [1,null,2]
 Output: 2
 */

/// use recursion to find max depth
static inline int _findTreeDepth(TreeNode *root, int depth) {
    if (root == NULL) {
        return depth;
    }
    int leftDepth = _findTreeDepth(root->left, depth+1);
    int rightDepth = _findTreeDepth(root->right, depth+1);
    return max(leftDepth, rightDepth);
}

int Solution::maxDepth(TreeNode *root) {
    return _findTreeDepth(root, 0);
}

int otherMaxDepth(TreeNode *root) {
    if (root == NULL) {
        return 0;
    }
    return 1+max(otherMaxDepth(root->left), otherMaxDepth(root->right));
}

void testMaxDepth() {
    vector<int> nums = {3,INT_MAX,7};
    cout << Solution().maxDepth(buildTree(nums)) << endl;
}
