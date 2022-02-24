//
//  main.cpp
//  24-Swap_Nodes_in_Pairs
//
//  Created by JackMa on 16/9/16.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include "ListNode.h"

using namespace std;

ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode *root = head->next;
    ListNode *p = head, *q = head->next;
    while (p && q) {
        p->next = q->next;
        q->next = p;
        ListNode *temp = p->next;
        if (!temp || !temp->next) {
            break;
        }
        p->next = temp->next;
        p = temp;
        q = temp->next;
    }
    
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {};
    swapPairs(buildList(nums));
    return 0;
}
