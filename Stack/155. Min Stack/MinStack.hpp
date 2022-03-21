//
//  MinStack.hpp
//  LeetCode-main
//
//  Created by jackma on 2022/3/21.
//  Copyright © 2022 JackMa. All rights reserved.
//

#ifndef MinStack_hpp
#define MinStack_hpp

#include <stdio.h>
#include <stack>

// https://leetcode.com/problems/min-stack/
class MinStack {
private:
    stack<int> minStack;
    int minNum;
    
public:
    MinStack();
    
    void push(int val);
    
    void pop();
    
    int top();
    
    int getMin();
};

void testMinStack();

#endif /* MinStack_hpp */
