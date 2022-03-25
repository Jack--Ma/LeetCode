//
//  DeleteNodeInABST.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "DeleteNodeInABST.hpp"

/**
 Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 
 Input: root = [5,3,6,2,4,null,7], key = 3
 Output: [5,4,6,2,null,null,7]
 Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
 One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
 Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.
 
 Input: root = [5,3,6,2,4,null,7], key = 0
 Output: [5,3,6,2,4,null,7]
 Explanation: The tree does not contain a node with value = 0.
 */

void testDeleteNodeInBST() {
    vector<int> nums = {};
    outputTree(Solution().deleteNodeInBST(buildTree(nums), 5));
}

TreeNode* Solution::deleteNodeInBST(TreeNode *root, int key) {
    if (!root) {
        return NULL;
    }
    if (key < root->val) {
        // if key is smaller than root value, just handle left branch
        root->left = deleteNodeInBST(root->left, key);
    } else if (key > root->val) {
        // if key is bigger than root value, just handle right branch
        root->right = deleteNodeInBST(root->right, key);
    } else {
        // find the key node
        if (!root->left && !root->right) {
            // the leaf node, just delete it
            return NULL;
        } else if (root->left && root->right) {
            // need find the nearest node with node value
            // eg. root node val=5, and nearest node val=6 or node val=4
            // here, we find minimum node in right branch
            TreeNode *minNode = root->right;
            while (minNode->left) {
                minNode = minNode->left;
            }
            // change root value with nearest value
            root->val = minNode->val;
            // delete minNode value in right branch
            root->right = deleteNodeInBST(root->right, minNode->val);
        } else if (root->left) {
            // no right branch, just return left node
            return root->left;
        } else {
            // no left branch, just return right node
            return root->right;
        }
    }
    return root;
}
