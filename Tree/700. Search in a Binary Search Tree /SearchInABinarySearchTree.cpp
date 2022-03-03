//
//  SearchInABinarySearchTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "SearchInABinarySearchTree.hpp"

/**
 binary search tree (BST)
 Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

 Input: root = [4,2,7,1,3], val = 2
 Output: [2,1,3]
 */

// my solution by use stack
TreeNode* Solution::searchBST(TreeNode *root, int val) {
    // BST use inorder traverse
    stack<TreeNode *> nodeStack;
    TreeNode *node = root;
    while (node || !nodeStack.empty()) {
        if (node) {
            nodeStack.push(node);
            node = node->left;
        } else {
            TreeNode *top = nodeStack.top();
            // find val and return
            if (top->val == val) {
                return top;
            }
            nodeStack.pop();
            node = top->right;
        }
    }
    return NULL;
}

// other solution by use recursion
TreeNode* _searchBST_recursion(TreeNode *root, int val) {
    // BST is a sort tree,
    // node->left is less then node, node->right is bigger then node
    if (!root) {
        return NULL;
    } else if (root->val < val) {
        return _searchBST_recursion(root->right, val);
    } else if (root->val > val) {
        return _searchBST_recursion(root->left, val);
    } else {
        return root;
    }
}

void testSearchBST() {
    vector<int> nums = {4,2,7,1,3};
    outputTree(Solution().searchBST(buildTree(nums), 5));
}
