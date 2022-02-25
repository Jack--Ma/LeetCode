//
//  MergeTwoSortedLists.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/2/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MergeTwoSortedLists.hpp"

/**
 Input: list1 = [1,2,4], list2 = [1,3,4]
 Output: [1,1,2,3,4,4]
 */

// my solution
ListNode* Solution::mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode *result = new ListNode(0);
    
    ListNode *p = list1, *q = list2;
    ListNode *head = result;
    while (p != NULL && q != NULL) {
        int val1 = p->val, val2 = q->val;
        if (val1 <= val2) {
            ListNode *node = new ListNode(val1);
            head->next = node;
            head = head->next;
            p = p->next;
        } else {
            ListNode *node = new ListNode(val2);
            head->next = node;
            head = head->next;
            q = q->next;
        }
    }
    
    while (p != NULL) {
        ListNode *node = new ListNode(p->val);
        head->next = node;
        head = head->next;
        p = p->next;
    }
    
    while (q != NULL) {
        ListNode *node = new ListNode(q->val);
        head->next = node;
        head = head->next;
        q = q->next;
    }
    
    return result->next;
}

void testMergeTwoLists() {
    vector<int> list1 = {1,2,4};
    vector<int> list2 = {1,3,4};
    outputList(Solution().mergeTwoLists(buildList(list1), buildList(list2)));
}
