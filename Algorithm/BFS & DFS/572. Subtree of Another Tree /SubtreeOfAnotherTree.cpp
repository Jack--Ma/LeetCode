//
//  SubtreeOfAnotherTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/23.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "SubtreeOfAnotherTree.hpp"

/**
 Given the roots of two binary trees root and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.
 
 A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants. The tree tree could also be considered as a subtree of itself.
 
 Input: root = [3,4,5,1,2], subRoot = [4,1,2]
 Output: true
 */

void testSubtreeOfAnotherTree() {
    TreeNode *root = buildTree({3,4,5,1,2});
    TreeNode *subRoot = buildTree({4,1,2});
    cout << Solution().isSubtree(root, subRoot) << endl;
}

bool Solution::isSubtree(TreeNode *root, TreeNode *subRoot) {
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty()) {
        const int size = (int)nodeQueue.size();
        for (int i = 0; i < size; i++) {
            TreeNode *front = nodeQueue.front();
            if (isSameTree(front, subRoot)) {
                return true;
            }
            nodeQueue.pop();
            if (front->left) {
                nodeQueue.push(front->left);
            }
            if (front->right) {
                nodeQueue.push(front->right);
            }
        }
    }
    
    return false;
}
