//
//  VerifyingAnAlienDictionary .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/8.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/verifying-an-alien-dictionary/description
 
 In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.

 Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.
 
 Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
 Output: true
 Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.
 */

extension Solution {
    func VerifyingAnAlienDictionary(_ words: [String], _ order: String) -> Bool {
        // build order hash-map
        var orderMap: [Character:Int] = [:]
        for (i, char) in order.enumerated() {
            orderMap[char] = i
        }
        
        for i in 0..<words.count-1 {
            let str1 = words[i]
            let str2 = words[i+1]
            var i1 = 0, i2 = 0
            // find the fist diff char between str1 and str2
            while (i1<str1.count && i2<str2.count) {
                let i1Index = str1.index(str1.startIndex, offsetBy: i1)
                let i2Index = str2.index(str2.startIndex, offsetBy: i2)
                if str1[i1Index] == str2[i2Index] {
                    i1+=1
                    i2+=1
                } else {
                    break
                }
            }
            
            let i1Index = str1.index(str1.startIndex, offsetBy: i1)
            let i2Index = str2.index(str2.startIndex, offsetBy: i2)
            // str1 length must beyound str2 length
            if (i1 < str1.count && i2 == str2.count) {
                return false
            }
            if (i1 < str1.count && i2 < str2.count) {
                // str1[i1] must less then str2[i2]
                if (orderMap[str1[i1Index]]! > orderMap[str2[i2Index]]!) {
                    return false
                }
            }
        }
        
        return true
    }
}
