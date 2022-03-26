//
//  KthSmallestElementInABST.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "KthSmallestElementInABST.hpp"

/**
 Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.
 
 Input: root = [3,1,4,null,2], k = 1
 Output: 1
 
 Input: root = [5,3,6,2,4,null,null,1], k = 3
 Output: 3
 */

void testKthSmallest() {
    vector<int> nums = {5,3,6,2,4,NullTreeNodeVal,NullTreeNodeVal,1};
    cout << Solution().kthSmallest(buildTree(nums), 0) << endl;
}

static inline void _kthSmallest_inorderTraverse(TreeNode *root, vector<int> &smallNums, int k) {
    if (!root) {
        return;
    }
    if (root->left) {
        _kthSmallest_inorderTraverse(root->left, smallNums, k);
    }
    if (smallNums.size() < k) {
        smallNums.push_back(root->val);
    }
    if (root->right) {
        _kthSmallest_inorderTraverse(root->right, smallNums, k);
    }
}

int Solution::kthSmallest(TreeNode *root, int k) {
    vector<int> smallNums;
    _kthSmallest_inorderTraverse(root, smallNums, k);
    if (smallNums.size() > 0) {
        return smallNums[smallNums.size() - 1];
    }
    return -1;
}
