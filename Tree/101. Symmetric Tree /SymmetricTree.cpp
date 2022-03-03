//
//  SymmetricTree.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/3/2.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <stack>
#include <queue>
#include "SymmetricTree.hpp"

/**
 Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 Input: root = [1,2,2,3,4,4,3]
 Output: true
 
 Input: root = [1,2,2,null,3,null,3]
 Output: false
 */

// my solution by use stack
bool Solution::isSymmetric(TreeNode *root) {
    if (!root) {
        return false;
    } else if (!root->left && !root->right) {
        return true;
    } else if (!root->left || !root->right) {
        return false;
    }  else if (root->left->val != root->right->val) {
        return false;
    }
    stack<int> valStack;
    vector<TreeNode *> levelNodes = {root->left, root->right};
    
    while (!levelNodes.empty()) {
        vector<TreeNode *> nextLevelNodes;
        for (int i = 0; i < levelNodes.size(); i++) {
            TreeNode *node = levelNodes.at(i);
            // build next level nodes
            if (node->left) {
                nextLevelNodes.push_back(node->left);
            }
            if (node->right) {
                nextLevelNodes.push_back(node->right);
            }
            
            if (i < levelNodes.size() / 2) {
                // left part tree, stack push node
                valStack.push(node->left ? node->left->val : 999);
                valStack.push(node->right ? node->right->val : 999);
            } else {
                // right part tree, stack pop node
                int leftVal = node->left ? node->left->val : 999;
                if (!valStack.empty() && valStack.top() == leftVal) {
                    valStack.pop();
                } else {
                    return false;
                }
                int rightVal = node->right ? node->right->val : 999;
                if (!valStack.empty() && valStack.top() == rightVal) {
                    valStack.pop();
                } else {
                    return false;
                }
            }
        }
        levelNodes = nextLevelNodes;
    }
    return valStack.empty();
}

// other solution by use recursion
bool isSymmetric_recursion_check(TreeNode *T1, TreeNode* T2) {
    if (T1 == NULL && T2 == NULL) return true;
    if (T1 == NULL || T2 == NULL) return false;
    if (T1->val != T2->val) {
        return false;
    }
    // T1 and T2 is symmetric in this tree
    // make sure T1-left is symmetric with T2-right, and T1-right is symmetric with T1-left
    return isSymmetric_recursion_check(T1->left,T2->right) &&
           isSymmetric_recursion_check(T1->right,T2->left);
}

bool isSymmetric_recursion(TreeNode *root) {
    return isSymmetric_recursion_check(root, root);
}

// other solution by use queue
bool isSymmetric_queue(TreeNode *root) {
    queue<TreeNode *> q1,q2;
    q1.push(root->left);
    q2.push(root->right);
    while (!q1.empty() || !q2.empty()) {
        TreeNode *f = q1.front();
        TreeNode *s = q2.front();
        if (!f && !s) return true;
        if (!f ||!s) break;
        if (f->val != s->val) break;
        q1.pop();
        q2.pop();
        if (f->left || s->right) {
            q1.push(f->left);
            q2.push(s->right);
        }
        if (f->right || s->left) {
            q1.push(f->right);
            q2.push(s->left);
        }
    }
    return q1.empty() && q2.empty();
}

void testIsSymmetric() {
    vector<int> nums = {1,2,2,3,4,4,3};
    cout << Solution().isSymmetric(buildTree(nums)) << endl;
}
