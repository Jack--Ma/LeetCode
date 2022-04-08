//
//  MiddleOfTheLinkedList.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MiddleOfTheLinkedList.hpp"

/**
 Given the head of a singly linked list, return the middle node of the linked list.

 If there are two middle nodes, return the second middle node.
 
 Input: head = [1,2,3,4,5]
 Output: [3,4,5]
 Explanation: The middle node of the list is node 3.
 
 Input: head = [1,2,3,4,5,6]
 Output: [4,5,6]
 Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 */

void testMiddleOfTheLinkedList() {
    vector<int> nums = {1};
    outputList(Solution().middleNode(buildList(nums)));
}

ListNode* Solution::middleNode(ListNode *head) {
    ListNode *newHead = new ListNode();
    newHead->next = head;
    // two pointer
    ListNode *fast = newHead, *slow = newHead;
    
    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next ? fast->next->next : NULL;
    }
    
    return slow;
}
