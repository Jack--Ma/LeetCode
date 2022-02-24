//
//  main.cpp
//  21-Merge_Two_Sorted_Lists
//
//  Created by JackMa on 16/9/14.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>
#include "ListNode.h"

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *q = l1, *p = l2;
    ListNode *temp = new ListNode(0);
    ListNode *root = temp;

    //双指针遍历即可
    while (q || p) {
        if (!q) {
            temp->next = p;
            break;
        }
        if (!p) {
            temp->next = q;
            break;
        }
        if (q->val <= p->val) {
            temp->next = q;
            q = q->next;
        } else {
            temp->next = p;
            p = p->next;
        }
        temp = temp->next;
    }
    
    return root->next;
}
int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {0,5,6};
    
    mergeTwoLists(buildList(nums1), buildList(nums2));
    
    return 0;
}
