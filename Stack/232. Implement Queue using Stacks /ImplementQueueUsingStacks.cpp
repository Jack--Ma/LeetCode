//
//  ImplementQueueUsingStacks.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "ImplementQueueUsingStacks.hpp"

/**
 Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).
 
 Input
 ["MyQueue", "push", "push", "peek", "pop", "empty"]
 [[], [1], [2], [], [], []]
 Output
 [null, null, null, 1, 1, false]
 */

// my solution
MyQueue::MyQueue() {
    myStack = stack<int>();
}

void MyQueue::push(int x) {
    stack<int> tempStack;
    while (myStack.size() != 0) {
        tempStack.push(myStack.top());
        myStack.pop();
    }
    
    myStack.push(x);
    while (tempStack.size() != 0) {
        myStack.push(tempStack.top());
        tempStack.pop();
    }
}

int MyQueue::pop() {
    int pop = myStack.top();
    myStack.pop();
    return pop;
}

int MyQueue::peek() {
    return myStack.top();
}

bool MyQueue::empty() {
    return myStack.empty();
}

void testMyQueue() {
    MyQueue queue = MyQueue();
    queue.push(1);
    queue.push(2);
    cout << queue.peek() << " ";
    cout << queue.pop() << " ";
    cout << queue.empty() << endl;
}
