//
//  DesignLinkedList.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef DesignLinkedList_hpp
#define DesignLinkedList_hpp

#include <stdio.h>
#include "ListNode.h"

// https://leetcode.com/problems/design-linked-list/
class MyLinkedList {
private:
    ListNode *head;
    
    ListNode *getNode(int index);
    
public:
    MyLinkedList();
    
    int get(int index);
    
    void addAtHead(int val);
    
    void addAtTail(int val);
    
    void addAtIndex(int index, int val);
    
    void deleteAtIndex(int index);
};

void testMyLinkedList();

#endif /* DesignLinkedList_hpp */
