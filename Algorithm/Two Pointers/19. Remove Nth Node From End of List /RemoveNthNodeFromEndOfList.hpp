//
//  RemoveNthNodeFromEndOfList.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/4/8.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef RemoveNthNodeFromEndOfList_hpp
#define RemoveNthNodeFromEndOfList_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n);
};

void testRemoveNthFromEnd();

#endif /* RemoveNthNodeFromEndOfList_hpp */
