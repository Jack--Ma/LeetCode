//
//  RemoveLinkedListElements.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RemoveLinkedListElements.hpp"

/**
 Input: head = [1,2,6,3,4,5,6], val = 6
 Output: [1,2,3,4,5]
 */

// my solution
ListNode* Solution::removeElements(ListNode *head, int val) {
    ListNode *result = new ListNode(0);
    
    ListNode *p = head;
    ListNode *q = result;
    while (p != NULL) {
        if (p->val != val) {
            q->next = new ListNode(p->val);
            q = q->next;
        }
        p = p->next;
    }
    return result->next;
}

// other solution
ListNode* otherRemoveElements(ListNode *head, int val) {
    if (head == NULL)
        return NULL ;
     
    head->next = otherRemoveElements(head->next , val);
    
    // find val, modify next pointer
    if (head->val == val)
        return head->next ;
    else
        return head;
}

void testRemoveElements() {
    vector<int> list = {1,2,6,3,4,5,6};
    outputList(Solution().removeElements(buildList(list), 3));
}
