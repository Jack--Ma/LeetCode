//
//  ReverseLinkedList.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ReverseLinkedList_hpp
#define ReverseLinkedList_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head);
};

void testReverseList();

#endif /* ReverseLinkedList_hpp */
