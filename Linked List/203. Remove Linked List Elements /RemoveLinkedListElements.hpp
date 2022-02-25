//
//  RemoveLinkedListElements.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef RemoveLinkedListElements_hpp
#define RemoveLinkedListElements_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/remove-linked-list-elements/
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val);
};

void testRemoveElements();

#endif /* RemoveLinkedListElements_hpp */
