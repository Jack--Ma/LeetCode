//
//  LongestCommonPrefix .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/13.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/longest-common-prefix/
 
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".
 */

extension Solution {
    // My solution
    func LongestCommonPrefix(_ strs: [String]) -> String {
        var result = ""
        if strs.count == 1 {
            return strs.first!
        }
        // find shortest sub string length
        var lcpMaxLength = LONG_MAX
        strs.forEach { str in
            lcpMaxLength = min(lcpMaxLength, str.count)
        }
        for i in 0..<lcpMaxLength {
            // traverse all strings, check whether str1 and str2 have the same characters in the same position
            var char: Character = " "
            for j in 0..<(strs.count-1) {
                let str1 = strs[j], str2 = strs[j+1]
                let index1 = str1.index(str1.startIndex, offsetBy: i)
                let index2 = str2.index(str2.startIndex, offsetBy: i)
                let char1 = str1[index1], char2 = str2[index2]
                // return when not equal
                if char1 != char2 {
                    return result
                } else {
                    char = char1
                }
            }
            result.append(String(char))
        }
        
        return result
    }
    
    // best solution
    func longestCommonPrefix(_ strs: [String]) -> String {
        guard !strs.isEmpty else { return "" }

        var pref = strs[0]

        for i in 1..<strs.count {
            let str = strs[i]

            while !str.hasPrefix(pref) {
                pref = String(pref.dropLast())
            }

            if pref.isEmpty {
                return ""
            }
        }
        return pref
    }
}
