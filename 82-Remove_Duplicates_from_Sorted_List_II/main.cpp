//
//  main.cpp
//  82-Remove_Duplicates_from_Sorted_List_II
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
    //尾部添加
    ListNode *p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = new ListNode(INT_MAX/2);
    //头部添加
    ListNode *start = new ListNode(INT_MIN/2);
    start->next = head;
    //三个指针
    ListNode *left = start, *mid = left->next, *right = mid->next;
    //新的链表
    ListNode *new_root = new ListNode(0);
    ListNode *root = new_root;
    while (right) {
        //当中间的数与两边不同时，那么添加到新的链表
        if (left->val != mid->val && mid->val != right->val) {
            ListNode *node = new ListNode(mid->val);
            root->next = node;
            root = root->next;
        }
        left = left->next;
        mid = mid->next;
        right = right->next;
    }
    
    return new_root->next;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,2,3,3,3,4,5,5,6};
    deleteDuplicates(buildList(nums));
    
    return 0;
}
