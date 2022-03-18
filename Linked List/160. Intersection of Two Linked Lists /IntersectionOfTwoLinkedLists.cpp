//
//  IntersectionOfTwoLinkedLists.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "IntersectionOfTwoLinkedLists.hpp"
#include <unordered_set>

/**
 Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

 Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
 Output: Intersected at '8'
 
 Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 Output: Intersected at '2'
 */

void testGetIntersectionNode() {
    vector<int> nums1 = {4,1};
    vector<int> nums2 = {5,6,1};
    vector<int> intersectNums = {8,4,5};
    
    ListNode *headA = buildList(nums1);
    ListNode *headB = buildList(nums2);
    ListNode *intersectHead= buildList(intersectNums);
    headA->next->next = intersectHead;
    headB->next->next->next = intersectHead;
    
    outputList(Solution().getIntersectionNode(headA, headB));
}

// solution by use set
ListNode * _getIntersectionNode_set(ListNode *headA, ListNode *headB) {
    unordered_set<ListNode *> ASet;
    
    ListNode *a = headA;
    while (a) {
        ASet.insert(a);
        a = a->next;
    }
    
    ListNode *b = headB;
    while (b) {
        if (ASet.find(b) != ASet.end()) {
            // find first same node
            return b;
        }
        b = b->next;
    }
    
    return NULL;
}

// solution by use two pointer
ListNode *Solution::getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    
    /**
     eg. listA = [4,1,8,4,5], listB = [5,6,1,8,4,5]
     a will: 4 1 8 4 5 5 6 1 [8] 4 5
     b will: 5 6 1 8 4 5 4 1 [8] 4 5
     */
    
    int nullNum = 0;
    while (a || b) {
        // find intersection
        if (a == b) {
            return a;
        }
        // a or b extend two times, mean no intersection
        if (nullNum > 2) {
            return NULL;
        }
        a = a->next;
        b = b->next;
        
        // traverse listB after listA
        if (!a) {
            a = headB;
            nullNum++;
        }
        // traverse listA after listB
        if (!b) {
            b = headA;
            nullNum++;
        }
    }
    
    return NULL;
}
