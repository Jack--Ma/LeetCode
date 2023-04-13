//
//  RepeatedSubstringPattern.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/4/12.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/repeated-substring-pattern
 
 Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.
 */

extension Solution {
    func RepeatedSubstringPattern(_ s: String) -> Bool {
        let ts = s + s
        let startIndex = ts.index(ts.startIndex, offsetBy: 1)
        let endIndex = ts.index(ts.endIndex, offsetBy: -1)
        let subS = ts[startIndex..<endIndex]
        return subS.contains(s)
    }
}
