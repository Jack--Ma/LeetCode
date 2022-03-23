//
//  ConvertSortedArrayToBinarySearchTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ConvertSortedArrayToBinarySearchTree.hpp"

/**
 Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
 A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
 
 Input: nums = [-10,-3,0,5,9]
 Output: [0,-3,9,-10,null,5]
 Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 
 */
void testSortedArrayToBST() {
    vector<int> nums = {-10,-3};
    outputTree(Solution().sortedArrayToBST(nums));
}

// solution by use recursion
TreeNode* _buildBST(vector<int> nums, int start, int end) {
    if (start > end) {
        return NULL;
    }
    int index = (start + end) / 2;
    TreeNode *node = new TreeNode(nums[index]);
    node->left = _buildBST(nums, start, index - 1);
    node->right = _buildBST(nums, index + 1, end);
    
    return node;
}

TreeNode* Solution::sortedArrayToBST(vector<int> &nums) {
    const int size = (int)nums.size();
    TreeNode *root = _buildBST(nums, 0, size - 1);
    
    return root;
}
