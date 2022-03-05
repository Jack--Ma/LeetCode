//
//  ValidateBinarySearchTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/4.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "ValidateBinarySearchTree.hpp"

/**
 Given the root of a binary tree, determine if it is a valid binary search tree (BST).
 
 Input: root = [2,1,3]
 Output: true
 
 Input: root = [5,1,4,null,null,3,6]
 Output: false
 Explanation: The root node's value is 5 but its right child's value is 4.
*/

static inline void _isValidBST_recursion(TreeNode *root, stack<int> &numStack, bool &valid) {
    if (!root) {
        return;
    }
    _isValidBST_recursion(root->left, numStack, valid);
    if (!numStack.empty() && root->val <= numStack.top()) {
        valid = false;
    }
    numStack.push(root->val);
    _isValidBST_recursion(root->right, numStack, valid);
}

bool Solution::isValidBST(TreeNode *root) {
    stack<int> numStack;
    bool result = true;
    _isValidBST_recursion(root, numStack, result);
    return result;
}

void testIsValidBST() {
//    vector<int> nums = {2,1,3};
    vector<int> nums = {0,-1};
    cout << Solution().isValidBST(buildTree(nums)) << endl;
}
