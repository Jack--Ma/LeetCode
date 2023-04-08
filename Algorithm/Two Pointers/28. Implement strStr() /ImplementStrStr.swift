//
//  ImplementStrStr.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/8.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
 
 Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

extension Solution {
    func ImplementStrStr(_ haystack: String, _ needle: String) -> Int {
        let L1 = haystack.count
        let L2 = needle.count
        
        var p = 0
        while p <= (L1-L2) {
            let start = haystack.index(haystack.startIndex, offsetBy: p)
            let end = haystack.index(haystack.startIndex, offsetBy: p+L2)
            let subStr = haystack[start..<end]
            if subStr == needle {
                return p
            }
            p+=1
        }
        
        return -1
    }
}
