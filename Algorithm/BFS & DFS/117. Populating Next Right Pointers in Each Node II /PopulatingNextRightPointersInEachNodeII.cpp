//
//  PopulatingNextRightPointersInEachNodeII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/22.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <queue>
#include "PopulatingNextRightPointersInEachNodeII.hpp"

/**
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 
 Initially, all next pointers are set to NULL.
 
 Input: root = [1,2,3,4,5,null,7]
 Output: [1,#,2,3,#,4,5,7,#]
 Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
 */

void testPopulatingNextRightPointersInEachNodeII() {
    vector<int> nums = {1,2,3,4,5,INT_MAX,7};
    Node *root = buildNodeTree(nums);
    Solution().populatingNextRightPointersInEachNodeII(root);
    outputNodeTreeByRight(root);
}

/// solution by use BFS
void _populatingNextRightPointersInEachNodeII(queue<Node *> nodeQueue) {
    if (nodeQueue.empty()) {
        return;
    }
    
    const int size = (int)nodeQueue.size();
    for (int i = 0; i < size; i++) {
        Node *front = nodeQueue.front();
        nodeQueue.pop();
        // not the rightmost node
        if (i < size-1) {
            front->next = nodeQueue.front();
        }
        // build next level node queue
        if (front->left) {
            nodeQueue.push(front->left);
        }
        if (front->right) {
            nodeQueue.push(front->right);
        }
    }
    _populatingNextRightPointersInEachNodeII(nodeQueue);
}

Node* Solution::populatingNextRightPointersInEachNodeII(Node *root) {
    if (!root) {
        return root;
    }
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    _populatingNextRightPointersInEachNodeII(nodeQueue);
    return root;
}
