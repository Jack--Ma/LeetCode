//
//  RemoveDuplicatesFromSortedList.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/26.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef RemoveDuplicatesFromSortedList_hpp
#define RemoveDuplicatesFromSortedList_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head);
};

void testDeleteDuplicates();

#endif /* RemoveDuplicatesFromSortedList_hpp */
