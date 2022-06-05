//
//  LinkedListInBinaryTree.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef LinkedListInBinaryTree_hpp
#define LinkedListInBinaryTree_hpp

#include <stdio.h>
#include "ListNode.h"
#include "TreeNode.hpp"

// https://leetcode.com/problems/linked-list-in-binary-tree/
class Solution {
private:
    bool result;
    void _isSubPath_DFS(ListNode *head, TreeNode *root);
    
public:
    bool isSubPath(ListNode* head, TreeNode* root);
};

void testLinkedListInBinaryTree();

#endif /* LinkedListInBinaryTree_hpp */
