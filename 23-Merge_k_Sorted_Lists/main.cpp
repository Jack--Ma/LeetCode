//
//  main.cpp
//  23-Merge_k_Sorted_Lists
//
//  Created by JackMa on 16/9/14.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
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

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *root = NULL;
    const int N = int(lists.size());
    
    for (int i = 0; i < N; i++) {
        root = mergeTwoLists(root, lists[i]);
    }
    
    return root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums1 = {1,3,5};
    vector<int> nums2 = {2,4,6};
    vector<int> nums3 = {7,8,9};
    vector<ListNode *> lists = {buildList(nums1), buildList(nums2), buildList(nums3)};
    mergeKLists(lists);
    
    return 0;
}
