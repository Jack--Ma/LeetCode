//
//  RemoveDuplicatesFromSortedList.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RemoveDuplicatesFromSortedList.hpp"

/**
 Input: head = [1,1,2,3,3]
 Output: [1,2,3]
 */

// my solution
ListNode* Solution::deleteDuplicates(ListNode *head) {
    if (head == nullptr) {
        return head;
    }
    // 2 pointer loop, p point to the no duplicate position
    ListNode *p = head, *next = p->next;
    while (next != nullptr) {
        if (p->val != next->val) {
            p->next = next;
            p = next;
        }
        next = next->next;
    }
    // incase [1,1], set p->next nullptr
    p->next = nullptr;
    return head;
}

// other solution
ListNode* otherDeleteDuplicates(ListNode *head) {
    if (head == NULL || head->next == NULL)
        return head;
    head->next = otherDeleteDuplicates(head->next);
    return head->val==head->next->val ? head->next : head;
}

void testDeleteDuplicates() {
    vector<int> list = {};
    outputList(Solution().deleteDuplicates(buildList(list)));
}
