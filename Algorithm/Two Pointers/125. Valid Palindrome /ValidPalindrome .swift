//
//  ValidPalindrome .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/16.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/valid-palindrome/
 
 A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

 Given a string s, return true if it is a palindrome, or false otherwise.
 */

extension Solution {
    func ValidPalindrome(_ s: String) -> Bool {
        // must transform to Array, get char from Swift-String too slow
        let s = Array(s.lowercased())
        let length = s.count
        var i = 0, j = length-1
        while i <= j {
            if !s[i].isLetter, !s[i].isNumber {
                i+=1; continue;
            }
            if !s[j].isLetter, !s[j].isNumber {
                j-=1; continue;
            }
            guard s[i] == s[j] else {
                return false
            }
            i+=1
            j-=1
        }
        
        return true
    }
}
