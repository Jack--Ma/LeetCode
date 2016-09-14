//
//  main.cpp
//  19-Remove_Nth_Node_From_End_of_List
//
//  Created by JackMa on 16/9/14.
//  Copyright © 2016年 JackMa. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *root = head;
    ListNode *p = head, *q = head;
    //设置p, q间差距n个长度
    while (n-- > 0) {
        q = q->next;
    }
    //找到距尾部n长度的位置
    while (q && q->next) {
        q = q->next;
        p = p->next;
    }
    //删除元素
    if (q) {
        ListNode *temp = p->next;
        p->next = temp ? temp->next : NULL;
        delete temp;
    } else {
        root = root->next;
    }
    
    return root;
}

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

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {1,2,3,4,5};
    removeNthFromEnd(buildList(nums), 0);
    
    return 0;
}
