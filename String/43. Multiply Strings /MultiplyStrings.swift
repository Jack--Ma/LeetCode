//
//  MultiplyStrings.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/20.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/multiply-strings
 
 Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

 Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

extension Solution {
    func MultiplyStrings(_ num1: String, _ num2: String) -> String {
        let zeroValue = Character("0").asciiValue!
        let size1 = num1.count, size2 = num2.count
        let array1 = Array(num1), array2 = Array(num2)
        
        var result = Array(repeating: 0, count: size1 + size2)
        // traverse from back to front
        for (i2, n2) in array2.enumerated().reversed() {
            var carryNum = 0
            for (i1, n1) in array1.enumerated().reversed() {
                // index from 0 to size1+size2-2
                let resultIndex = size1-i1-1+size2-i2-1
                let resultNum = result[resultIndex]
                // calculate n1 * n2
                carryNum += Int((n2.asciiValue!-zeroValue) * (n1.asciiValue!-zeroValue)) + resultNum
                // set number in result
                result[resultIndex] = carryNum % 10
                carryNum /= 10
            }
            // the last carry number
            result[size1+size2-i2-1] = carryNum
        }
        // remove unused zero
        var numOfZero = 0
        for num in result.reversed() {
            if num == 0 {
                numOfZero+=1
            } else {
                break
            }
        }
        result.removeLast(numOfZero)
        var resultStr = ""
        result.reversed().forEach { num in
            resultStr += String(num)
        }
        return resultStr.isEmpty ? "0" : resultStr
    }
}
