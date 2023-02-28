//
//  CheckIfOneStringSwapCanMakeStringsEqual .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/2/28.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal
 
 You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.

 Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
 */

extension Solution {
    func CheckIfOneStringSwapCanMakeStringsEqual(_ s1: String, _ s2: String) -> Bool {
        // record number of swap times, must be 0 or 2
        var numberOfSwap = 0;
        var s1_c1 = Character(" "), s2_c1 = Character(" ")
        for i in 0..<s1.count {
            let char_s1 = s1[s1.index(s1.startIndex, offsetBy: i)]
            let char_s2 = s2[s2.index(s2.startIndex, offsetBy: i)]
            
            if char_s1 == char_s2 {
                continue
            }
            
            numberOfSwap += 1
            if numberOfSwap == 1 {
                // record first char1 and char2 when not equal
                s1_c1 = char_s1
                s2_c1 = char_s2
            } else if numberOfSwap == 2 {
                // s1_char1 must equal to s2_char2
                if s1_c1 != char_s2 || s2_c1 != char_s1 {
                    return false
                }
            } else {
                // swap times beyond 2
                return false
            }
        }
        if numberOfSwap == 1 {
            return false
        }
        return true
    }
}
