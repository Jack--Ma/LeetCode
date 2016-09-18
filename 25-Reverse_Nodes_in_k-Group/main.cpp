//
//  main.cpp
//  25-Reverse_Nodes_in_k-Group
//
//  Created by JackMa on 16/9/18.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

//交换范围内的k个数
ListNode *reverseList(ListNode *pre, ListNode *end) {
    ListNode *start = pre->next;
    ListNode *current = pre->next->next;
    while (current != end) {
        ListNode *next = current->next;
        current->next = pre->next;
        pre->next = current;
        current = next;
    }
    
    start->next = end;
    return start;
}

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next || k == 1) {
        return head;
    }

    ListNode *root = new ListNode(0);
    root->next = head;
    ListNode *p = root, *q = head;//p永远指向当前k范围的前一个数，q为遍历指针
    int i = 0;
    while (q) {
        i++;
        ListNode *next = q->next;
        if (i % k == 0) {
            //此时，next为下一个k范围的第一个数
            p = reverseList(p, next);
        }
        q = next;
    }
    
    return root->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3,4,5,6};
    reverseKGroup(buildList(nums), 3);
    return 0;
}
