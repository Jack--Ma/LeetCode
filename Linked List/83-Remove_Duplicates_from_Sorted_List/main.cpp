//
//  main.cpp
//  83-Remove_Duplicates_from_Sorted_List
//
//  Created by JackMa on 16/9/19.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = head, *q = head->next;//两个指针遍历链表
    while (q) {
        //相邻元素相同，那么跳过
        if (p->val == q->val) {
            q = q->next;
            p->next = q;
            continue;
        }
        p = p->next;
        q = q->next;
    }
    
    return dummy->next;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,2,3,3,3,4,5,5,6};
    deleteDuplicates(buildList(nums));
    
    return 0;
}
