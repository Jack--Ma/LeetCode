//
//  ListNode.cpp
//  LeetCode
//
//  Created by JackMa on 16/9/14.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include "ListNode.h"

ListNode *buildList(vector<int> nums) {
    if (nums.size() == 0) {
        return NULL;
    }
    ListNode *root = new ListNode(nums[0]);
    ListNode *p = root;
    
    int i = 1;
    while (i < nums.size()) {
        p->next = new ListNode(nums[i]);
        p = p->next;
        i++;
    }
    
    return root;
}

void outputList(ListNode *head) {
    ListNode *p = head;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}
