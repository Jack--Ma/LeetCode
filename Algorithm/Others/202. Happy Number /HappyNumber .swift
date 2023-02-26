//
//  HappyNumber .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/27.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/happy-number
 
 Write an algorithm to determine if a number n is happy.

 A happy number is a number defined by the following process:

 Starting with any positive integer, replace the number by the sum of the squares of its digits.
 Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 Those numbers for which this process ends in 1 are happy.
 Return true if n is a happy number, and false if not.
 */

extension Solution {
    // use a set stores all numbers which looped
    static var numberSet: Set<Int> = []
    
    func HappyNumber(_ n: Int) -> Bool {
//        static var numberSet: Set<Int32> = [0]
//        struct S { static var v = 0 }
//        S.v += 1
        if Solution.numberSet.contains(n) {
            Solution.numberSet = []
            return false
        }
        Solution.numberSet.insert(n)
        
        var thisN = n
        var nextN = 0
        while thisN > 0 {
            let a = thisN % 10
            nextN += Int(pow(Double(a), 2.0))
            thisN /= 10
        }
        
        if nextN == 1 {
            Solution.numberSet = []
            return true
        } else {
            return HappyNumber(nextN)
        }
    }
}
