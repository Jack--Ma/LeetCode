//
//  ToLowerCase .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/to-lower-case
 
 Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.
 
 s consists of printable ASCII characters.
 */

extension Solution {
    func ToLowerCase(_ s: String) -> String {
        var result = ""
        let aAGap = Character("a").asciiValue! - Character("A").asciiValue!
        
        for sChar in s {
            if sChar >= "A" && sChar <= "Z" {
                let lowercaseSChar = Character(UnicodeScalar(sChar.asciiValue!+aAGap))
                result += String(lowercaseSChar)
            } else {
                result += String(sChar)
            }
        }
        
        return result
    }
}
