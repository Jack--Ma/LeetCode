//
//  ReorderList.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/20.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReorderList.hpp"
#include <queue>
#include <stack>

/**
 You are given the head of a singly linked-list. The list can be represented as:
 L0 → L1 → … → Ln - 1 → Ln
 
 Reorder the list to be on the following form:
 L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 
 Input: head = [1,2,3,4]
 Output: [1,4,2,3]
 
 Input: head = [1,2,3,4,5]
 Output: [1,5,2,4,3]
 */

void testReorderList() {
    vector<int> nums = {1,2,3,4};
    ListNode *head = buildList(nums);
    Solution().reorderList(head);
    outputList(head);
}

void _reorderList_stack(ListNode *head) {
    ListNode *p = head;
    stack<ListNode *> nodeStack;
    while (p) {
        nodeStack.push(p);
        p = p->next;
    }
    
    const int num = (int)nodeStack.size();
    ListNode *newHead = new ListNode(0);
    ListNode *q = head, *k = newHead;
    for (int i = 0; i < num / 2; i++) {
        // 1st add head list node
        k->next = q;
        q = q->next;
        k = k->next;
        // 2rd add stack node
        k->next = nodeStack.top();
        nodeStack.pop();
        k = k->next;
    }
    if (q == nodeStack.top()) {
        k->next = nodeStack.top();
        nodeStack.pop();
        k = k->next;
    }
    k->next = NULL;
    head = newHead->next;
}

// solution by use stack/queue
void _reorderList_stack_queue(ListNode *head) {
    ListNode *p = head;
    int num = 0;
    while (p) {
        num++;
        p = p->next;
    }
    
    stack<ListNode *> nodeStack;
    queue<ListNode *> nodeQueue;
    
    ListNode *q = head;
    for (int i = 0; i < num; i++) {
        if (i < num / 2) {
            nodeQueue.push(q);
        } else {
            nodeStack.push(q);
        }
        q = q->next;
    }
    
    ListNode *newHead = new ListNode(0);
    ListNode *k = newHead;
    while (!nodeStack.empty() && !nodeQueue.empty()) {
        k->next = nodeQueue.front();
        nodeQueue.pop();
        k = k->next;
        
        k->next = nodeStack.top();
        nodeStack.pop();
        k = k->next;
    }
    if (!nodeStack.empty()) {
        k->next = nodeStack.top();
        nodeStack.pop();
        k = k->next;
    }
    k->next = NULL;
    head = newHead->next;
}

void Solution::reorderList(ListNode *head) {
    _reorderList_stack(head);
}
