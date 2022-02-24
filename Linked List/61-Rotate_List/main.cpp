//
//  main.cpp
//  61-Rotate_List
//
//  Created by JackMa on 16/9/19.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *root = head;
    ListNode *p = root, *q = root;
    int i = 0;
    while (i++ < k) {
        if (!q->next) {
            //当循环一次后，i为链表长度，重置q后求k和i的值，减少循环次数
            q = root;
            k = k % i;
            i = 0;
            continue;
        }
        q = q->next;
    }
    while (q->next) {
        p = p->next;
        q = q->next;
    }
    q->next = root;
    root = p->next;
    p->next = NULL;
    
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3};
    rotateRight(buildList(nums), 2000000000);
    return 0;
}
