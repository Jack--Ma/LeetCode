//
//  MinStack.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/21.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "MinStack.hpp"

/**
 Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 */

void testMinStack() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
}

/// initializes the stack object.
MinStack::MinStack() {
    minStack = stack<int>();
    minNum = INT_MAX;
}

/// pushes the element val onto the stack.
void MinStack::push(int val) {
    // if val is smaller, first push the last smaller number
    if (val <= minNum) {
        minStack.push(minNum);
        minNum = val;
    }
    // second push this value
    minStack.push(val);
}

/// removes the element on the top of the stack.
void MinStack::pop() {
    // first pop the top value
    int top = minStack.top();
    minStack.pop();
    // second pop the last smaller number when current pop number is the minNum
    if (top == minNum) {
        minNum = minStack.top();
        minStack.pop();
    }
}

/// gets the top element of the stack.
int MinStack::top() {
    return minStack.top();
}

/// retrieves the minimum element in the stack.
int MinStack::getMin() {
    return minNum;
}
