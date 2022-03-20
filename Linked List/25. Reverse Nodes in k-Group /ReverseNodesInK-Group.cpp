//
//  ReverseNodesInK-Group.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReverseNodesInK-Group.hpp"
#include <stack>

/**
 Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 
 k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 
 Input: head = [1,2,3,4,5], k = 2
 Output: [2,1,4,3,5]
 
 Input: head = [1,2,3,4,5], k = 3
 Output: [3,2,1,4,5]
 */

void testReverseKGroup() {
    vector<int> nums = {1,2,3,4,5};
    outputList(Solution().reverseKGroup(buildList(nums), 3));
}

ListNode* Solution::reverseKGroup(ListNode *head, int k) {
    ListNode *result = new ListNode(0);
    
    int i = 0;
    stack<ListNode *> nodeStack;
    ListNode *p = head, *q = result, *remainHead = NULL;
    while (p) {
        if (i < k) {
            nodeStack.push(p);
            i++;
        }
        if (i == k) {
            // clean stack and build reverse K list
            while (!nodeStack.empty()) {
                ListNode *newNode = new ListNode(nodeStack.top()->val);
                q->next = newNode;
                q = q->next;
                nodeStack.pop();
            }
            remainHead = p;
            i = 0;
        }

        p = p->next;
    }
    // remain number in stack
    if (!nodeStack.empty()) {
        while (remainHead->next) {
            ListNode *newNode = new ListNode(remainHead->next->val);
            q->next = newNode;
            q = q->next;
            remainHead = remainHead->next;
        }
    }
    
    return result->next;
}
