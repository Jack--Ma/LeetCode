//
//  LengthOfLastWord.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/length-of-last-word
 
 Given a string s consisting of words and spaces, return the length of the last word in the string.

 A word is a maximal substring consisting of non-space characters only.
 */

extension Solution {
    func LengthOfLastWord(_ s: String) -> Int {
        var result = 0
        
        var findWord = false
        for (_, sChar) in s.enumerated().reversed() {
            if sChar == " " {
                if findWord {
                    break
                } else {
                    continue
                }
            } else {
                result+=1
                if !findWord {
                    findWord = true
                }
            }
        }
        
        return result
    }
}
