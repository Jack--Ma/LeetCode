//
//  main.cpp
//  2-Add_Two_Numbers
//
//  Created by JackMa on 16/9/12.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *root = new ListNode(0), *head = root;
    ListNode *p = l1, *q = l2;
    int carry_num = 0;
    
    while (p != NULL || q != NULL || carry_num != 0) {
        int sum = (p == NULL ? 0 : p->val) + (q == NULL ? 0 : q->val) + carry_num;
        carry_num = sum / 10;
        head->next = new ListNode(sum % 10);
        head = head->next;
        cout << head->val;
        p = p ? p->next : NULL;
        q = q ? q->next : NULL;
    }
    
    return root->next;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> list1 = {5};
    vector<int> list2 = {5};
    addTwoNumbers(buildList(list1), buildList(list2));
    
    return 0;
}
