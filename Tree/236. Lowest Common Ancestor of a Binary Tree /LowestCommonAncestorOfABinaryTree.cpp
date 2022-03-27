//
//  LowestCommonAncestorOfABinaryTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LowestCommonAncestorOfABinaryTree.hpp"

/**
 Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

 The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).
 
 Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 Output: 3
 Explanation: The LCA of nodes 5 and 1 is 3.
 
 Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 Output: 5
 Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 */

void testLowestCommonAncestorOfBinaryTree() {
    vector<int> nums = {3,5,1,6,2,0,8,NullTreeNodeVal,NullTreeNodeVal,7,4};
    TreeNode *root = buildTree(nums);
    TreeNode *p = findTreeNode(root, 7);
    TreeNode *q = findTreeNode(root, 4);
    outputTree(Solution().lowestCommonAncestorOfBinaryTree(root, p, q));
}

void _lowestCommonAncestor_findNode(TreeNode *root, TreeNode *node, vector<TreeNode *> nodeList, vector<TreeNode *> &result) {
    if (!root || result.size() > 0) {
        return;
    }
    nodeList.push_back(root);
    if (root == node) {
        result = nodeList;
    }
    if (result.size() > 0) {
        return;
    }
    _lowestCommonAncestor_findNode(root->left, node, nodeList, result);
    if (result.size() > 0) {
        return;
    }
    _lowestCommonAncestor_findNode(root->right, node, nodeList, result);
}

// my solution by use recursion
// Memory Limit Exceeded
TreeNode* _lowestCommonAncestorOfBinaryTree_my(TreeNode *root, TreeNode *p, TreeNode *q) {
    vector<TreeNode *> pNodeParents, qNodeParents;
    _lowestCommonAncestor_findNode(root, p, {}, pNodeParents);
    _lowestCommonAncestor_findNode(root, q, {}, qNodeParents);
    
    TreeNode *result = root;
    for (int i = 0; i < min(pNodeParents.size(), qNodeParents.size()); i++) {
        if (pNodeParents[i] == qNodeParents[i]) {
            result = pNodeParents[i];
        }
    }
    
    return result;
}

// better solution by use DFS
TreeNode* _lowestCommonAncestorOfBinaryTree_better(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
        return NULL;
    }
    // find p or q, there is no need to recurse root children nodes
    if (root == p || root == q) {
        return root;
    }
    
    // use DFS to traverse all node
    TreeNode *left = _lowestCommonAncestorOfBinaryTree_better(root->left, p, q);
    TreeNode *right = _lowestCommonAncestorOfBinaryTree_better(root->right, p, q);
    
    if (left && right) {
        // if left and right all exist, that mean current node is the LCA
        return root;
    } else if (left) {
        // the exist node represent the LCA node
        return left;
    } else if (right) {
        // the exist node represent the LCA node
        return right;
    } else {
        // if left and right all not exist, mean current root node is not the LCA
        return NULL;
    }
}

TreeNode* Solution::lowestCommonAncestorOfBinaryTree(TreeNode *root, TreeNode *p, TreeNode *q) {
    return _lowestCommonAncestorOfBinaryTree_better(root, p, q);
}
