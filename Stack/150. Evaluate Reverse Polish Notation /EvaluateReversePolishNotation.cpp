//
//  EvaluateReversePolishNotation.cpp
//  LeetCode-main
//
//  Created by jackma on 2022/6/5.
//  Copyright © 2022 JackMa. All rights reserved.
//

#include "EvaluateReversePolishNotation.hpp"
#include <stack>

/**
 Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 
 Valid operators are +, -, *, and /. Each operand may be an integer or another expression.
 
 Input: tokens = ["2","1","+","3","*"]
 Output: 9
 Explanation: ((2 + 1) * 3) = 9
 
 Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
 Output: 22
 Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 = ((10 * (6 / (12 * -11))) + 17) + 5
 = ((10 * (6 / -132)) + 17) + 5
 = ((10 * 0) + 17) + 5
 = (0 + 17) + 5
 = 17 + 5
 */

void testEvaluateReversePolishNotation() {
    vector<string> tokens = {"4","13","5","/","+"};
    cout << Solution().evalRPN(tokens) << endl;
}

int Solution::evalRPN(vector<string> &tokens) {
    stack<int> rpnStack;
    for (string token : tokens) {
        switch (token[token.length()-1]) {
            case '+': {
                int num1 = rpnStack.top();
                rpnStack.pop();
                int num2 = rpnStack.top();
                rpnStack.pop();
                rpnStack.push(num2+num1);
            }
                break;
            case '-': {
                int num1 = rpnStack.top();
                rpnStack.pop();
                int num2 = rpnStack.top();
                rpnStack.pop();
                rpnStack.push(num2-num1);
            }
                break;
            case '*': {
                int num1 = rpnStack.top();
                rpnStack.pop();
                int num2 = rpnStack.top();
                rpnStack.pop();
                rpnStack.push(num2*num1);
            }
                break;
            case '/': {
                int num1 = rpnStack.top();
                rpnStack.pop();
                int num2 = rpnStack.top();
                rpnStack.pop();
                rpnStack.push(num2/num1);
            }
                break;
            default: {
                int num = stoi(token);
                rpnStack.push(num);
            }
                break;
        }
    }
    
    return rpnStack.top();
}
