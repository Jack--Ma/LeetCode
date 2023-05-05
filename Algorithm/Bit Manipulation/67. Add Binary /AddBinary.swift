//
//  AddBinary.swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/5.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/add-binary
 
 Given two binary strings a and b, return their sum as a binary string.
 */

extension Solution {
    func AddBinary(_ a: String, _ b: String) -> String {
        var result = ""
        var carryFlag = 0
        var p_a = a.count-1, p_b = b.count-1
        while p_a >= 0 || p_b >= 0 || carryFlag != 0 {
            var sum = carryFlag
            if p_a >= 0 {
                let index_a = a.index(a.startIndex, offsetBy: p_a)
                let char_a = a[index_a]
                if char_a == "1" { sum+=1 }
            }
            if p_b >= 0 {
                let index_b = b.index(b.startIndex, offsetBy: p_b)
                let char_b = b[index_b]
                if char_b == "1" { sum+=1 }
            }
            
            carryFlag = sum / 2
            result.insert(Character(String(sum%2)), at: result.startIndex)
            p_a-=1
            p_b-=1
        }
        
        return result
    }
}
