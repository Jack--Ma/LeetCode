//
//  DailyTemperatures .swift
//  LeetCode-Swift
//
//  Created by jackma on 2023/5/6.
//  Copyright © 2023 JackMa. All rights reserved.
//

import Foundation

/**
 https://leetcode.com/problems/daily-temperatures
 
 Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
 */

extension Solution {
    func DailyTemperatures(_ temperatures: [Int]) -> [Int] {
        // default 0 day
        var result = Array(repeating: 0, count: temperatures.count)
        
        // Keep stack monotonically decrease, stores temperature pair
        // 0 mean temperature, 1 mean location of array
        var stack = [(Int, Int)]()
        for (i, num) in temperatures.enumerated() {
            // While stack not empty, traverse stack
            while !stack.isEmpty {
                let top = stack.last!
                if num > top.0 {
                    // current temperature beyond the top of stack
                    let day = i - top.1
                    result[top.1] = day
                    stack.removeLast()
                } else {
                    // break when temperature less
                    break
                }
            }
            // current temperature must less than the top of stack
            stack.append((num, i))
        }
        
        return result
    }
}
