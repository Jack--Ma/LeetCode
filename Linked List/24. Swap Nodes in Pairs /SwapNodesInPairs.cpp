//
//  SwapNodesInPairs.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "SwapNodesInPairs.hpp"

/**
 Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 Input: head = [1,2,3,4]
 Output: [2,1,4,3]
 */

void testSwapPairs() {
    outputList(Solution().swapPairs(buildList({1,2,3})));
}

ListNode* Solution::swapPairs(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *fast = head->next, *slow = head;
    
    ListNode *result = new ListNode(0);
    ListNode *p = result;
    while (slow) {
        if (fast) {
            p->next = new ListNode(fast->val);
            p = p->next;
            fast = fast->next ? fast->next->next : NULL;
        }
        p->next = new ListNode(slow->val);
        p = p->next;
        slow = slow->next ? slow->next->next : NULL;
    }
    
    return result->next;
}
