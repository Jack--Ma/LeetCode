//
//  ImplementQueueUsingStacks.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/2/27.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef ImplementQueueUsingStacks_hpp
#define ImplementQueueUsingStacks_hpp

#include <stdio.h>
#include <stack>

// https://leetcode.com/problems/implement-queue-using-stacks/
class MyQueue {
private:
    stack<int> myStack;
    
public:
    MyQueue();
    
    void push(int x);
    
    int pop();
    
    int peek();
    
    bool empty();
};

void testMyQueue();

#endif /* ImplementQueueUsingStacks_hpp */
