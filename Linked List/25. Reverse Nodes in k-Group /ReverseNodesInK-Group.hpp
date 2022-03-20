//
//  ReverseNodesInK-Group.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ReverseNodesInK_Group_hpp
#define ReverseNodesInK_Group_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/reverse-nodes-in-k-group/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k);
};

void testReverseKGroup();

#endif /* ReverseNodesInK_Group_hpp */
