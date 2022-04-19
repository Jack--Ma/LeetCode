//
//  RemoveDuplicatesFromSortedListII.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "RemoveDuplicatesFromSortedListII.hpp"
#include <unordered_set>

/**
 Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 Input: head = [1,2,3,3,4,4,5]
 Output: [1,2,5]
 
 Input: head = [1,1,1,2,3]
 Output: [2,3]
 */

void testDeleteDuplicatesII() {
    outputList(Solution().deleteDuplicatesII(buildList({1,1,2,3,3,4,4,5})));
}

// solution by use set
ListNode *_deleteDuplicatesII_set(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    
    // find all duplicate number
    unordered_set<int> duplicateSet;
    ListNode *p = head, *q = head->next;
    while (p && q) {
        if (p->val == q->val) {
            q = q->next;
            duplicateSet.insert(p->val);
        } else {
            p = q;
            q = p->next;
        }
    }
    
    // build new list without duplicate number
    ListNode *result = new ListNode();
    p = head;
    q = result;
    while (p) {
        if (duplicateSet.find(p->val) == duplicateSet.end()) {
            q->next = new ListNode(p->val);
            q = q->next;
        }
        p = p->next;
    }
    
    return result->next;
}

/// soluton by use three pointers and no alloc new node
ListNode* _deleteDuplicatesII_two_pointer(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *newHead = new ListNode(INT_MIN);
    newHead->next = head;
    
    ListNode *slow = newHead, *mid = slow->next, *fast = mid->next;
    bool findDuplicate = false;
    while (fast) {
        if (mid->val != fast->val) {
            if (findDuplicate) {
                slow->next = fast;
                mid = slow->next;
                fast = mid->next;
                findDuplicate = false;
            } else {
                fast = fast->next;
                mid = mid->next;
                slow = slow->next;
            }
        } else {
            fast = fast->next;
            findDuplicate = true;
        }
    }
    if (findDuplicate) {
        slow->next = fast;
        mid = slow->next;
        fast = mid ? mid->next : NULL;
    }
    
    return newHead->next;
}

// solution by use three pointer
ListNode *Solution::deleteDuplicatesII(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    // add INT_MIN new start
    ListNode *newHead = new ListNode(INT_MIN);
    newHead->next = head;
    
    // add INT_MAX new end
    ListNode *p = newHead;
    while (p->next) {
        p = p->next;
    }
    p->next = new ListNode(INT_MAX);
    
    ListNode *start = newHead, *mid = start->next, *end = mid->next;
    ListNode *result = new ListNode();
    ListNode *resultHead = result;
    while (end) {
        // when start!=mid!=end, that mean mid value is unique
        if (start->val != mid->val && mid->val != end->val) {
            resultHead->next = new ListNode(mid->val);
            resultHead = resultHead->next;
        }
        start = start->next;
        mid = mid->next;
        end = end->next;
    }
    
    return result->next;
}
