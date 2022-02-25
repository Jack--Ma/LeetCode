//
//  MergeTwoSortedLists.hpp
//  LeetCode-main
//
//  Created by mazhaoxiang on 2022/2/25.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef MergeTwoSortedLists_hpp
#define MergeTwoSortedLists_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2);
};

void testMergeTwoLists();

#endif /* MergeTwoSortedLists_hpp */
