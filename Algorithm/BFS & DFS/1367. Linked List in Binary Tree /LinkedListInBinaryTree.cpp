//
//  LinkedListInBinaryTree.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LinkedListInBinaryTree.hpp"

/**
 Given a binary tree root and a linked list with head as the first node.

 Return True if all the elements in the linked list starting from the head correspond to some downward path connected in the binary tree otherwise return False.
 
 Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
 Output: true
 Explanation: Nodes in blue form a subpath in the binary Tree.  
 */

void testLinkedListInBinaryTree() {
    /**
     [1,10]
     [1,null,1,10,1,9]
     [2,2,1]
     [2,null,2,null,2,null,1]
     */
    vector<int> listNums = {2,2,1};
    vector<int> treeNums = {2,NullTreeNodeVal,2,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,2,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,NullTreeNodeVal,1};
    ListNode *head = buildList(listNums);
    TreeNode *root = buildTree(treeNums);
    outputTree(root);
    cout << Solution().isSubPath(head, root) << endl;
}

void Solution::_isSubPath_DFS(ListNode *head, TreeNode *root) {
    if (result) {
        return;
    }
    if (!head) {
        result = true;
        return;
    }
    if (!root) {
        return;
    }
    if (root->val == head->val) {
        _isSubPath_DFS(head->next, root->left);
        _isSubPath_DFS(head->next, root->right);
    }
}

bool Solution::isSubPath(ListNode *head, TreeNode *root) {
    if (result) {
        return result;
    }
    // adjust there is subPath from "root" node 
    _isSubPath_DFS(head, root);
    // loop every node in tree
    if (root->left) {
        isSubPath(head, root->left);
    }
    if (root->right) {
        isSubPath(head, root->right);
    }

    return result;
}
