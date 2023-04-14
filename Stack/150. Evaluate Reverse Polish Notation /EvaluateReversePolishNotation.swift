//
//  EvaluateReversePolishNotation.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/14.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/evaluate-reverse-polish-notation
 
 You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

 Evaluate the expression. Return an integer that represents the value of the expression.

 Note that:

 The valid operators are '+', '-', '*', and '/'.
 Each operand may be an integer or another expression.
 The division between two integers always truncates toward zero.
 There will not be any division by zero.
 The input represents a valid arithmetic expression in a reverse polish notation.
 The answer and all the intermediate calculations can be represented in a 32-bit integer.
 */

extension Solution {
    func EvaluateReversePolishNotation(_ tokens: [String]) -> Int {
        var stack = Array<Int>()
        
        for token in tokens {
            switch token.last {
            case "+": do {
                let num1 = stack.last!
                stack.removeLast()
                let num2 = stack.last!
                stack.removeLast()
                stack.append(num1+num2)
            }
                break
            case "-": do {
                let num1 = stack.last!
                stack.removeLast()
                let num2 = stack.last!
                stack.removeLast()
                stack.append(num2-num1)
            }
                break
            case "*": do {
                let num1 = stack.last!
                stack.removeLast()
                let num2 = stack.last!
                stack.removeLast()
                stack.append(num2*num1)
            }
                break
            case "/": do {
                let num1 = stack.last!
                stack.removeLast()
                let num2 = stack.last!
                stack.removeLast()
                stack.append(num2/num1)
            }
                break
            default:
                let num = Int(token)!
                stack.append(num)
            }
        }
        
        return stack.last!
    }
}
