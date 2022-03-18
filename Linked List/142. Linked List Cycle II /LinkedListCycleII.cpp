//
//  LinkedListCycleII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "LinkedListCycleII.hpp"

/**
 Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
 
 Input: head = [3,2,0,-4], pos = 1
 Output: tail connects to node index 1
 Explanation: There is a cycle in the linked list, where tail connects to the second node.
 */

void testDetectCycle() {
    vector<int> nums = {3,2,0,-4};
    ListNode *head = buildList(nums);
    ListNode *p = head;
    p->next->next->next->next = head->next;
    
    outputList(Solution().detectCycle(head));
}

ListNode *Solution::detectCycle(ListNode *head) {
    ListNode *curr = head, *next = head;
    while (curr && next) {
        // no cycle
        if (!curr->next || !next->next) {
            return NULL;
        }
        // fast move two steps at one time while slow moves one step at a time.
        curr = curr->next;
        next = next->next->next;
        // find cycle and break
        if (curr == next) {
            break;
        }
    }
    // no cycle
    if (!curr || !next) {
        return NULL;
    }
    ListNode *result = head;
    // result and curr is equal, mean find the begin node of cycle
    while (result != curr) {
        result = result->next;
        curr = curr->next;
    }
    
    return result;
}
