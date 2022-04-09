//
//  RemoveNthNodeFromEndOfList.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RemoveNthNodeFromEndOfList.hpp"

/**
 Given the head of a linked list, remove the nth node from the end of the list and return its head.

 Input: head = [1,2,3,4,5], n = 2
 Output: [1,2,3,5]
 */

void testRemoveNthFromEnd() {
    vector<int> nums = {1,2,3,4,5};
    outputList(Solution().removeNthFromEnd(buildList(nums), 2));
}

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    // use a empty head
    ListNode *newHead = new ListNode();
    newHead->next = head;
    
    ListNode *slow = newHead, *fast = newHead;
    // slow and fast keep n interval
    while (n-- > 0) {
        fast = fast->next;
    }
    // find fast last node
    while (fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // remove slow->next node
    ListNode *removeNode = slow->next;
    if (removeNode) {
        slow->next = removeNode->next;
    }
    return newHead->next;
}
