//
//  PopulatingNextRightPointersInEachNode.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/4/12.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "PopulatingNextRightPointersInEachNode.hpp"

/**
 You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
 
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
 Input: root = [1,2,3,4,5,6,7]
 Output: [1,#,2,3,#,4,5,6,7,#]
 Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 */

void testPopulatingNextRightPointersInEachNode() {
    Node* root = buildNodeTree({1});
    Solution().connect(root);
}

/// solution by use recursion
void _connect_recursion(queue<Node *> nodeQueue) {
    if (nodeQueue.empty()) {
        return;
    }
    queue<Node *> nextNodeQueue;
    while (!nodeQueue.empty()) {
        Node* top = nodeQueue.front();
        nodeQueue.pop();
        // set up node's next pointer
        if (!nodeQueue.empty()) {
            top->next = nodeQueue.front();
        }
        if (top->left) {
            nextNodeQueue.push(top->left);
        }
        if (top->right) {
            nextNodeQueue.push(top->right);
        }
    }
    _connect_recursion(nextNodeQueue);
}

Node* Solution::connect(Node* root) {
    if (!root) {
        return root;
    }
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    _connect_recursion(nodeQueue);
    
    return root;
}
