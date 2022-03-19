//
//  DesignLinkedList.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/19.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "DesignLinkedList.hpp"

/**
 Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
 A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
 */

void testMyLinkedList() {
    MyLinkedList myLinkedList = MyLinkedList();
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
    myLinkedList.get(1);              // return 2
    myLinkedList.deleteAtIndex(0);    // now the linked list is 1->3
    myLinkedList.get(0);              // return 3
}

/// Initializes the MyLinkedList object.
MyLinkedList::MyLinkedList() {
    head = NULL;
}

/// Get the value of the indexth node in the linked list. If the index is invalid, return -1.
int MyLinkedList::get(int index) {
    ListNode *node = getNode(index);
    return node ? node->val : -1;
}

/// Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void MyLinkedList::addAtHead(int val) {
    ListNode *newHead = new ListNode(val, head);
    head = newHead;
}

/// Append a node of value val as the last element of the linked list.
void MyLinkedList::addAtTail(int val) {
    if (!head) {
        addAtHead(val);
        return;
    }
    // find tail node p
    ListNode *p = head;
    while (p->next) {
        p = p->next;
    }
    p->next = new ListNode(val);
}

/// Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void MyLinkedList::addAtIndex(int index, int val) {
    if (index < 0) {
        return;
    } else if (index == 0) {
        addAtHead(val);
        return;
    }
    // find the index node's last node
    ListNode *node = getNode(index - 1);
    if (!node) {
        return;
    }
    ListNode *newNode = new ListNode(val);
    newNode->next = node->next;
    node->next = newNode;
}

/// Delete the indexth node in the linked list, if the index is valid.
void MyLinkedList::deleteAtIndex(int index) {
    if (index < 0) {
        return;
    } else if (index == 0) {
        head = head ? head->next : NULL;
        return;
    }
    // find the index node's last node
    ListNode *node = getNode(index - 1);
    // index node is beyond of list tail
    if (!node || !node->next) {
        return;
    }
    node->next = node->next->next;
}

ListNode* MyLinkedList::getNode(int index) {
    if (!head) {
        return NULL;
    }
    ListNode *p = head;
    for (int i = 0; i < index; i++) {
        if (!p) {
            return NULL;
        }
        p = p->next;
    }
    
    return p;
}
