//
//  InsertIntoABinarySearchTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/3.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "InsertIntoABinarySearchTree.hpp"

/**
 You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
 
 Input: root = [4,2,7,1,3], val = 5
 Output: [4,2,7,1,3,5]
*/

// my solution
TreeNode* Solution::insertIntoBST(TreeNode *root, int val) {
    if (!root) {
        return new TreeNode(val);
    }
    TreeNode *node = root;
    while (node) {
        // BST is a sort tree
        if (val > node->val) {
            // find right branch
            if (node->right) {
                node = node->right;
            } else {
                TreeNode *newNode = new TreeNode(val);
                node->right = newNode;
                break;
            }
        } else if (val < node->val) {
            // find left branch
            if (node->left) {
                node = node->left;
            } else {
                TreeNode *newNode = new TreeNode(val);
                node->left = newNode;
                break;
            }
        }
    }
    
    return root;
}

void testInsertIntoBST() {
//    vector<int> nums = {4,2,7,1,3};
    vector<int> nums = {40,20,60,10,30,50,70};
    
    outputTree(Solution().insertIntoBST(buildTree(nums), 25));
}
