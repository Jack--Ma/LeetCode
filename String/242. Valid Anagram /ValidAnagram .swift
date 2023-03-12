//
//  ValidAnagram .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/12.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/valid-anagram
 
 Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
 */

extension Solution {
    func ValidAnagram(_ s: String, _ t: String) -> Bool {
        var sMap = Array(repeating: 0, count: 26)
        var tMap = Array(repeating: 0, count: 26)
        
        for sChar in s {
            let value = Int(sChar.asciiValue! - Character("a").asciiValue!)
            sMap[value]+=1
        }
        
        for tChar in t {
            let value = Int(tChar.asciiValue! - Character("a").asciiValue!)
            tMap[value]+=1
        }
        
        return sMap==tMap
    }
}
