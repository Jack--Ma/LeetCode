//
//  DecryptStringFromAlphabetToIntegerMapping .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping
 
 You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
    Characters ('a' to 'i') are represented by ('1' to '9') respectively.
    Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
 Return the string formed after mapping.

 The test cases are generated so that a unique mapping will always exist.
 */

extension Solution {
    func DecryptStringFromAlphabetToIntegerMapping(_ s: String) -> String {
        var result = ""
        let length = s.count
        
        var i = length-1
        while i >= 0 {
            let sChar = s[s.index(s.startIndex, offsetBy: i)]
            var sSubstring = ""
            if sChar == "#" {
                // find the substring with range[i-2,i-1]
                let start = s.index(s.startIndex, offsetBy: i-2)
                let end = s.index(s.startIndex, offsetBy: i)
                let range = start..<end
                sSubstring = String(s[range])
                i-=3
            } else {
                // number 1~9，transform to a~i
                sSubstring = String(sChar)
                i-=1
            }
            let sSubstringValue = Int(sSubstring)!
            let newCharValue = Int(Character("a").asciiValue!)-1+sSubstringValue
            let newChar = Character(UnicodeScalar(newCharValue)!)
            result.insert(newChar, at: result.startIndex)
        }
        
        return result
    }
}
