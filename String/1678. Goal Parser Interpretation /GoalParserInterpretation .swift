//
//  GoalParserInterpretation .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/3/7.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/goal-parser-interpretation
 
 You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

 Given the string command, return the Goal Parser's interpretation of command.
 */

extension Solution {
    func GoalParserInterpretation(_ command: String) -> String {
        var result = ""
        
        var i = 0
        while i < command.count {
            let c = command[command.index(command.startIndex, offsetBy: i)]
            if c == "G" {
                result += "G"
                i+=1
            } else {
                if i+1 < command.count {
                    let nextC = command[command.index(command.startIndex, offsetBy: i+1)]
                    if (nextC == ")") {
                        result += "o"
                        i+=2
                    } else {
                        result += "al"
                        i+=4
                    }
                }
            }
        }
        
        return result
    }
}
