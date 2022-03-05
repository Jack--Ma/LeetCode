//
//  LowestCommonAncestorOfABinarySearchTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include "LowestCommonAncestorOfABinarySearchTree.hpp"

/**
 Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
 The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants
 
 Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
 Output: 6
 Explanation: The LCA of nodes 2 and 8 is 6.
 
 Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
 Output: 2
 Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

// my solution by use stack
TreeNode* Solution::lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *pNode = root, *qNode = root;
    stack<TreeNode *> pStack, qStack;
    // left branch traverse, build p node parent node list
    while (pNode) {
        pStack.push(pNode);
        if (p->val == pNode->val) {
            break;
        } else if (p->val < pNode->val) {
            pNode = pNode->left;
        } else if (p->val > pNode->val) {
            pNode = pNode->right;
        }
    }
    // right branch traverse, build q node parent node list
    while (qNode) {
        qStack.push(qNode);
        if (q->val == qNode->val) {
            break;
        } else if (q->val < qNode->val) {
            qNode = qNode->left;
        } else if (q->val > qNode->val) {
            qNode = qNode->right;
        }
    }
    
    // traverse two stack to find common parent
    while (!pStack.empty() || !qStack.empty()) {
        if (pStack.size() <= qStack.size()) {
            if (qStack.top() != pStack.top()) {
                qStack.pop();
            } else {
                return qStack.top();
            }
        } else {
            if (qStack.top() != pStack.top()) {
                pStack.pop();
            } else {
                return pStack.top();
            }
        }
    }
    
    return root;
}

// other better solution by use recursion
TreeNode* _lowestCommonAncestor_recursion(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root) return root;
    if (root->val < p->val && root->val < q->val) {
        // root value is smaller than left and right
        return _lowestCommonAncestor_recursion(root->right, p, q);
    } else if (root->val > p->val && root->val > q->val) {
        // root value is bigger than left and right
        return _lowestCommonAncestor_recursion(root->left, p, q);
    } else {
        return root;
    }
}

void testLowestCommonAncestor() {
    vector<int> nums = {6,2,8,0,4,7,9,NullTreeNodeVal,NullTreeNodeVal,3,5};
    TreeNode *root = buildTree(nums);
    Solution().lowestCommonAncestor(root, root->left, root->right);
}
