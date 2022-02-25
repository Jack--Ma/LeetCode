//
//  LinkedListCycle.cpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/2/24.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include <unordered_set>
#include "LinkedListCycle.hpp"

/**
 Input: head = [3,2,0,-4], pos = 1
 Output: true
 Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
 
 Input: head = [1], pos = -1
 Output: false
 Explanation: There is no cycle in the linked list.
 */

// my solution
bool Solution::hasCycle(ListNode *head) {
    ListNode *p = head;
    unordered_set<ListNode *> addrList;
    while (p != NULL) {
        if (addrList.find(p) == addrList.end()) {
            addrList.insert(p);
        }
        if (p->next != NULL && addrList.find(p->next) != addrList.end()) {
            return true;
        }
        p = p->next;
    }
    return false;
}

// other solution
bool otherHasCycle(ListNode *head) {
    if (!head)
        return false;
    // two pointer
    ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

void testHasCycle() {
    vector<int> array = {3,2,0,-4};
    ListNode *head = buildList(array);
    ListNode *p = head;
    while (p != NULL) {
        if (p->next == NULL) {
            p->next = head;
            break;
        }
        p = p->next;
    }
    cout << Solution().hasCycle(head) << endl;
}
