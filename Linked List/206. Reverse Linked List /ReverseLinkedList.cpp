//
//  ReverseLinkedList.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ReverseLinkedList.hpp"

/**
 Input: head = [1,2,3,4,5]
 Output: [5,4,3,2,1]
 */

/// solution by use recursion
ListNode * _reverseList_recursion(ListNode *head, ListNode *prev, ListNode *next) {
    if (!head) {
        return prev;
    }
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    return _reverseList_recursion(head, prev, next);
}

// my soluton
ListNode* Solution::reverseList(ListNode *head) {
//    ListNode *result = _reverseList_recursion(head, nullptr, head);
//    return result;
    
    ListNode *reverseHead = nullptr;
    ListNode *p = head;
    while (p != NULL) {
        ListNode *newNode = new ListNode(p->val);
        newNode->next = reverseHead;
        reverseHead = newNode;
        p = p->next;
    }
    
    return reverseHead;
}

// other solution
ListNode* otherReverseList(ListNode *head) {
    ListNode *next = head, *prev = nullptr;
    while (head != nullptr) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    
    return prev;
}

void testReverseList() {
    vector<int> list = {1,2,3,4,5};
    outputList(Solution().reverseList(buildList(list)));
}
