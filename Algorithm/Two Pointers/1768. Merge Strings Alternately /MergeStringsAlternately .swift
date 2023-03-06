//
//  MergeStringsAlternately .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/merge-strings-alternately
 
 You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

 Return the merged string.
 
 Input: word1 = "abc", word2 = "pqr"
 Output: "apbqcr"
 Explanation: The merged string will be merged as so:
 word1:  a   b   c
 word2:    p   q   r
 merged: a p b q c r
 */

extension Solution {
    func MergeStringsAlternately(_ word1: String, _ word2: String) -> String {
        var result = ""
        
        var i = 0, j = 0
        while i < word1.count || j < word2.count {
            if (i+j)%2 == 0 {
                // must add protect
                if (i < word1.count) {
                    let index = word1.index(word1.startIndex, offsetBy: i)
                    result.append(word1[index])
                }
                i+=1
            } else {
                // must add protect
                if (j < word2.count) {
                    let index = word2.index(word2.startIndex, offsetBy: j)
                    result.append(word2[index])
                }
                j+=1
            }
        }
        
        return result
    }
}
