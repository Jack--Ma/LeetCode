//
//  main.cpp
//  86-Partition_List
//
//  Created by JackMa on 16/9/21.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

ListNode *partition(ListNode *head, int x) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *i = head;
    ListNode *dummy1 = new ListNode(0), *p = dummy1;//小于x的链表
    ListNode *dummy2 = new ListNode(0), *q = dummy2;//大于x的链表
    while (i) {
        if (i->val < x) {
            p->next = new ListNode(i->val);
            p = p->next;
        } else {
            q->next = new ListNode(i->val);
            q = q->next;
        }
        i = i->next;
    }
    p->next = dummy2->next;
    
    return dummy1->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,4,3,2,5,2};
    partition(buildList(nums), 3);
    return 0;
}
