//
//  AddTwoNumbers.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/17.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "AddTwoNumbers.hpp"

/**
 You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

 Input: l1 = [2,4,3], l2 = [5,6,4]
 Output: [7,0,8]
 Explanation: 342 + 465 = 807.
 */

void testAddTwoNumbers() {
    vector<int> l1 = {2,4,3};
    vector<int> l2 = {5,6,4};
    outputList(Solution().addTwoNumbers(buildList(l1), buildList(l2)));
}

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *root = new ListNode();
    
    ListNode *p1 = l1, *p2 = l2;
    ListNode *q = root;
    int carryNum = 0;
    while (p1 || p2 || carryNum) {
        // build next node
        ListNode *next = new ListNode();
        carryNum += ((p1 ? p1->val : 0) + (p2 ? p2->val: 0));
        next->val = carryNum % 10;
        carryNum /= 10;
        
        q->next = next;
        q = next;
        p1 = p1 ? p1->next : p1;
        p2 = p2 ? p2->next : p2;
    }
    
    return root->next;
}
