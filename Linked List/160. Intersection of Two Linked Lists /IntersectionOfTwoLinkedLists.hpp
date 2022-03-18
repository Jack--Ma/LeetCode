//
//  IntersectionOfTwoLinkedLists.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/18.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef IntersectionOfTwoLinkedLists_hpp
#define IntersectionOfTwoLinkedLists_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/intersection-of-two-linked-lists/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
};

void testGetIntersectionNode();

#endif /* IntersectionOfTwoLinkedLists_hpp */
